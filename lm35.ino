#include<LiquidCrystal.h>
int RS=12;
int EN=11;
int D0=6;
int D1=5;
int D2=4;
int D3=3;
LiquidCrystal lcd(12,11,6,5,4,3);
int sensor=A0;
float vout;
float tempC;

void setup() 
{
  Serial.begin(9600);
  lcd.begin(16,2);
  pinMode(sensor,INPUT);
}

void loop() 
{
vout=analogRead(sensor);
vout=(vout*500)/1023;
tempC=vout;
lcd.clear();
lcd.print(vout);
  if(tempC>50)
  {
    lcd.setCursor(0,1);
    lcd.print("High Temperature");
  }
  else
  {
    lcd.setCursor(0,1);
    lcd.print("Normal Temperature");
  }
delay(500);
}
