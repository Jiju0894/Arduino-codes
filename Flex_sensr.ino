const int flexPin_1 = A3; 
const int flexPin_2 = A4;
const int ledPin = 7; 

void setup() 
{ 
  Serial.begin(9600);
  pinMode(ledPin,OUTPUT);
  pinMode(flexPin_1,INPUT);
  pinMode(flexPin_2,INPUT);
} 

void loop() 
{ 
  int flexValue_1;
  flexValue_1 = analogRead(flexPin_1);
  int val_2 =  analogRead(flexPin_2);
  Serial.print("sensor_1 = ");
  Serial.print(flexValue_1);
  Serial.print("\t");
  Serial.print("sensor_2 = ");
  Serial.println(val_2);
  Serial.println();
    delay(1000);
//  if(flexValue>890)
//     digitalWrite(ledPin,HIGH);
//  else
//    digitalWrite(ledPin,LOW);
  

} 
