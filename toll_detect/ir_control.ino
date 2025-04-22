

void ir_init(int IR_PIN) 
{
  //IR pin setup
  pinMode(IR_PIN,INPUT);
}

int ir_read(int IR_PIN)
{
  return digitalRead(IR_PIN);
}
