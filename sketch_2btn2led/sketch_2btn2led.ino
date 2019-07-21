
#include "DigiKeyboard.h"  

#define BTN1_PIN 0
#define BTN2_PIN 2

#define DEBOUNCE_TIME 25
#define BLINK_TIME 200

void setup()
{
  pinMode(BTN1_PIN, INPUT_PULLUP);
  pinMode(BTN2_PIN, INPUT_PULLUP);

  DigiKeyboard.update();
  // this is generally not necessary but with some older systems it seems to
  // prevent missing the first character after a delay:
  DigiKeyboard.sendKeyStroke(0);
}

void led_blink(uint8_t _pin)
{
  if (digitalRead(_pin) == HIGH)
  {
    pinMode(_pin, OUTPUT);
    digitalWrite(_pin, HIGH);
    delay(BLINK_TIME);
    digitalWrite(_pin, LOW);
    delay(BLINK_TIME);
    digitalWrite(_pin, HIGH);
    delay(BLINK_TIME);
    digitalWrite(_pin, LOW);
    pinMode(_pin, INPUT_PULLUP);
  }
}

void btn_scan(uint8_t _pin)
{
  if (digitalRead(_pin) == LOW)
  {
    delay(DEBOUNCE_TIME);
    
    if (digitalRead(_pin) == LOW)
    {
      if (_pin == BTN1_PIN)
        led_blink(BTN2_PIN);
      if (_pin == BTN2_PIN)
        led_blink(BTN1_PIN);
      
      while (digitalRead(_pin) == LOW) delay(DEBOUNCE_TIME);
    }
  }
}

void key_send()
{
  DigiKeyboard.sendKeyStroke(KEY_F7, MOD_CONTROL_LEFT | MOD_ALT_LEFT);
}

void loop()
{
  btn_scan(BTN1_PIN);
  btn_scan(BTN2_PIN);
}
