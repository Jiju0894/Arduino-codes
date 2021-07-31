
int led = 9;    // LED connected to digital pin 9
int i;
void setup() {
  pinMode(led,OUTPUT);
}

void loop() 
{
  for (i = 0 ; i<= 255; i++)
  {
    analogWrite(led,i);
    delay(30);
  }
  for (i= 100 ; i >= 0; i--)
  {
    analogWrite(led, i);
    delay(30);
  }
}


