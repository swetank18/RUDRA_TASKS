
const int pwm1 = 9;   
const int pwm2 = 10;  

void setup() {
  pinMode(pwm1, OUTPUT);
  pinMode(pwm2, OUTPUT);
  Serial.begin(9600);
  Serial.println("Sabertooth Analog Control Initialized");
  delay(1000);
}

void loop() {
  // ======= FORWARD MOTION =======
  Serial.println("Moving Forward...");
  for (int i = 127; i <= 255; i++) 
    analogWrite(pwm1, i);
    analogWrite(pwm2, i);
    delay(10);
  }

  delay(1000);

  // ======= STOP =======
  Serial.println("Stopping...");
  analogWrite(pwm1, 127);   
  analogWrite(pwm2, 127);
  delay(1500);

  // ======= REVERSE MOTION =======
  Serial.println("Moving Backward...");
  for (int i = 127; i >= 0; i--) {  
    analogWrite(pwm1, i);
    analogWrite(pwm2, i);
    delay(10);
  }

  delay(1000);

  // ======= STOP AGAIN =======
  Serial.println("Stopped.");
  analogWrite(pwm1, 127);
  analogWrite(pwm2, 127);
  delay(2000);
}
