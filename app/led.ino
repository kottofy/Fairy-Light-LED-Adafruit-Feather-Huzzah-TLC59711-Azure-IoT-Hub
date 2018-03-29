void initBuiltInLED()
{
    Serial.println("Initializing Built-In LED.");
    pinMode(LED_BUILTIN, OUTPUT);
    blinkLED();
}

void blinkLED()
{
    digitalWrite(LED_BUILTIN, HIGH);
    delay(500);
    digitalWrite(LED_BUILTIN, LOW);
}
