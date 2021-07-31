//#include "DHT.h"
#include<LiquidCrystal.h>
#include <DHT.h>
//#include <DHT_U.h>
#include <Adafruit_Sensor.h>
//#include "DHT.h"

#define DHTPIN 2
#define DHTTYPE DHT11
DHT dht(DHTPIN, DHTTYPE);
int RS=A0;
int EN=A1;
int D4=13;
int D5=12;
int D6=11;
int D7=10;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
//DHT dht;

void setup()
{
  Serial.begin(9600);
  Serial.println();
  Serial.println("Status:\tHumidity (%)\tTemperature (C)\t(F)");
  lcd.begin(16,2);
  //dht.setup(2);   /* set pin for data communication */
  dht.begin();
}

void loop()
{
//  delay(dht.getMinimumSamplingPeriod());  /* Delay of amount equal to sampling period */  
//
//  float humidity = dht.getHumidity();     /* Get humidity value */
//  float temperature = dht.getTemperature(); /* Get temperature value */

  float humidity = dht.readHumidity();
  // Read temperature as Celsius (the default)
  float temperature = dht.readTemperature();

  Serial.print("\t");
  Serial.print(humidity, 1);
  lcd.setCursor(0,0);
  lcd.print("Humidity=");
  lcd.print(humidity);
  Serial.print("\t\t");
  Serial.print(temperature, 1);
  lcd.setCursor(0,1);
  lcd.print("Temp=");
  lcd.print(temperature);
  Serial.print("\t\t");
  
 // Serial.println(dht.toFahrenheit(temperature), 1); /* Convert temperature to Fahrenheit units */
  if(temperature>29)
  {
    Serial.println("High Temperature");
  }
  
  Serial.println();
  
  if(humidity>90)
  {
    Serial.print("High Humidity");
  }
  Serial.println();
  delay(2000);
}
