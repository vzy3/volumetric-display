// display a cup of water 

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL3 3  // Arduino pin that connects to NeoPixel
#define PIN_NEO_PIXEL5 5  
#define PIN_NEO_PIXEL6 6 
#define PIN_NEO_PIXEL9 9 
#define NUM_POS 8 // number of spots the leds light up

int NUM_PIXELS[] = {72, 70, 72, 52};

Adafruit_NeoPixel NeoPixel5(NUM_PIXELS[1], PIN_NEO_PIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel3(NUM_PIXELS[0], PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel6(NUM_PIXELS[2], PIN_NEO_PIXEL6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel9(NUM_PIXELS[3], PIN_NEO_PIXEL9, NEO_GRB + NEO_KHZ800);

int P3[] = {};
int P5[] = {31, 32, 34, 69};
int P6[] = {0, 33, 34, 35};
int P9[] = {};

int W3[] = {38, 51, 56, 69};
int W5[] = {0, 13, 19, 30, 37, 48, 55, 66};
int W6[] = {3, 14, 22, 31, 41, 42, 43, 44, 45, 46, 47, 48, 60, 61, 62, 63, 64, 65};
int W9[] = {4, 5, 6, 7, 8, 9};

int B5[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11, 12, 20, 21, 22, 23, 24, 25, 26, 27, 28, 29,
            38, 39, 40, 41, 42, 43, 44, 45, 46, 47, 56, 57, 58, 59, 60, 61, 62, 63, 64, 65};
int B6[] = {4, 5, 6, 7, 8, 9, 10, 11, 12, 13, 23, 24, 25, 26, 27, 28, 29, 30};

int NUM_CUP[] = {4, 8, 18, 6};
int NUM_WATER[] = {0, 42, 18, 0};

uint32_t white = NeoPixel3.Color(60, 60, 60);
uint32_t blue = NeoPixel3.Color(0, 0, 60);

////////////////////// interrupt //////////////////////
const int photogate = 2;
volatile int pre = 0;
volatile int now = 0;
volatile int period = 0;
volatile short slice = 0;
volatile bool lit = false;
volatile short current = 0; // 0 to NUM_POS - 1

void pin_ISR(){
  pre = now;
  now = millis();
  period = now-pre;
  slice = period/NUM_POS;
  Serial.println(period);
  for (int i=0; i<0; i++) {
      NeoPixel3.setPixelColor(P3[i], white);
    }
    for (int i=0; i<4; i++) {
      NeoPixel5.setPixelColor(P5[i], white);
    }
    for (int i=0; i<4; i++) {
      NeoPixel6.setPixelColor(P6[i], white);
    }
    for (int i=0; i<0; i++) {
      NeoPixel9.setPixelColor(P9[i], white);
    }

    NeoPixel3.show();                             
    NeoPixel5.show();  
    NeoPixel6.show();  
    NeoPixel9.show();
}

////////////////////// set up //////////////////////////

void setup() {
  
  Serial.begin(9600);

  // leds
  pinMode(A1, INPUT_PULLUP);
  NeoPixel5.begin();  // INITIALIZE NeoPixel strip object (REQUIRED)
  NeoPixel3.begin();
  NeoPixel6.begin();
  NeoPixel9.begin();

  NeoPixel5.clear();  // INITIALIZE NeoPixel strip object (REQUIRED)
  NeoPixel3.clear();
  NeoPixel6.clear();
  NeoPixel9.clear();

  // interrupt
  pinMode(photogate, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(photogate), pin_ISR, FALLING);
}

///////////////////////// loop ///////////////////////////

void loop() {
  // put your main code here, to run repeatedly:

  
  if ((millis() - now)%slice < 10){
    
    
  }


  for(int i = 0; i<NUM_CUP[0]; i++){
    NeoPixel3.setPixelColor(W3[i], white);
  }
  for(int i = 0; i<NUM_CUP[1]; i++){
    NeoPixel5.setPixelColor(W5[i], white);
  }
  for(int i = 0; i<NUM_CUP[2]; i++){
    NeoPixel6.setPixelColor(W6[i], white);
  }
  for(int i = 0; i<NUM_CUP[3]; i++){
    NeoPixel9.setPixelColor(W9[i], white);
  }

  for(int i = 0; i<NUM_WATER[1]; i++){
    NeoPixel5.setPixelColor(B5[i], blue);
  }
  for(int i = 0; i<NUM_WATER[2]; i++){
    NeoPixel6.setPixelColor(B6[i], blue);
  }

  NeoPixel3.show();                             
  NeoPixel5.show();  
  NeoPixel6.show();  
  NeoPixel9.show();
  NeoPixel3.clear();
  NeoPixel5.clear();
  NeoPixel6.clear();
  NeoPixel9.clear();
  
}
