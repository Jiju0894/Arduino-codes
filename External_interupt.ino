const byte ledPin = 13;
const byte interruptPin = 3;
volatile byte state = LOW;
int count=0;
void setup() {
   Serial.begin(9600);
  pinMode(ledPin, OUTPUT);
  pinMode(interruptPin, INPUT_PULLUP);
 // attachInterrupt(digitalPinToInterrupt(interruptPin), blink, CHANGE);
 attachInterrupt(digitalPinToInterrupt(interruptPin), blink, FALLING);
}

void loop() {
  digitalWrite(ledPin, state);\
  
}

void blink() {
  state = !state;
   Serial.println(count++);
   
}
