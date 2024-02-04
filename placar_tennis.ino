#include <Keyboard.h>
const int Up = 2;
const int Left = 3;
const int Right = 4;
const int Down = 5;

void setup() {
  // put your setup code here, to run once:
  
  Serial.begin(9600);
  // .begin();
  pinMode(Up, INPUT_PULLUP);
  pinMode(Down, INPUT_PULLUP);
  pinMode(Left, INPUT_PULLUP);
  pinMode(Right, INPUT_PULLUP);
}


void loop() {
  int buttonStateUp = digitalRead(Up);
  int buttonStateDown = digitalRead(Down);
  int buttonStateLeft = digitalRead(Left);
  int buttonStateRight = digitalRead(Right);

  if (buttonStateUp == LOW){
    Keyboard.write('w');
    Serial.println("w");
    
  }
  if (buttonStateDown == LOW){
    Keyboard.write('s');
    Serial.println("s");
    
  } if (buttonStateLeft == LOW){
    Keyboard.write('a');
    Serial.println("a");
    
  } if (buttonStateRight == LOW){
    Keyboard.write('d');
    Serial.println("d");
    
   
 
}