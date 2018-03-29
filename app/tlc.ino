#include "config.h"
#include "Adafruit_TLC59711.h"
#include <SPI.h>

Adafruit_TLC59711 tlc = Adafruit_TLC59711(NUM_TLC59711, CLOCK_PIN, DATA_PIN);

void initTLC()
{
  Serial.println("Initializing TLC.");

  tlc.begin();
  tlc.write();
  rgbWipeCycle();
  colorWipe(0, 0, 0, 0);
}

void stopLEDs()
{
  // Serial.println("stopLEDs");

  colorWipe(0, 0, 0, 0);
}

void rgbWipeCycle()
{
  // Serial.println("rgbWipeCycle");

  colorWipe(65535, 0, 0, 0); // "Red" (depending on your LED wiring)
  delay(1000);
  colorWipe(0, 65535/4, 0, 0); // "Green" (depending on your LED wiring)
  delay(1000);
  colorWipe(0, 0, 65535/4, 0); // "Blue" (depending on your LED wiring)
  delay(1000);
  colorWipe(0, 0, 0, 0);
}

// Fill the dots one after the other with a color
void colorWipe(uint16_t r, uint16_t g, uint16_t b, uint8_t wait)
{
  // Serial.println("ColorWipe");

  for (uint16_t i = 0; i < 8 * NUM_TLC59711; i++)
  {
    tlc.setLED(i, r, g, b);
    tlc.write();
    delay(wait);
  }
}

void rainbow()
{
  // Serial.println("rainbow");

  uint8_t wait = 0;
  uint32_t i, j;

  for (j = 0; j < 65535; j += 20)
  {
    for (i = 0; i < 4 * NUM_TLC59711; i++)
    {
      Wheel(i, i + j & 65535);
    }
    tlc.write();
    delay(wait);
  }
}

// Slightly different, this makes the rainbow equally distributed throughout
void rainbowCycle()
{
  // Serial.println("rainbowCycle");

  uint8_t wait = 0;
  uint32_t i, j;

  for (j = 0; j < 65535; j += 10)
  { // 1 cycle of all colors on wheel
    for (i = 0; i < 4 * NUM_TLC59711; i++)
    {
      Wheel(i, ((i * 65535 / (4 * NUM_TLC59711)) + j) & 65535);
    }
    tlc.write();
    delay(wait);
  }
}

void holidayWipe()
{
  // Serial.println("holidayWipe");

  colorWipe(65535, 0, 0, 0); // "Red" (depending on your LED wiring)
  delay(1000);
  colorWipe(0, 65535 / 4, 0, 0); // "Green" (depending on your LED wiring)
  delay(1000);
  colorWipe(0, 0, 0, 0);
}

// Input a value 0 to 4095 to get a color value.
// The colours are a transition r - g - b - back to r.
void Wheel(uint8_t ledn, uint16_t WheelPos)
{
  if (WheelPos < 21845)
  {
    tlc.setLED(ledn, 3 * WheelPos, 65535 - 3 * WheelPos, 0);
  }
  else if (WheelPos < 43690)
  {
    WheelPos -= 21845;
    tlc.setLED(ledn, 65535 - 3 * WheelPos, 0, 3 * WheelPos);
  }
  else
  {
    WheelPos -= 43690;
    tlc.setLED(ledn, 0, 3 * WheelPos, 65535 - 3 * WheelPos);
  }
}
