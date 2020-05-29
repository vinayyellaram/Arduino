#include <FastLED.h> /// install the libray before running this code

#define ledPin 2    
#define noOfLed 60  // No of leds  present in led strip

CRGB led[noOfLed];

int noiseSignal;
int noOfLedTotoggel;

void setup() {
  pinMode(A0, INPUT);  // A0 is connect to a output pin of analog mic  module
  Serial.begin(9600);
}

void loop() { 
// this code will be repeated under this loop
  FastLED.addLeds<WS2812, ledPin, GRB>(led, noOfLed); 
  ledFn();
}

void ledFn() {
  noiseSignal = analogRead(A0); 
  Serial.println(noiseSignal);

  if (noiseSignal > 0 && noiseSignal <= 100)
  {
    noOfLedTotoggel = noOfLedToGlow(10);
    glowLed();
    ofLed();
  }
  else if (noiseSignal > 100 && noiseSignal <= 200)
  {
    noOfLedTotoggel = noOfLedToGlow(20);
    glowLed();
    ofLed();
  }
  else if (noiseSignal > 200 && noiseSignal <= 300)
  {
    noOfLedTotoggel = noOfLedToGlow(30);
    glowLed();
    ofLed();
  }
  else if (noiseSignal > 300 && noiseSignal <= 400)
  {
    noOfLedTotoggel = noOfLedToGlow(40);
    glowLed();
  }
  else if (noiseSignal > 400 && noiseSignal <= 500)
  {
    noOfLedTotoggel = noOfLedToGlow(50);
    glowLed();
    ofLed();
  }
  else if (noiseSignal > 500 && noiseSignal <= 600)
  {
    noOfLedTotoggel = noOfLedToGlow(60);
    glowLed();
    ofLed();
  }
  else if (noiseSignal > 600 && noiseSignal <= 700)
  {
    noOfLedTotoggel = noOfLedToGlow(70);
    glowLed();
  }
  else if (noiseSignal > 700 && noiseSignal <= 800)
  {
    noOfLedTotoggel = noOfLedToGlow(80);
    glowLed();
    ofLed();
  }
  else if (noiseSignal > 800 && noiseSignal <= 900)
  {
    noOfLedTotoggel = noOfLedToGlow(90);
    glowLed();
    ofLed();
  }
  else if (noiseSignal > 900 && noiseSignal <= 1000)
  {
    noOfLedTotoggel = noOfLedToGlow(100);
    glowLed();
    ofLed();
  }
  else {
    noOfLedTotoggel = noOfLedToGlow(5);
    glowLed();
    ofLed();
  }
}

void glowLed() {
    for (int i = 0; i <= noOfLedTotoggel; i++) {
      if (i < noOfLedToGlow(10)) {
        led[i] = CRGB(0,0,250);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(20)) {
        led[i] = CRGB(0,145,200);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(30)) {
        led[i] = CRGB(50,145,100);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(40)) {
        led[i] = CRGB(100, 145, 50);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(50)) {
        led[i] = CRGB(0, 200, 100);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(60)) {
        led[i] = CRGB(0, 250, 0);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(70)) {
        led[i] = CRGB(100, 100, 0);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(80)) {
        led[i] = CRGB(100, 0, 100);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(90)) {
        led[i] = CRGB(200, 0, 100);
        FastLED.show();
      }
      else if (i < noOfLedToGlow(100)) {
        led[i] = CRGB(250, 0, 0);
        FastLED.show();
      }
  }
}

int noOfLedToGlow(int no) {
  return (((no*noOfLed)/100) - 1);
}

void ofLed(){
  for (int i = 60; i >= noOfLedTotoggel; i--) {
    led[i] = CRGB(0,0,0);
    FastLED.show();
  }
}
