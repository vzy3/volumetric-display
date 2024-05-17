/*
 * lighting up a vertical strip
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
#define DELAY_INTERVAL 370  // 250ms pause between each pixel
bool led_on = false;

Adafruit_NeoPixel NeoPixel5(NUM_PIXELS, PIN_NEO_PIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel3(NUM_PIXELS, PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel6(NUM_PIXELS, PIN_NEO_PIXEL6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel9(NUM_PIXELS, PIN_NEO_PIXEL9, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel5.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  NeoPixel3.begin();
  NeoPixel6.begin();
  NeoPixel9.begin();
}

void loop() {
  
  if(!led_on){
      NeoPixel5.setPixelColor(16, NeoPixel5.Color(90, 90, 90));  // it only takes effect if pixels.show() is called
      NeoPixel5.show();                                           // send the updated pixel colors to the NeoPixel hardware.

      NeoPixel3.setPixelColor(16, NeoPixel3.Color(90, 90, 90));  // it only takes effect if pixels.show() is called
      NeoPixel3.show();  
        
      NeoPixel6.setPixelColor(16, NeoPixel6.Color(90, 90, 90));  // it only takes effect if pixels.show() is called
      NeoPixel6.show();  
      
      NeoPixel9.setPixelColor(16, NeoPixel9.Color(90, 90, 90));  // it only takes effect if pixels.show() is called
      NeoPixel9.show();
      led_on = !led_on;
  }else{
      NeoPixel5.clear();  
      NeoPixel3.clear();
      NeoPixel6.clear();
      NeoPixel9.clear();
      
      NeoPixel5.show();
      NeoPixel3.show();
      NeoPixel6.show();
      NeoPixel9.show();
      led_on = !led_on;
      delay(DELAY_INTERVAL);
  
  }

}

