#include <FastLED.h>

#define NUM_LEDS 43
#define DATA_PIN 6
CRGB leds[NUM_LEDS];

const int daylightButton = 2; //This will be to as buttonStateOne for logic
const int nighttimeButton = 3; //This will be buttonStateTwo
const int onButton = 4; //buttonStateThree
const int offButton = 5; //buttonStateFour

int buttonStateOne = 0;
int buttonStateTwo = 0;
int buttonStateThree = 0;
int buttonStateFour = 0;

void setup() {
  
pinMode (DATA_PIN, OUTPUT); 
FastLED.addLeds<WS2812B, DATA_PIN>(leds, NUM_LEDS); 

pinMode (daylightButton, INPUT_PULLUP);
pinMode (nighttimeButton, INPUT_PULLUP);
pinMode (onButton, INPUT_PULLUP);
pinMode (offButton, INPUT_PULLUP);

}

void loop() {
buttonStateOne = digitalRead(daylightButton);
if (buttonStateOne == LOW){
 daylight();

}
if (buttonStateTwo == LOW){
 nightTime();
 }
if (buttonStateThree == LOW) {
  light();
 }
if (buttonStateFour == LOW) {
 off();
 }
}

void daylight(){
  static const uint8_t sunriseLength = 60; 
static const uint8_t interval = (sunriseLength * 60) / 256;

static uint8_t heatIndex = 0;
CRGB color = ColorFromPalette(HeatColors_p, heatIndex); 
fill_solid(leds, NUM_LEDS, color);
EVERY_N_SECONDS(interval) {
  if(heatIndex < 255) {
    heatIndex++;
  }
  if(heatIndex == 255){
    heatIndex = 0;
  }
}
}

void nightTime(){
static const uint8_t sunsetLength = 60; 
static const uint8_t interval = (sunsetLength * 60) / 256;

static uint8_t heatIndex = 0;
CRGB color = ColorFromPalette(HeatColors_p, heatIndex); 
fill_solid(leds, NUM_LEDS, color);
EVERY_N_SECONDS(interval) {
  if(heatIndex > 0) {
    heatIndex--;
  }
  if(heatIndex == 0){
    heatIndex = 255;
  }
}
}

void off(){
   
}

void light(){
  
}
