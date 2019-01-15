
// NeoPixel Ring simple sketch (c) 2013 Shae Erisson
// released under the GPLv3 license to match the rest of the AdaFruit NeoPixel library

#include <Adafruit_NeoPixel.h>
#include <ArduinoSTL.h>
#ifdef __AVR__
  #include <avr/power.h>
#endif

// Which pin on the Arduino is connected to the NeoPixels?
// On a Trinket or Gemma we suggest changing this to 1
#define PIN            3


// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS      150

// When we setup the NeoPixel library, we tell it how many pixels, and which pin to use to send signals.
// Note that for older NeoPixel strips you might need to change the third parameter--see the strandtest
// example for more information on possible values.
Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 5; // delay for half a second
int soundValue;
int firstrow = 0;
int secondrow = 25;
int thirdrow = 50;
int fourthrow = 75;
int fifthrow = 100;
int sixthrow = 125;

void setup() {
  Serial.begin(9600);

  pixels.begin(); // This initializes the NeoPixel library.

}

void loop() {

  // For a set of NeoPixels the first NeoPixel is 0, second is 1, all the way up to the count of pixels minus one.
  int readValue = analogRead(A0);
  Serial.println(readValue);
  soundValue = 0;
  for (int k = 0; k <= readValue; k++){
    if (k%14 == 0){
      if (soundValue < 25){
        soundValue++;
      }
    }

  }


  for(int i=0;i < soundValue;i++){
    pixels.setPixelColor(firstrow + i, pixels.Color(0,200,200));// Moderately bright green color.
    pixels.setPixelColor(secondrow + i, pixels.Color(0,0,200));
    pixels.setPixelColor(thirdrow + i, pixels.Color(200,200,0));
    pixels.setPixelColor(fourthrow + i, pixels.Color(200,0,0));
    pixels.setPixelColor(fifthrow + i, pixels.Color(200,0,200));
    pixels.setPixelColor(sixthrow + i, pixels.Color(200,200,60));
    pixels.show(); // This sends the updated pixel color to the hardware.
    delay(100);

  }
  delay(500);
  for (int j = 0; j < soundValue; j++){
      pixels.setPixelColor(24 - j, pixels.Color(0, 0, 0));
      pixels.setPixelColor(49 - j, pixels.Color(0, 0, 0));
      pixels.setPixelColor(74 - j, pixels.Color(0, 0, 0));
      pixels.setPixelColor(99 - j, pixels.Color(0, 0, 0));
      pixels.setPixelColor(124 - j, pixels.Color(0, 0, 0));
      pixels.setPixelColor(150 - j, pixels.Color(0, 0, 0));
      pixels.show();
      delay(100);
    }
  delay(200);

}
