/*
 * Created by ArduinoGetStarted.com
 *
 * This example code is in the public domain
 *
 * Tutorial page: https://arduinogetstarted.com/tutorials/arduino-neopixel-led-strip
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL5 5  // Arduino pin that connects to NeoPixel
#define PIN_NEO_PIXEL3 3 
#define PIN_NEO_PIXEL6 6 
#define PIN_NEO_PIXEL9 9 
#define NUM_PIXELS 72    // The number of LEDs (pixels) on NeoPixel

#define DELAY_INTERVAL 250  // 250ms pause between each pixel

Adafruit_NeoPixel NeoPixel5(NUM_PIXELS, PIN_NEO_PIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel3(NUM_PIXELS, PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel6(NUM_PIXELS, PIN_NEO_PIXEL6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel9(NUM_PIXELS, PIN_NEO_PIXEL9, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel3.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  NeoPixel5.begin();
  NeoPixel6.begin();
  NeoPixel9.begin();
}

void loop() {
  NeoPixel3.clear();  // set all pixel colors to 'off'. It only takes effect if pixels.show() is called
  NeoPixel5.clear();
  NeoPixel6.clear();
  NeoPixel9.clear();

  // turn pixels to green one by one with delay between each pixel
  for (int pixel = 0; pixel < NUM_PIXELS; pixel++) {           // for each pixel
    NeoPixel3.setPixelColor(pixel, NeoPixel3.Color(0, 12, 90));  // it only takes effect if pixels.show() is called
    NeoPixel3.show();                                           // send the updated pixel colors to the NeoPixel hardware.
    
    if (pixel >=2) {
        NeoPixel5.setPixelColor(pixel-2, NeoPixel5.Color(90, 0, 0));  // it only takes effect if pixels.show() is called
        NeoPixel5.show();  
    }
    
    NeoPixel6.setPixelColor(pixel, NeoPixel6.Color(0, 90, 0));  // it only takes effect if pixels.show() is called
    NeoPixel6.show();  
    
    if (pixel >=2 and pixel < NUM_PIXELS-18) {
        NeoPixel9.setPixelColor(pixel-2, NeoPixel9.Color(0, 30, 40));  // it only takes effect if pixels.show() is called
        NeoPixel9.show();
    }  

    delay(DELAY_INTERVAL);  // pause between each pixel
  }

}
