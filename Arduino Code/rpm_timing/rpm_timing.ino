#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL3 3  // Arduino pin that connects to NeoPixel
#define PIN_NEO_PIXEL5 5  
#define PIN_NEO_PIXEL6 6 
#define PIN_NEO_PIXEL9 9 

volatile bool interrupted = false;
volatile float microsPerPixel;
volatile float nextPixelMicros = 0;

elapsedMicros timeSince;


int NUM_PIXELS[] = {72, 70, 72, 52};

Adafruit_NeoPixel NeoPixel5(NUM_PIXELS[1], PIN_NEO_PIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel3(NUM_PIXELS[0], PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel6(NUM_PIXELS[2], PIN_NEO_PIXEL6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel9(NUM_PIXELS[3], PIN_NEO_PIXEL9, NEO_GRB + NEO_KHZ800);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(19200);
  pinMode(2, INPUT_PULLUP);

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
  // put your main code here, to run repeatedly:
//  if (digitalRead(2)==LOW) {
//    
//  }
  Serial.println(timeSince);
}
