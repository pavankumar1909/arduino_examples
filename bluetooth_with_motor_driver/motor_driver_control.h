#ifndef __MOTOR_DRIVER_CONTROL_H__
#define __MOTOR_DRIVER_CONTROL_H__

void go_forward();
void go_backward();
void turn_right();
void turn_left();
void stop_all_motors();
void set_motor_speed();
void accelerate_low_to_high_speed();
void decelerate_high_to_speed();

#endif //__MOTOR_DRIVER_CONTROL_H__
