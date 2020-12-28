/*
 Small script to test my LED-strip (WS2812B) with 300LEDs
 Since I'm still waiting for batterie cases to power the strip, 
 I had to power it using only my Arduino Uno Board. 
 That's why by using this script there are never more than
 two LEDs switched ON. 
 */



#include <Adafruit_NeoPixel.h>

#define LED_PIN    6
#define LED_COUNT 300

Adafruit_NeoPixel strip(LED_COUNT, LED_PIN, NEO_GRB + NEO_KHZ800);

void setup() {

  strip.begin();           // initialise NeoPixel strip object
  strip.show();            // Turn OFF all pixels ASAP
  strip.setBrightness(50); // Set BRIGHTNESS to about 1/5 (max = 255)
}


void loop() {
  colorWipe(strip.Color(0,  255,   0), 50); // Green
  colorWipe(strip.Color(255, 0, 0), 50); //Red
  colorWipe(strip.Color(  0,   0, 255), 50); // Blue

}



void colorWipe(uint32_t color, int wait) {
  for(int i=0; i<strip.numPixels(); i++) { 
    strip.setPixelColor(i, color);        
    int k = i + (strip.numPixels() / 2);
    if(k >=strip.numPixels()){
      k = k-strip.numPixels();
    }
    strip.setPixelColor(k, color);
    
    strip.show();                         
    delay(wait);
    strip.clear();
  }
}
