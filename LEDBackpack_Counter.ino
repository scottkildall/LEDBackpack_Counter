 /*
  LEDBackpack_Counter
  by Scott Kildall
  Janaury 3, 2017
  
  A very simple Arudino sketch that uses the Adafruit LED backpack. This sketch like the Blink test sketch that I use to make sure their LED display is working correctly.

  Their GitHub repo is here
  https://github.com/adafruit/Adafruit_LED_Backpack

  Download it and put it in your libraries folder
*/


#include "Adafruit_LEDBackpack.h"

Adafruit_7segment matrix = Adafruit_7segment();

int blinkCount = 0;
int delayTime = 5;

// the setup function runs once when you press reset or power the board
void setup() {
  matrix.begin(0x70);
  matrix.print(blinkCount, DEC);
  matrix.writeDisplay();
}

// the loop function runs over and over again forever
void loop() {   
  // update blink count, when overflow, reset to zero
  blinkCount++;
  if( blinkCount > 9999 )
    blinkCount = 0;

  // update display on the backpack
  matrix.print(blinkCount, DEC);
  matrix.writeDisplay();

  delay(5);
}
