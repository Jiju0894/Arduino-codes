void GPRS_send(float a,float b)
{
lcd.setCursor(0, 1);
  delay(10);
  lcd.print("UPLOADING DATA..");
  delay(500);
mySerial.println("AT");
delay(1000);
mySerial.println("AT+CPIN?");//check for sim
delay(1000);
mySerial.println("AT+CREG?"); // checking sim registeration
delay(1000); 
mySerial.println("AT+CGATT?");//checking if MS is connected to GPRS
delay(1000);
mySerial.println("AT+CIPSHUT");
delay(1000); 
mySerial.println("AT+CIPSTATUS"); // current connection status
delay(2000);
mySerial.println("AT+CIPMUX=0");// start multiconnection
delay(2000);
mySerial.println("AT+CSTT=\"airtelgprs.com\"");// APN of the sim
delay(1000);
mySerial.println("AT+CIICR ");// start wireless connection with GPRS
delay(3000);
mySerial.println("AT+CIFSR ");//get local IP address
delay(1000); 
mySerial.println("AT+CIPSPRT=0");
delay(3000); 
mySerial.println("AT+CIPSTART=\"TCP\",\"api.thingspeak.com\",\"80\"");// start TCP connection AT+HTTPPARA=\"URL\",\"api.thingspeak.com/update\"
delay(5000);  
mySerial.println("AT+CIPSEND");// send data through TCP/UDP connection
delay(5000);
//String str="GET https://api.thingspeak.com/update?api_key=PESQLADSZ6S92RM0&field1=" +String(a)+"&field2=" +String(b); 
String str="GET https://api.thingspeak.com/update?api_key=J1ZKF0F8766QJYO3&field1=" +String(a)+"&field2=" +String(b); 

mySerial.print(str);
mySerial.println();
delay(3000);
mySerial.write(26);
delay(1000); 
mySerial.println();
mySerial.println("AT+CIPSHUT");
delay(1000); 
lcd.setCursor(0, 1);
  delay(10);
  lcd.print("   COMPLETE     ");
  delay(1000);
}
