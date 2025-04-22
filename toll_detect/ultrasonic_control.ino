


void ultrasonic_init(int Trig,int echo)
{
   //pin setup for ultrasonic sensor
  pinMode(Trig,OUTPUT);
  pinMode(echo,INPUT);
}

void ultrasonic_write_to_Trigger(int Trig)
{
      digitalWrite(Trig,LOW);
      delay(100);
      digitalWrite(Trig,HIGH);
      delay(30);
      digitalWrite(Trig,LOW);
}

int ultrasonic_read_to_Echo(int echopin)
{
  return pulseIn(echopin,HIGH);  //return time duration of a pulse
}

int ultrasonic_distance(int echopin)
{
  return (ultrasonic_read_to_Echo(echopin)*0.034)/2;  //returns distance in cm
}
