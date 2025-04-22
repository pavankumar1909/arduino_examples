#include"ir_control.h"
#include"ultrasonic_control.h"

//for ir
int IR_PIN=8;
int value=0;

//for ultrasonic sensor
long duration=0;
int distance=0;
int triggerPin=10;
int echopin=11;

void setup() {
  
  Serial.begin(9600);
  //initialise Ultrasonic pins
  //(Trigger pin,echopin)
  ultrasonic_init(triggerPin,echopin);
  //initialise IR pins
  ir_init(IR_PIN);

}

void loop() {

     value=ir_read(IR_PIN);
     //    Serial.print("value: ");
     //    Serial.println(value);
    if(!value)
    {
      Serial.print("object detected at ");
      ultrasonic_write_to_Trigger(triggerPin);
      distance= ultrasonic_distance(echopin);
      Serial.print("distance: ");
      Serial.print(distance);
      Serial.println("cm");

    }
    else
    {
      Serial.println("no object");
    }
    
    delay(100);
  // put your main code here, to run repeatedly:
  
}
