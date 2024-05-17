// display 8 vertical lines

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

int P3[] = {2,33,38,69};
int P5[] = {0,31,36,67};
int P6[] = {2,33,38,69};
int P9[] = {0,31,36};

uint32_t white = NeoPixel3.Color(20,20,20);

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
  NeoPixel5.clear();
  NeoPixel3.clear();
  NeoPixel6.clear();
  NeoPixel9.clear();

  // set lit to false each time the slice position is reached
  if ((millis() - now)%slice < 5){
    lit = false;
  }

  
  
  if ((millis() - now)%slice < 10 and !lit){
    
    for (int i=0; i<4; i++) {
      NeoPixel3.setPixelColor(P3[i], white);
    }
    for (int i=0; i<4; i++) {
      NeoPixel5.setPixelColor(P5[i], white);
    }
    for (int i=0; i<4; i++) {
      NeoPixel6.setPixelColor(P6[i], white);
    }
    for (int i=0; i<3; i++) {
      NeoPixel9.setPixelColor(P9[i], white);
    }
    lit = true;
  }

  NeoPixel3.show();                             
  NeoPixel5.show();  
  NeoPixel6.show();  
  NeoPixel9.show();
  
}
