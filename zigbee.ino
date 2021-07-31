//#include <TinyGPS++.h>
//
//#include <TinyGPS++.h>
//#include <SoftwareSerial.h>
///* Create object named bt of the class SoftwareSerial */
//SoftwareSerial GPS_SoftSerial(4, 3);/* (Rx, Tx) */
///* Create an object named gps of the class TinyGPSPlus */
//TinyGPSPlus gps;      
//
//volatile float minutes, seconds;
//volatile int degree, secs, mins;
int led = 13;
int received = 0;
int i;
void setup() {
  Serial.begin(9600); 
  pinMode(led, OUTPUT);
}
 
void loop() {
  if (Serial.available() > 0)
  {
  received = Serial.read();
  Serial.println(received);
  
    if (received == 'a')
    {
    digitalWrite(led, HIGH);
    delay(2000);
    digitalWrite(led, LOW);
    Serial.println("Vechicle Without Helmet Identified");
    sendsms();
    
    }
     else if (received == 'b'){
      for(i=0;i<5;i++){
    digitalWrite(led, HIGH);
    delay(1000);
    digitalWrite(led, LOW);
    delay(1000);
    }
  } 
}

}

void sendsms()
  {
//    Serial.println("AT");
//    delay(1000);
    //Serial.println("ATD+919121991303;");
    //Serial.println("ATEO");
    //delay(1000);
    Serial.println("AT+CMGF=1");
    delay(1000);
    Serial.println("AT+CMGS=\"+919526234625\"\r");
     //Serial.println("AT+CMGS=\"+919074598671\"\r");
    delay(1000);
   Serial.print("Traffic Rule Violation");
//    delay(10);
   //MY_SERIAL.println( link);
    delay(100);
    //Serial.write(26);
    Serial.println((char)26); // ASCII code of CTRL+Z
    delay(1000);
  }
