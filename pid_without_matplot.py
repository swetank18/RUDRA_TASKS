import math
import time


def wrap_to_pi(x):
    while x <= -math.pi:
        x += 2 * math.pi
    while x > math.pi:
        x -= 2 * math.pi
    return x


class PID:
    def __init__(self, Kp, Ki, Kd, dt):
        self.Kp = Kp
        self.Ki = Ki
        self.Kd = Kd
        self.dt = dt
        self.integral = 0
        self.prev_error = 0

    def compute(self, target, current):
        error = wrap_to_pi(target - current)
        self.integral += error * self.dt
        derivative = (error - self.prev_error) / self.dt
        output = self.Kp * error + self.Ki * self.integral + self.Kd * derivative
        self.prev_error = error
        return output, error


dt = 0.05               
pid = PID(Kp=2.0, Ki=0.4, Kd=0.06, dt=dt)

target_angle = math.radians(170)   
current_angle = math.radians(-170) 

print("Starting PID simulation...\n")
for i in range(1, 100):
    control_output, error = pid.compute(target_angle, current_angle)
    delta_angle = control_output * dt       
    current_angle += delta_angle

    print(f"Iter {i:02d}: angle = {math.degrees(current_angle):8.3f}°, "
          f"error = {math.degrees(error):7.3f}°, moved = {math.degrees(delta_angle):6.3f}°")

    if abs(error) < math.radians(0.5):
        print("\n✅ Target angle reached!")
        break

    time.sleep(dt)

