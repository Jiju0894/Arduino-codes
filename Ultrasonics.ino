#include<LiquidCrystal.h>
int RS=12;
int EN=11;
int D4=8;
int D5=7;
int D6=6;
int D7=5;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
int trigr=2;
int echo=3;
long duration=0;
int distance=0;

void setup()
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(trigr,OUTPUT);
  pinMode(echo,INPUT);
}

void loop()
{
  lcd.clear();
  digitalWrite(trigr,LOW);
  delayMicroseconds(2);
  
  digitalWrite(trigr,HIGH);
  delayMicroseconds(10);
  digitalWrite(trigr,LOW);
  
  duration=pulseIn(echo,HIGH);
  distance=(duration*0.034)/2;
  Serial.print("Distance= ");
  Serial.println(distance);
  lcd.setCursor(0,0);
  lcd.print("Distnz=");
  lcd.print(distance);
  delay(1000);
}
