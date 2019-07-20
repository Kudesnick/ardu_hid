
#include "DigiKeyboard.h"  

#define BTN_PIN 0
#define LED_PIN 1
#define DEBOUNCE_TIME 25
#define BLINK_TIME 100

void setup()
{
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);

  DigiKeyboard.update();
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
}

void led_blink()
{
  digitalWrite(LED_PIN, HIGH);
  delay(BLINK_TIME);
  digitalWrite(LED_PIN, LOW);
}

void key_send()
{
  DigiKeyboard.sendKeyStroke(KEY_K, MOD_CONTROL_LEFT);
}

void loop()
{
  if (digitalRead(BTN_PIN) == LOW)
  {
    delay(DEBOUNCE_TIME);
    
    if (digitalRead(BTN_PIN) == LOW)
    {
      led_blink();
      key_send();
      
      while (digitalRead(BTN_PIN) == LOW) delay(DEBOUNCE_TIME);
    }
  }
}
