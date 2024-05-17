#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL3 3  // Arduino pin that connects to NeoPixel
#define PIN_NEO_PIXEL5 5  
#define PIN_NEO_PIXEL6 6 
#define PIN_NEO_PIXEL9 9 

int NUM_PIXELS[] = {72, 70, 72, 52};
int offset = 0;

Adafruit_NeoPixel NeoPixel5(NUM_PIXELS[1], PIN_NEO_PIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel3(NUM_PIXELS[0], PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel6(NUM_PIXELS[2], PIN_NEO_PIXEL6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel9(NUM_PIXELS[3], PIN_NEO_PIXEL9, NEO_GRB + NEO_KHZ800);

int P3[] = {2,33,38,69};
int P5[] = {0,31,36,67};
int P6[] = {2,33,38,69};
int P9[] = {0,31,36};

uint32_t white = NeoPixel3.Color(10,10,10);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(A1, INPUT_PULLUP);
  
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

  offset = offset + 100;
  delay(100);
  
  for (int i=0+offset; i<266+offset; i++) {

    Serial.println(i%266);
    delay(10);
    
    if (i%266<72){
      NeoPixel3.setPixelColor(i%266, NeoPixel3.Color(133-abs(133-i%266),0,abs(133-i%266)));
    }else if (i%266<(72+70)){
      NeoPixel5.setPixelColor(i%266-72, NeoPixel5.Color(133-abs(133-i%266),0,abs(133-i%266)));
    }else if (i%266<(72+70+72)){
      NeoPixel6.setPixelColor(i%266-72-70, NeoPixel6.Color(133-abs(133-i%266),0,abs(133-i%266)));
    }else{
      NeoPixel9.setPixelColor(i%266-72-70-72, NeoPixel9.Color(133-abs(133-i%266),0,abs(133-i%266)));
    }
  }

  NeoPixel3.show();                             
  NeoPixel5.show();  
  NeoPixel6.show();  
  NeoPixel9.show();
  
}
