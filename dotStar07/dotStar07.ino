// Backlog
/*
 * Make the flashers be part of an array so that I can work through them and detect when collisions occur and add colours together 
 * 
 */

#define NUMPIXELS 21 // Number of LEDs in strip

#include <Adafruit_DotStar.h>
// Because conditional #includes don't work w/Arduino sketches...
#include <SPI.h>         // COMMENT OUT THIS LINE FOR GEMMA OR TRINKET

#include "Flasher.h" // Written by PBS 
 
// Here's how to control the LEDs from any two pins:
#define DATAPIN    4
#define CLOCKPIN   5
Adafruit_DotStar strip = Adafruit_DotStar(
  NUMPIXELS, DATAPIN, CLOCKPIN);
// The last parameter is optional -- this is the color data order of the
// DotStar strip, which has changed over time in different production runs.
// Your code just uses R,G,B colors, the library then reassigns as needed.
// Default is DOTSTAR_BRG, so change this if you have an earlier strip.

// Hardware SPI is a little faster, but must be wired to specific pins
// (Arduino Uno = pin 11 for data, 13 for clock, other boards are different).
//Adafruit_DotStar strip = Adafruit_DotStar(NUMPIXELS, DOTSTAR_BRG);

// Flasher flasher01("flasher01", 10, 240, 0x111111); // name, length, speed, colour
// Flasher flasher02("flasher02", 1, 50, 0x001100); // name, length, speed, colour
// Flasher flasher03("flasher03", 1, 60, 0x000011); // name, length, speed, colour
// Flasher flasher04("flasher04", 1, 70, 0x111100); // name, length, speed, colour
// Flasher flasher05("flasher05", 1, 80, 0x001111); // name, length, speed, colour
// Flasher flasher06("flasher06", 3, 200, 0x110011); // name, length, speed, colour
// Flasher flasher07("flasher07", 4, 250, 0x030300); // name, length, speed, colour

Flasher flasher01("flasher04", 250, NUMPIXELS, 0xff0000); // name, length, speed, colour


void setup() {

  Serial.begin(250000);
  delay(1000);
  Serial.println("Hi There. dotStar06");
//  Serial.println(flasher01.getFlashTailPosition());
  
  strip.begin(); // Initialize pins for output
  strip.show();  // Turn all LEDs off ASAP
}

// Runs 10 LEDs at a time along strip, cycling through red, green and blue.
// This requires about 200 mA for all the 'on' pixels + 1 mA per 'off' pixel.


void loop() {
 
// flasher01.moveFlasher(); //Move the object
//  flasher02.moveFlasher(); //Move the object
//  flasher03.moveFlasher(); //Move the object  
  flasher01.moveFlasher(); //Move the object

  strip.show();                     // Refresh strip



}
