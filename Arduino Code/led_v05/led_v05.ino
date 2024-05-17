/* gradient ball
 */

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL3 3  // Arduino pin that connects to NeoPixel
#define PIN_NEO_PIXEL5 5  
#define PIN_NEO_PIXEL6 6 
#define PIN_NEO_PIXEL9 9 

#define DELAY_INTERVAL 100  // 250ms pause between each pixel
int P3[] = {43,44,45,46,59,60,61,62,63,64,65,66};
int P5[] = {2,3,4,5,6,7,8,9,10,11,19,20,21,22,23,24,25,26,27,28,29,30,37,38,39,40,41,42,43,44,45,46,47,48,55,56,57,58,59,60,61,62,63,64,65,66,67};
int P6[] = {3,4,5,6,7,8,9,10,11,12,13,14,21,22,23,24,25,26,27,28,29,30,31,32,40,41,42,43,44,45,46,47,48,49,59,60,61,62,63,64,65,66};
int P9[] = {5,6,7,8};

int NUM_PIXELS[] = {72, 70, 72, 52};


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

int brightness = 7;

uint32_t red = NeoPixel3.Color(255,0,0);
uint32_t orange = NeoPixel3.Color(255,80,0);
uint32_t yellow = NeoPixel3.Color(255,200,0);
uint32_t lgreen = NeoPixel3.Color(0,255,100);
uint32_t green = NeoPixel3.Color(0,255,0);
uint32_t lblue = NeoPixel3.Color(0,255,255);
uint32_t blue = NeoPixel3.Color(0,0,255);
uint32_t purple = NeoPixel3.Color(85,0,255);
uint32_t pink = NeoPixel3.Color(230,0,255);

uint32_t colors3[] = {red,orange,yellow,lgreen,green,lblue,blue,purple,pink};
uint32_t colors5[] = {orange,yellow,lgreen,green,lblue,blue,purple,pink,red};
uint32_t colors6[] = {yellow,lgreen,green,lblue,blue,purple,pink,red,orange};
uint32_t colors9[] = {lgreen,green,lblue,blue,purple,red,orange,yellow};

void loop() {
  for (int i=0; i<9; i++) {
    NeoPixel3.clear();
    for (int j=0; j<12; j++) {
      NeoPixel3.setPixelColor(P3[j]-11, colors3[i]);
    }
    NeoPixel3.setBrightness(brightness);
    NeoPixel3.show();
    NeoPixel5.clear();
    for (int j=0; j<46; j++) {
      NeoPixel5.setPixelColor(P5[j], colors5[i]);
    }
    NeoPixel5.setBrightness(brightness);
    NeoPixel5.show();
    delay(DELAY_INTERVAL);
    NeoPixel6.clear();
    for (int j=0; j<42; j++) {
      NeoPixel6.setPixelColor(P6[j], colors6[i]);
    }
    NeoPixel6.setBrightness(brightness);
    NeoPixel6.show();
    delay(DELAY_INTERVAL);
    NeoPixel9.clear();
    for (int j=0; j<4; j++) {
      NeoPixel9.setPixelColor(P9[j], colors9[i]);
    }
    NeoPixel9.setBrightness(brightness);
    NeoPixel9.show();
    delay(DELAY_INTERVAL);
  }
  
  NeoPixel3.show();                             
  NeoPixel5.show();  
  NeoPixel6.show();  
  NeoPixel9.show();

}
