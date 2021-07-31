#include <OneWire.h>
#include <DallasTemperature.h>
#include<LiquidCrystal.h>
int RS=A0;
int EN=A1;
int D4=13;
int D5=12;
int D6=11;
int D7=10;

LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
#define ONE_WIRE_BUS 4

OneWire oneWire(ONE_WIRE_BUS);
DallasTemperature sensors(&oneWire);

void setup(void)
{
  Serial.begin(9600);
  sensors.begin();
  lcd.begin(16,2);
}

void loop(void)
{ 
  sensors.requestTemperatures(); 
  
  Serial.print("Celsius temperature: ");
  Serial.print(sensors.getTempCByIndex(0)); 
  lcd.setCursor(0,0);
  lcd.print("Celsius");
  lcd.print(sensors.getTempCByIndex(0));
  Serial.print(" - Fahrenheit temperature: ");
  Serial.println(sensors.getTempFByIndex(0));
  lcd.setCursor(0,1);
  lcd.print("Fahrenheit");
  lcd.print(sensors.getTempFByIndex(0));

  if(sensors.getTempCByIndex(0)>50)
  {
    Serial.println("High Temperature");
  }
  Serial.println();

  delay(1000);
}
