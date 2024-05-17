// firework

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
uint32_t yellow = NeoPixel3.Color(255,255,0);
int num_led = 0;
int yellow_start = 0;
int yellow_end = 0;
int pink_start = 12;
int pink_end = 0;
int loop_num = 0;

int loop0[5][8] = {
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  {261, 234, 225, 200, 191, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300}
};

int loop1[5][8] = {
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  {164, 155, 128, 119, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300}
};

int loop2[5][8] = {
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  { 92,  83, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300}
};

int loop3[5][8] = {
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  { 58, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300}
};

int loop4[5][8] = {
  {300, 300, 300, 300, 300, 300, 300, 300},
  { 58, 300, 300, 300, 300, 300, 300, 300},
  { 49,  57,  58,  59,  83, 300, 300, 300},
  { 58, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300, 300, 300, 300, 300, 300}
};

int loop5[5][21] = {
  { 58, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300},
  { 50,  49,  48,  57,  58,  59,  82,  83,  84, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300},
  {  21, 22, 47,  48,  49,   50,  51,  60,  59,  58,  57,  56,  81,  82,  83,  84,  85,  93,  92,  91,  23},
  { 50,  49,  48,  57,  58,  59,  82,  83,  84, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300},
  { 58, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300}
};

int loop6[5][16] = {
  { 91,  92,  93, 119, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300},
  { 81,  85,  93,  92,  91, 117, 119, 121, 128, 300, 300, 300, 300, 300, 300, 300},
  { 48,  49,  50,  60,  56,  80,  81,  86,  94,  90, 118, 120, 129,  92,  91,  85},
  { 81,  85,  93,  92,  91, 117, 119, 121, 128, 300, 300, 300, 300, 300, 300, 300},
  { 91,  92,  93, 119, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300, 300}
};

int loop7[5][10] = {
  {300, 300, 121, 300, 300, 300, 300, 300, 300, 300},
  {300, 300, 300,  93, 118, 300,  88,  80, 300, 300},
  {300, 300, 117,  91, 300, 127, 300,  89, 300, 157},
  {300, 300,  90,  93, 300, 129,  88,  80, 300, 300},
  {300,  92, 300, 126, 300, 300, 300, 300, 300, 300}
};


// for all leds in this frame
void set_color(uint32_t color, int leds[], int num_idx) {
  for (int i=0; i<num_idx; i++) { 
    if (leds[i]<(72-11)){ 
      NeoPixel3.setPixelColor(leds[i]-11, color);
    }else if(leds[i]<(142-11)){
      NeoPixel5.setPixelColor(leds[i]-72, color);
    }else if(leds[i]<(214-11)){
      NeoPixel6.setPixelColor(leds[i]-142, color);
    }else if(leds[i]<(266-11)){
      NeoPixel9.setPixelColor(leds[i]-214, color);
    }
  }
}


void photogate(){

  for(int i=0; i<5; i++){ // 16 is max num of frames

    switch(loop_num){
      case 0:
        set_color(yellow, loop0[i], 8);
        break;
      case 1:
        set_color(yellow, loop1[i], 8);
        break;
      case 2:
        set_color(yellow, loop2[i], 8);
        break;
      case 3:
        set_color(yellow, loop3[i], 8);
        break;
      case 4:
        set_color(yellow, loop4[i], 8);
        break;
      case 5:
        set_color(yellow, loop5[i], 21);
        break;
      case 6:
        set_color(yellow, loop6[i], 16);
        break;
      case 7:
        set_color(yellow, loop7[i], 12);
        break;
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
  loop_num = loop_num+1;
  if (loop_num>8){
    loop_num = 0;
  }
  Serial.println(loop_num);
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

  //num_led = sizeof(mat_yellow[0])/sizeof(mat_yellow[0][0]);
  //yellow_end = yellow_start + sizeof(mat_yellow)/sizeof(mat_yellow[0]);
}




void loop() {
    
}
