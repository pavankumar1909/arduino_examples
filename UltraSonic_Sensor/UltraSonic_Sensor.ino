long duration=0;
int distance=0;
int triggerPin=2;
int echopin=4;
void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(triggerPin,OUTPUT);
  pinMode(echopin,INPUT);

}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(triggerPin,LOW);
  delay(100);


  digitalWrite(triggerPin,HIGH);
  delay(30);
  digitalWrite(triggerPin,LOW);

  duration=pulseIn(echopin,HIGH);
  distance= ( duration*0.034)/2;
  Serial.print("distance:");
  Serial.println(distance);
 

}
