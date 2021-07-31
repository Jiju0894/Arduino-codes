#include<LiquidCrystal.h>
#include<SoftwareSerial.h>
int RS=12;
int EN=11;
int D4=8;
int D5=7;
int D6=6;
int D7=5;
int Rx=2;
int Tx= 3;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
char a;
SoftwareSerial pH_serial(Rx,Tx);
char pH_array[30],b[30];
int i=0,j;
String final_ph="";
bool complete_flag=0,start_flag=0;;
void setup()
{
 Serial.begin(9600);
 pH_serial.begin(9600);
 lcd.begin(16,2);
 lcd.print("Hello");
 delay(1000);
}

void loop()
{
  final_ph="";
  while(complete_flag==0)
  {
 if(pH_serial.available())
  {
    a=pH_serial.read();
    //Serial.print(
     if(a=='P')
       {
        start_flag=1;
       }
    if(start_flag==1)
    {
        pH_array[i]=a;  
     i++; 
     if((a==',') || (i>=30))
     {
      complete_flag=1;
      start_flag=0;
      j=i;
      i=0; 
     }
    } 
  }
  }
 if(complete_flag==1)
    {
     
     
//int k=0;

      for(int i=0;i<j;i++)
      {
         if(isDigit(pH_array[i])||(pH_array[i]=='.'))
        {
          final_ph=final_ph+String(pH_array[i]);
         // k++;
          
        }  
      }
      j=0;
        lcd.clear();
       lcd.setCursor(0,0);
     complete_flag=0;
       lcd.print("pH= ");
       lcd.print(final_ph);
        Serial.println("ph:"+final_ph);
        //clear_array();

     unsigned int ph_value=final_ph.toInt();
      Serial.println(ph_value);
       
//       if(ph_value>7)
//       {
//        Serial.println("Soln is Basic");
//        lcd.setCursor(0,1);
//        lcd.print("Basic");
//       }
//       
//      if(ph_value < 7)
//       {
//        Serial.println("Soln is Acidic");
//        lcd.setCursor(0,1);
//        lcd.print("Acidic");
//       }
//       
//        if(ph_value==7)
//       {
//        Serial.println("Soln is Pure Water");
//        lcd.setCursor(0,1);
//        lcd.print("Pure Water");
//       }
    } 
  delay(1000);

}

void clear_array()
{
for(int i=0;i<30;i++)
{
  pH_array[i]='\0';
}
  
}

