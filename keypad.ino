#include <Keypad.h>

const byte ROWS = 4; //four rows
const byte COLS = 3; //three columns

char keys[ROWS][COLS] = {
  {'1','2','3'},
  {'4','5','6'},
  {'7','8','9'},
  {'*','0','#'}
};
char key_array[10] ;
byte rowPins[ROWS] = {9, 8, 7, 6}; //connect to the row pinouts of the keypad
byte colPins[COLS] = {5, 4, 3}; //connect to the column pinouts of the keypad
int i=0;

//Create an object of keypad
Keypad keypad = Keypad( makeKeymap(keys), rowPins, colPins, ROWS, COLS );

void setup()
{
  Serial.begin(9600);
}
  
void loop()
{
  char key = keypad.getKey();   // Read the key
  if(key)
  {
  key_array[i]=key;
  i++;
  }
  // Print if key pressed
  if (i==4)
  {
    Serial.println(key_array);
      i=0;
  }
}
