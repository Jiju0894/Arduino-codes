#include<LiquidCrystal.h>
int RS=12;
int EN=11;
int D0=6;
int D1=5;
int D2=4;
int D3=3;
LiquidCrystal lcd(12,11,6,5,4,3);

String inputString = "";         // a string to hold incoming data
boolean stringComplete = false;  // whether the string is complete

void setup() {
  // initialize serial:
  Serial.begin(9600);
 lcd.begin(16,2);
}

void loop() {
  // print the string when a newline arrives:
  if (stringComplete)
  {
    Serial.println(inputString);
    lcd.setCursor(0,0);
    lcd.print(inputString);
    // clear the string:
    inputString = "";
    stringComplete = false;
  }
}

void serialEvent() {
  while (Serial.available())
  {
    // get the new byte:
    char inChar = (char)Serial.read();
    // if the incoming character is a newline, set a flag
    // so the main loop can do something about it:
    if (inChar == '\n')
    {
      stringComplete = true;
    }
    else
    {
      // add it to the inputString:
    inputString += inChar;
    }
  }
}


