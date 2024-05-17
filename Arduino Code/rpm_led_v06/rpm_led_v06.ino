// petals

#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>  // Required for 16 MHz Adafruit Trinket
#endif

#define PIN_NEO_PIXEL3 3  // Arduino pin that connects to NeoPixel

Adafruit_NeoPixel NeoPixel3(72, PIN_NEO_PIXEL3, NEO_GRB + NEO_KHZ800);

int P3[] = {0,1,2,3,4,5,6,7};

uint32_t pink = NeoPixel3.Color(230,0,255);

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(2, INPUT_PULLUP);
  
  NeoPixel3.begin();
  NeoPixel3.clear();
}

// this is a really stupid function. i'll fix it if this works
void led_col(uint32_t color, int leds[]) {
  for (int i=0; i<8; i++) {
    if (leds[i]==1) {
      NeoPixel3.setPixelColor(P3[i], color);
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

int angle[48][8] = {
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,0,1,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {1,0,0,0,0,0,0,0},
  {0,1,0,0,0,0,0,0},
  {0,0,1,0,0,0,0,0},
  {0,0,0,1,0,0,0,0},
  {0,0,0,0,1,0,0,0},
  {0,0,0,0,0,1,0,0}
};

void loop() {
  // put your main code here, to run repeatedly:
  //Serial.println(digitalRead(2));
  NeoPixel3.clear();
  NeoPixel3.show();
  if (digitalRead(2)==LOW) {
    for (int i=0; i<44; i++) {
      NeoPixel3.clear();
      NeoPixel3.show();
      int col[] = {angle[i][0],angle[i][1],angle[i][2],angle[i][3],angle[i][4],angle[i][5],angle[i][6],angle[i][7]};
      led_col(pink, col);
      
      NeoPixel3.show(); 
      //delay(0.5);
    }
    //NeoPixel3.show(); 
  }
  //NeoPixel3.show(); 
}
