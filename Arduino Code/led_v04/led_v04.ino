/*
 * lighting up a simple shape (cup of water)
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL3 3  // Arduino pin that connects to NeoPixel
#define PIN_NEO_PIXEL5 5  
#define PIN_NEO_PIXEL6 6 
#define PIN_NEO_PIXEL9 9 
    // The number of LEDs (pixels) on NeoPixel
#define DELAY_INTERVAL 370  // 250ms pause between each pixel
int W3[] = {38, 51, 56, 69};
int W5[] = {0, 13, 19, 30, 37, 48, 55, 66};
int W6[] = {3, 14, 22, 31, 41, 42, 43, 44, 45, 46, 47, 48, 60, 61, 62, 63, 64, 65};
int W9[] = {4, 5, 6, 7, 8, 9};

int B5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
            38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65};
int B6[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 23, 24, 25, 26, 27, 28, 29, 30};

int NUM_PIXELS[] = {72, 70, 72, 52};
int NUM_CUP[] = {4, 8, 18, 6};
int NUM_WATER[] = {0, 42, 18, 0};


Adafruit_NeoPixel NeoPixel5(NUM_PIXELS[1], PIN_NEO_PIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel3(NUM_PIXELS[0], PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel6(NUM_PIXELS[2], PIN_NEO_PIXEL6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel9(NUM_PIXELS[3], PIN_NEO_PIXEL9, NEO_GRB + NEO_KHZ800);

void setup() {
  NeoPixel5.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  NeoPixel3.begin();
  NeoPixel6.begin();
  NeoPixel9.begin();

  NeoPixel5.clear();  // INITIALIZE NeoPixel strip object (REQUIRED)
  NeoPixel3.clear();
  NeoPixel6.clear();
  NeoPixel9.clear();
}

void loop() {
  for(int i = 0; i<NUM_CUP[0]; i++){
    NeoPixel3.setPixelColor(W3[i]-11, NeoPixel3.Color(20, 20, 20));
  }
  for(int i = 0; i<NUM_CUP[1]; i++){
    NeoPixel5.setPixelColor(W5[i], NeoPixel5.Color(20, 20, 20));
  }
  for(int i = 0; i<NUM_CUP[2]; i++){
    NeoPixel6.setPixelColor(W6[i], NeoPixel6.Color(20, 20, 20));
  }
  for(int i = 0; i<NUM_CUP[3]; i++){
    NeoPixel9.setPixelColor(W9[i], NeoPixel9.Color(20, 20, 20));
  }

  for(int i = 0; i<NUM_WATER[1]; i++){
    NeoPixel5.setPixelColor(B5[i], NeoPixel5.Color(0, 0, 20));
  }
  for(int i = 0; i<NUM_WATER[2]; i++){
    NeoPixel6.setPixelColor(B6[i], NeoPixel6.Color(0, 0, 20));
  }
  
  
      NeoPixel5.show();                             
      NeoPixel3.show();  
      NeoPixel6.show();  
      NeoPixel9.show();

}
