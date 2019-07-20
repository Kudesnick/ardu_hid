
#define BTN_PIN 0
#define LED_PIN 1
#define DEBOUNCE_TIME 25

void setup()
{
  pinMode(BTN_PIN, INPUT_PULLUP);
  pinMode(LED_PIN, OUTPUT);
}

void led_inverse()
{
  static uint8_t led_sts = LOW;

  led_sts = (led_sts == LOW) ? HIGH : LOW;
  digitalWrite(LED_PIN, led_sts);
}

void loop()
{
  if (digitalRead(BTN_PIN) == LOW)
  {
    delay(DEBOUNCE_TIME);
    
    if (digitalRead(BTN_PIN) == LOW)
    {
      led_inverse();
      
      while (digitalRead(BTN_PIN) == LOW) delay(DEBOUNCE_TIME);
    }
  }
}
