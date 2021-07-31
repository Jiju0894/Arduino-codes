#include<LiquidCrystal.h>
int RS=12;
int EN=11;
int D0=6;
int D1=5;
int D2=4;
int D3=3;
LiquidCrystal lcd(12,11,6,5,4,3);
int xin=A0;
int yin=A1;
int zin=A2;
int i,j,k;

void setup() 
{
 Serial.begin(9600);
 lcd.begin(16,2);
 pinMode(xin,INPUT);
 pinMode(yin,INPUT);
 pinMode(zin,INPUT);
}

void loop()
{
  lcd.clear();
  i=analogRead(xin);
  Serial.print(i);
  Serial.print("\t");
  j=analogRead(yin);
  Serial.print(j);
  Serial.print("\t");
  k=analogRead(zin);
  Serial.print(k);
  Serial.println();
  delay(1000);

//  if((i>350)||(i<335)||(j>340)||(j<330))
//  {
//    lcd.setCursor(0,1);
//    lcd.print("Accident Detected");
//    Serial.println("Accident Detected");
//  }
//  else
//  {
//    lcd.setCursor(0,1);
//    lcd.print("No Accident");
//    Serial.println("No Detected");
//  }
//  delay(1000); 
}
