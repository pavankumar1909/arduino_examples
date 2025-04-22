#include"defines.h"
#include"motor_driver_control.h"

void go_forward()
{
  set_motors_speed(HIGH_SPEED);
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
}
void go_backward()
{
  set_motors_speed(HIGH_SPEED);
  digitalWrite(INPUT1, LOW);
  digitalWrite(INPUT2, HIGH);
  digitalWrite(INPUT3, LOW);
  digitalWrite(INPUT4, HIGH);
  delay(2000);
}

void turn_right()
{
  set_motors_speed(HIGH_SPEED);
  // Now change motor directions
  digitalWrite(INPUT1, HIGH);
  digitalWrite(INPUT2, HIGH);
  digitalWrite(INPUT3, LOW);
  digitalWrite(INPUT4, LOW);
  delay(2000);
}

void turn_left()
{
  set_motors_speed(HIGH_SPEED);
  // Now change motor directions
  digitalWrite(INPUT1, LOW);
  digitalWrite(INPUT2, LOW);
  digitalWrite(INPUT3, HIGH);
  digitalWrite(INPUT4, HIGH);
  delay(2000);
}

void stop_all_motors()
{
  // Turn off motors
  digitalWrite(INPUT1, LOW);
  digitalWrite(INPUT2, LOW);
  digitalWrite(INPUT3, LOW);
  digitalWrite(INPUT4, LOW);
}

void accelerate_to_high_speed()
{
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(ENABLE_A, i);
    analogWrite(ENABLE_B, i);
    delay(20);
  }
}

void decelerate_high_to_low_speed()
{
 // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(ENABLE_A, i);
    analogWrite(ENABLE_B, i);
    delay(20);
  }
}

void set_motors_speed(int speed)
{
  // For PWM maximum possible values are 0 to 255
  analogWrite(ENABLE_A, speed);
  analogWrite(ENABLE_B, speed);
}
