#include<LiquidCrystal.h>
int RS=12;
int EN=11;
int D4=8;
int D5=7;
int D6=6;
int D7=5;
LiquidCrystal lcd(RS,EN,D4,D5,D6,D7);
char data[12],temp[12];
char RFID_1[]="3600A60A6DF7", RFID_2[]="3600A669738A";
int i,j,flag=0;

void setup()
{
 Serial.begin(9600);
 lcd.begin(16,2);
 lcd.print("Hello");
 delay(1000);
}

void loop()
{
  if(Serial.available())
  {
  char a=Serial.read();
    data[i]=a;
    i++;
  }

  
  if(i==12)
  {
    
   // int cmp_flag=-1;
  
  
      if( compare(data,RFID_1)==1)
      {
      Serial.print("RFID-1");
      lcd.setCursor(0,0);
      lcd.print("RFID-1");
      lcd.setCursor(0,1);
      for(int j=0;j<12;j++)
        {
          lcd.print(data[j]);
        }
      }
 
  
   else if( compare(data,RFID_2)==1)
    {
      Serial.print("RFID-2");
      lcd.setCursor(0,0);
      for(int j=0;j<12;j++)
      {
        //Serial.print(data[j]);
        lcd.setCursor(0,1);
        lcd.print(data[j]);
      }
    }
 
  
    else
    {
      Serial.print("Unknown Id");
      lcd.setCursor(0,0);
      lcd.print("Unknown Id");
    }
       Serial.println();
    i=0;
  }
}
 
int compare( char *a,char *b)
{
  for(j=0;j<12;j++)
   {
    if(a[j]!=b[j])
   {
    return 0;
   }
   }
   return 1;
}

