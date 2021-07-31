
#define USE_ARDUINO_INTERRUPTS true    // Set-up low-level interrupts for most acurate BPM math.
#include <PulseSensorPlayground.h>     // Includes the PulseSensorPlayground Library.   
#include<LiquidCrystal.h>
int RS=A0;
int EN=A1;
int D4=13;
int D5=12;
int D6=11;
int D7=10;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);

//  Variables
const int PulseWire = A3;       // PulseSensor PURPLE WIRE connected to ANALOG PIN 0
const int LED13 = 13;          // The on-board Arduino LED, close to PIN 13.
int Threshold = 550;           // Determine which Signal to "count as a beat" and which to ignore.
                               // Use the "Gettting Started Project" to fine-tune Threshold Value beyond default setting.
                               // Otherwise leave the default "550" value. 
                               
PulseSensorPlayground pulseSensor;  // Creates an instance of the PulseSensorPlayground object called "pulseSensor"


void setup() 
{   

  Serial.begin(9600);          // For Serial Monitor
  lcd.begin(16,2);
  // Configure the PulseSensor object, by assigning our variables to it. 
  pulseSensor.analogInput(PulseWire);   
  pulseSensor.blinkOnPulse(LED13);       //auto-magically blink Arduino's LED with heartbeat.
  pulseSensor.setThreshold(Threshold);   

  // Double-check the "pulseSensor" object was created and "began" seeing a signal. 
   if (pulseSensor.begin()) {
    Serial.println("We created a pulseSensor Object !");  //This prints one time at Arduino power-up,  or on Arduino reset.  
  }
}



void loop()
{

 int myBPM = pulseSensor.getBeatsPerMinute();  // Calls function on our pulseSensor object that returns BPM as an "int".
                                               // "myBPM" hold this BPM value now. 

if (pulseSensor.sawStartOfBeat())              // Constantly test to see if "a beat happened". 
{            
 Serial.println("♥  A HeartBeat Happened ! "); // If test is "true", print a message "a heartbeat happened".
 Serial.print("BPM: ");                        // Print phrase "BPM: " 
 Serial.println(myBPM);                        // Print the value inside of myBPM. 
 lcd.setCursor(0,0);
 lcd.print(myBPM);

 
  if(myBPM>120)
  {
    Serial.println("HIGH BPM");
    lcd.setCursor(0,1);
    lcd.print("HIGH BPM");
  }
  Serial.println();
  
  if(myBPM<40)
  {
    Serial.print("LOW BPM, EMERGENCY");
    lcd.setCursor(0,1);
    lcd.print("EMERGENCY");
  }
  Serial.println();
}

  delay(20);                    // considered best practice in a simple sketch.

}

  
