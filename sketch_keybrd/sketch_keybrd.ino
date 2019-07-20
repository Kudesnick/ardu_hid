
#include "DigiKeyboard.h"  

#define BTN_PIN 0
#define LED_PIN 1
#define DEBOUNCE_TIME 25
#define BLINK_TIME 100

void setup()
{
  pinMode(BTN_PIN, INPUT);
  pinMode(LED_PIN, OUTPUT);
}

void led_blink()
{
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_TIME);
  digitalWrite(LED_PIN, LOW);
}

void loop()
{
  if (digitalRead(BTN_PIN) == LOW)
  {
    delay(DEBOUNCE_TIME);
    
    if (digitalRead(BTN_PIN) == LOW)
    {
      led_blink();
      
      while (digitalRead(BTN_PIN) == LOW) delay(DEBOUNCE_TIME);
    }
  }
}
