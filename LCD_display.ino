#include <LiquidCrystal.h>

//#include<LiquidCrystal.h>


LiquidCrystal lcd(12,11,7,6,5,4);

void setup()
{
 lcd.begin(16,2);

}

void loop() 
{
 lcd.setCursor(0,0);
   lcd.print("HELLO WORLD");

 lcd.setCursor(0,1);
 lcd.print("HAPPY NEW YEAR");
 delay(1000);
 lcd.clear();
 delay(1000);
 
}
