void initBuiltInLED() {
    pinMode(LED_BUILTIN, OUTPUT);
 }

void blinkLED()
{
   digitalWrite(LED_BUILTIN, HIGH);
   delay(500);
   digitalWrite(LED_BUILTIN, LOW);
}
