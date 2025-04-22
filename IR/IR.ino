int IR_PIN=2;
int value=0;
void setup() {
  // put your setup code here, to run once:
   Serial.begin(9600);
   pinMode(IR_PIN,INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
    value=digitalRead(IR_PIN);
    Serial.print("value: ");
    Serial.println(value);
    if(!value)
    {
      Serial.println("object detected");
    }
    else
    {
      Serial.println("no object");
    }
    
    delay(500);
}
