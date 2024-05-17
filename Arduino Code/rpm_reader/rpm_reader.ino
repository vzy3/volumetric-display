const int photogate = 2;
volatile int pre = 0;
volatile int now = 0;
volatile int period = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  //pinMode(A1, INPUT);
  pinMode(photogate, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(photogate), pin_ISR, FALLING);
}

void loop() {
}

void pin_ISR(){
  pre = now;
  now = millis();
  period = now-pre;
  Serial.println(period);
}
