int count=0;
const int PUSH_BUTTON_PIN=3;
bool BUTTON_STATUS=HIGH;

void setup() 
{
  Serial.begin(9600);
  pinMode(PUSH_BUTTON_PIN,INPUT_PULLUP);  
    
}

void loop() {
  // put your main code here, to run repeatedly:
  BUTTON_STATUS=digitalRead(PUSH_BUTTON_PIN);
  
  if(!BUTTON_STATUS)
  {
    count++;
   Serial.print("button pressed ");
   Serial.print(count);
   Serial.println("th time");
   delay(200);
   Serial.println("Button released");
  }
 
}
