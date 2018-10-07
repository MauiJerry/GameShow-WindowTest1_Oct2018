/*
//   test rig for GameShowFantatics
// Test neo windows, 
 */

#include "gameNeoPix.h"
#include "gameButtons.h"

#define FULLON 254      //for NeoPixels
uint32_t
  BLUE = Adafruit_NeoPixel::Color(0, 0, FULLON),
  WHITE = Adafruit_NeoPixel::Color(FULLON, FULLON, FULLON, FULLON),
  RED = Adafruit_NeoPixel::Color(FULLON, 0, 0),
  GREEN = Adafruit_NeoPixel::Color(0, FULLON, 0),
  YELLOW = Adafruit_NeoPixel::Color(FULLON, FULLON, 0),
  BROWN = Adafruit_NeoPixel::Color(165, 42, 0),
  ORANGE = Adafruit_NeoPixel::Color(FULLON, 128, 0);

////////////////////////////////////

void setup() {
  Serial.begin(115200);
  delay(500); // wait half sec to open serial monitor window
  Serial.println("Starting gameShow led test one in sequence");

  setupNeoPix();
//  startupBlinks();
  allOff();

 Serial.println("startup complete, now loop");
 setInitialWindows();
 showAllStrip();
}


void loop()
{
  // Basic NeoEffects loop:
  // update time
  // check inputs & effectsDone - change behavior as needed
  // update each active Window
  // show the strips
  NeoWindow::updateTime();

  topFullWindowUpdate();
  topLeftWindowUpdate();
  topRightWindowUpdate();

  rightWindowUpdate();
  leftWindowUpdate();
  
  showAllStrip();
}
