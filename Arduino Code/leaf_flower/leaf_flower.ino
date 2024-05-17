// flower ?

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

uint32_t pink = NeoPixel3.Color(230,0,255);
uint32_t green = NeoPixel3.Color(0,255,0);
int num_led = 0;
int green_start = 0;
int green_end = 0;
int pink_start = 12;
int pink_end = 0;

int mat_green[15][8] = {
  {128, 155, 165, 300, 300, 300, 300, 300}, // 1st leaf
  { 91, 120, 127, 156, 164, 190, 202, 222}, // 1st leaf
  {128, 155, 165, 300, 300, 300, 300, 300}, // 1st leaf
  {300, 300, 300, 300, 300, 300, 300, 300}, // empty
  {300, 300, 300, 300, 300, 300, 300, 300}, // empty
  {300, 300, 300, 300, 300, 300, 300, 300}, // empty
  {224, 225, 226, 300, 300, 300, 300, 300}, // 2nd leaf
  {237, 223, 201, 200, 199, 227, 300, 300}, // 2nd leaf
  {224, 225, 226, 300, 300, 300, 300, 300}, // 2nd leaf
  {300, 300, 300, 300, 300, 300, 300, 300}, // empty
  {300, 300, 300, 300, 300, 300, 300, 300}, // empty
  {300, 300, 300, 300, 300, 300, 300, 300}, // empty
  {257, 238, 221, 203, 188, 167, 300, 300}, // stem 12
  {153, 130, 118,  92, 300, 300, 300, 300}, // stem 13
};

int mat_pink[15][8] = {
  { 84,  56, 300, 300, 300, 300, 300, 300}, // flower
  { 50,  56,  57,  58,  83,  84,  85,  86}, // flower
  { 84,  56,  86,  90, 300, 300, 300, 300}, // flower
};


// for all leds in this frame
void set_color(uint32_t color, int leds[]) {
  for (int i=0; i<num_led; i++) { 
    if (leds[i]<72-11){ 
      NeoPixel3.setPixelColor(leds[i]-11, color);
    }else if(leds[i]<142-11){
      NeoPixel5.setPixelColor(leds[i]-72, color);
    }else if(leds[i]<214-11){
      NeoPixel6.setPixelColor(leds[i]-142, color);
    }else if(leds[i]<266-11){
      NeoPixel9.setPixelColor(leds[i]-214, color);
    }
  }
}

void photogate(){
  
  for(int i=0; i<16; i++){ // 13 is max num of frames

    if(i<green_end){
      set_color(green, mat_green[i]);
    }
    if(i>= pink_start and i<pink_end){
      set_color(pink, mat_pink[i-pink_start]);
    }
    
    NeoPixel3.show(); 
    NeoPixel5.show(); 
    NeoPixel6.show(); 
    NeoPixel9.show();
    delay(1);
    NeoPixel5.clear(); 
    NeoPixel3.clear();
    NeoPixel6.clear();
    NeoPixel9.clear();
    NeoPixel3.show(); 
    NeoPixel5.show(); 
    NeoPixel6.show(); 
    NeoPixel9.show();
  }
}

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

  pinMode(2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(2), photogate, FALLING);

  num_led = sizeof(mat_green[0])/sizeof(mat_green[0][0]);
  green_end = green_start + sizeof(mat_green)/sizeof(mat_green[0]);
  pink_end = pink_start + sizeof(mat_pink)/sizeof(mat_pink[0]);
}




void loop() {
    
}
