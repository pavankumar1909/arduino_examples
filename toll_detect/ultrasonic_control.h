#ifndef __ULTRASONIC_CONTROL_H__
#define __ULTRASONIC_CONTROL_H__

void ultrasonic_init(int,int);
void ultrasonic_write_to_Trigger(int);
int ultrasonic_read_to_Echo(int);
int ultrasonic_distance(int);

#endif  //__ULTRASONIC_CONTROL_H__
