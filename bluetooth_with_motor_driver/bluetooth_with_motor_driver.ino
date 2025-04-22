
#include"defines.h"
#include"motor_driver_control.h"



char command_from_serial;

void setup() {
  
  Serial.begin(9600);   //Sets the baud for serial data transmission
  // Set all the motor control pins to outputs
  pinMode(ENABLE_A, OUTPUT);
  pinMode(ENABLE_B, OUTPUT);
  pinMode(INPUT1, OUTPUT);
  pinMode(INPUT2, OUTPUT);
  pinMode(INPUT3, OUTPUT);
  pinMode(INPUT4, OUTPUT);
  
  // Turn off motors - Initial state
  digitalWrite(INPUT1, LOW);
  digitalWrite(INPUT2, LOW);
  digitalWrite(INPUT3, LOW);
  digitalWrite(INPUT4, LOW);
}

void loop() {

   if(Serial.available() > 0)      //  Send data only when you receive data:
   {
      command_from_serial = Serial.read();        //Read  the incoming data & store into data
      Serial.print(command_from_serial);          //Print  Value inside data in Serial monitor
      Serial.print("\");        
   }

   
   switch(command_from_serial)
   {
     case '1':go_forward();
              break;
     case '2':go_backward();
              break;
     case '3':turn_right();break;
     case '4':turn_left();break;
   }

   delay(100);
  
}

/*

// This function lets you control spinning direction of motors
void directionControl() {
  // Set motors to maximum speed
  // For PWM maximum possible values are 0 to 255
  analogWrite(enA, 255);
  analogWrite(enB, 255);

  // Turn on motor A & B
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  digitalWrite(in3, HIGH);
  digitalWrite(in4, LOW);
  delay(2000);
  
  // Now change motor directions
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  delay(2000);
  
  // Turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}

// This function lets you control speed of the motors
void speedControl() {
  // Turn on motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  digitalWrite(in3, LOW);
  digitalWrite(in4, HIGH);
  
  // Accelerate from zero to maximum speed
  for (int i = 0; i < 256; i++) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  
  // Decelerate from maximum speed to zero
  for (int i = 255; i >= 0; --i) {
    analogWrite(enA, i);
    analogWrite(enB, i);
    delay(20);
  }
  
  // Now turn off motors
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  digitalWrite(in3, LOW);
  digitalWrite(in4, LOW);
}
*/
