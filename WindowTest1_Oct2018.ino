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
typedef enum WindowEnum {topFull, topLeft, topRight, Left, Right, Player1, Player2} WindowEnum;
WindowEnum windowNumber = topFull; // topFull, topLeft topRight Left Right Player1 Player 2
int windowEfxCount = 0;
int smallChange = 5;
int allEfx = 15;
int windowChangeEfxMax = smallChange; // number of times we change efx for each window

int startEfxNumOrRandom = -1;

void setup() {
  Serial.begin(115200);
  delay(500); // wait half sec to open serial monitor window
  Serial.println("Starting gameShow led test one in sequence");

  setupNeoPix();
//  startupBlinks();
  allOff();

  windowNumber = topLeft;
  setTestWindow(topLeftWindow,0);

 Serial.println("startup complete, now loop");
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

  if (updateTestWindow()) 
  {
    // update changed the effect
    windowEfxCount++;
    if (windowEfxCount >= windowChangeEfxMax) 
    {
      switchWindows();
    }
  }
  
  showAllStrip();
}

void switchWindows()
{
    // done enough on this window, do next one
  Serial.print("Switch Windows was doing ");Serial.print(windowNumber);
  clearTestWindow();
  // select new test window
  switch(windowNumber)
  {
    case topFull:
      windowNumber = topLeft;
      setTestWindow(topLeftWindow,startEfxNumOrRandom);
      break;
    case topLeft:
      windowNumber = topRight;
      setTestWindow(topRightWindow,startEfxNumOrRandom);
    case topRight:
      windowNumber = Left;
      setTestWindow(leftWindow,startEfxNumOrRandom);
    case Left:
      windowNumber = Right;
      setTestWindow(rightWindow,startEfxNumOrRandom);
    case Right:
      windowNumber = Player1;
      setTestWindow(player1Ring,startEfxNumOrRandom);
    case Player1:
      windowNumber = Player2;
      setTestWindow(player2Ring,startEfxNumOrRandom);
    case Player2:
    default:
      windowNumber = topFull;
      setTestWindow(topFullWindow,startEfxNumOrRandom);
  }
  Serial.print("now doing "); Serial.println(windowNumber);
}
