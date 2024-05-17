// heart

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL3 3  // Arduino pin that connects to NeoPixel
#define PIN_NEO_PIXEL5 5  
#define PIN_NEO_PIXEL6 6 
#define PIN_NEO_PIXEL9 9 

int NUM_PIXELS[] = {72, 70, 72, 52};

Adafruit_NeoPixel NeoPixel5(NUM_PIXELS[1], PIN_NEO_PIXEL5, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel3(NUM_PIXELS[0], PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel6(NUM_PIXELS[2], PIN_NEO_PIXEL6, NEO_GRB + NEO_KHZ800);
Adafruit_NeoPixel NeoPixel9(NUM_PIXELS[3], PIN_NEO_PIXEL9, NEO_GRB + NEO_KHZ800);

int P3[] = {0,1,2,3,4,5,6,7};

uint32_t pink = NeoPixel3.Color(230,0,255);
uint32_t purple = NeoPixel3.Color(85,0,255);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
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

// this is a really stupid function. i'll fix it if this works
void led_col(Adafruit_NeoPixel* pixelp, int pos[], uint32_t color, int leds[]) {
  for (int i=0; i<8; i++) {
    if (leds[i]==1) {
      pixelp->setPixelColor(pos[i], color);
    }
  }
}

int heart[5][7] = {
  {0,1,1,0,1,1,0},
  {1,1,1,1,1,1,1},
  {0,1,1,1,1,1,0},
  {0,0,1,1,1,0,0},
  {0,0,0,1,0,0,0}
};

int heartc[48][8] = {
  {0,0,1,0,0,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,1,1,1,1,0,0,0},
  {0,0,1,1,1,1,0,0},
  {0,1,1,1,1,0,0,0},
  {0,1,1,1,0,0,0,0},
  {0,0,1,0,0,0,0,0}
};

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(2));
  NeoPixel3.clear();
  NeoPixel5.clear(); 
  NeoPixel6.clear();
  NeoPixel9.clear();
  NeoPixel3.show();
  if (digitalRead(2)==LOW) {
    for (int i=0; i<48; i++) {
      NeoPixel3.clear();
      NeoPixel3.show();
      int col[] = {heartc[i][0],heartc[i][1],heartc[i][2],heartc[i][3],heartc[i][4],heartc[i][5],heartc[i][6],heartc[i][7]};
      led_col(&NeoPixel3, P3, pink, col);
      
      NeoPixel3.show(); 
      //delay(0.5);
    }
//    for (int i=0; i<48; i++) {
//      NeoPixel5.clear();
//      NeoPixel5.show();
//      int col[] = {heartc[i][0],heartc[i][1],heartc[i][2],heartc[i][3],heartc[i][4],heartc[i][5],heartc[i][6],heartc[i][7]};
//      led_col(&NeoPixel5, P3, purple, col);
//      
//      NeoPixel5.show(); 
//      //delay(0.5);
//    }
  }
  //NeoPixel3.show();                             
  NeoPixel5.show();  
  NeoPixel6.show();  
  NeoPixel9.show();
}
