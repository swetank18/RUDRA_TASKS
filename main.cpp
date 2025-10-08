#include <opencv2/opencv.hpp>
#include <iostream>
using namespace cv;
using namespace std;

int main() {
    // Read input image
    Mat img = imread("circles.jpg", IMREAD_COLOR);
    if(img.empty()) {
        cout << "Error: Image not found!" << endl;
        return -1;
    }

    Mat gray;
    cvtColor(img, gray, COLOR_BGR2GRAY);
    GaussianBlur(gray, gray, Size(9, 9), 2);

    // Detect circles
    vector<Vec3f> circles;
    HoughCircles(gray, circles, HOUGH_GRADIENT, 1, gray.rows/16, 100, 30, 1, 100);

    // Draw circles
    for(size_t i = 0; i < circles.size(); i++) {
        Point center(cvRound(circles[i][0]), cvRound(circles[i][1]));
        int radius = cvRound(circles[i][2]);
        circle(img, center, 3, Scalar(0,255,0), -1);  // center
        circle(img, center, radius, Scalar(0,0,255), 2); // outline
    }

    imshow("Detected Circles", img);
    waitKey(0);
    return 0;
}

