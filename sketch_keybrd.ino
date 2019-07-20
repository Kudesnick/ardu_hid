
#include "DigiKeyboard.h"  

void setup() {
 pinMode(0, INPUT);
 pinMode(1, INPUT);
 pinMode(2, INPUT);
}
void loop() {
 
if (digitalRead(0)==HIGH){
   DigiKeyboard.sendKeyStroke(KEY_0 , MOD_CONTROL_LEFT);
 }
 if (digitalRead(1)==HIGH){
   DigiKeyboard.sendKeyStroke(KEY_1 , MOD_CONTROL_LEFT);
 }
 if (digitalRead(2)==HIGH){
   DigiKeyboard.sendKeyStroke(KEY_2 , MOD_CONTROL_LEFT);
 }
}
