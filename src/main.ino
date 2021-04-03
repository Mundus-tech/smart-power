// Smart power
// pcb mk7, revision 0 and up -> new pinout
// Author: Fran Zekan

#include <Arduino.h>
#include <FastLED.h>
#include <math.h>

#define PI 3.14159

#define NUM_LEDS 16
#define DATA_PIN 19

CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<NEOPIXEL, DATA_PIN>(leds, NUM_LEDS);
  FastLED.setBrightness(64);

  Serial.begin(9600);
}

#define TIME 3000

double getI(int i, int offset) {
  double out = ((double)i + (offset / TIME) * 16);
  if(out > 16) {
    return out - 16;
  }

  return out;
}

void loop()
{
  int i;
  for(i = 0; i < TIME; i++) {
    for(int j = 0; j < 16; j++) {
      int brightness = 10;
      leds[j] = CHSV(0, 100, brightness);
    }

    FastLED.show();
    delay(1);
  }

  for(int i = 0; i < 16; i++) {
    leds[i] = CRGB::Black;
  }
  FastLED.show();
  delay(2000);

  // for(; i >= 0; i--) {
  //   for(int j = 0; j < 16; j++) {
  //     int brightness = sin(((double)j / 16) * PI) * ((double)i / TIME) * 255;
  //     leds[j] = CHSV(0, 100, brightness);
  //   }

  //   FastLED.show();
  //   delay(1);
  // }
}
