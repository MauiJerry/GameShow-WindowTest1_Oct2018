////////////////////////
// game show window code module test
////////////////////////
// some globals
int topFullCount = 0,
    topLeftCount = 0,
    topRightCount = 0,
    rightCount =0,
    leftCount = 0;

////////////////////////
// separate window functions

void  setInitialWindows()
{
  topFullWindow.fillColor(GREEN );
  topFullWindow.setHoldEfx(2000);
  
  topLeftWindow.setNoEfx();
  topRightWindow.setNoEfx();
  
  leftWindow.setSolidColorEfx(RED ,2000);

  rightWindow.setSolidColorEfx(BLUE ,2000);
}

void topFullWindowUpdate()
{
    // change window effects?
  if (topFullWindow.effectDone())
  {
    topFullCount++;
    topFullWindow.setNoEfx();
  }
  topFullWindow.updateWindow();
}

void topLeftWindowUpdate()
{
  int delayTime = random(100,500);
  int count = random(5,10);
  if (topLeftWindow.effectDone())
  {
    topLeftCount++;
    switch (topLeftCount)
    {
      case 0:
        topRightWindow.setSolidColorEfx(topStrip.randomColor(),2000);
        break;
      case 1:
         topLeftWindow.setSparkleEfx(topStrip.randomColor(), delayTime, delayTime/2, count);
       break;
      case 2:
         topLeftWindow.setMultiSparkleEfx(topStrip.randomColor(), 
             delayTime/2, delayTime, topLeftWindow.getNumPixels()/5, count);
       break;
      case 3:
        topLeftWindow.setRainbowEfx(delayTime, 1, count);
        break;
      default:
        topLeftWindow.setWipeEfx(topStrip.randomColor(), delayTime, count );
        topLeftCount = -1;
    }
  }
  topLeftWindow.updateWindow();
}

void topRightWindowUpdate()
{
  int delayTime = random(100,500);
  int count = random(5,10);
  if (topRightWindow.effectDone())
  {
    topRightCount++;
    switch (topRightCount)
    {
      case 0:
        topRightWindow.setSolidColorEfx(topStrip.randomColor() ,2000);
        break;
      case 1:
         topRightWindow.setDazzleEfx( delayTime, 50, count);
       break;
      case 2:
        topRightWindow.setFadeEfx(0, topStrip.randomColor(), delayTime, topRightWindow.fadeTypeCycle, count );
       break;
      case 3:
         topRightWindow.setMultiSparkleEfx(topStrip.randomColor(), delayTime/2, delayTime, topRightWindow.getNumPixels()/5, count);
        break;
      default:
        topRightWindow.setRainbowEfx(delayTime, 1, count);
        topRightCount = -1;
    }
  }
   topRightWindow.updateWindow();
}

void leftWindowUpdate()
{
  int delayTime = random(100,500);
  int count = random(5,10);
  if (leftWindow.effectDone())
  {
    leftCount++;
    switch (leftCount)
    {
      case 0:
        leftWindow.setSolidColorEfx(RED ,2000);
        break;
      case 1:
        leftWindow.setFadeEfx(0, topStrip.randomColor(), delayTime, leftWindow.fadeTypeCycle, count );
       break;
      case 2:
         leftWindow.setCircleEfx(leftStrip.randomColor(), delayTime, count,0);
      break;
      case 3:
         leftWindow.setDazzleEfx(delayTime, 50, count);
        break;
      default:
        leftWindow.setSolidColorEfx(topStrip.randomColor() ,2000);
        leftCount = -1;
    }
  }
  leftWindow.updateWindow();
}

void rightWindowUpdate()
{
   int delayTime = random(100,500);
  int count = random(5,10);
  if (rightWindow.effectDone())
  {
    rightCount++;
    switch (rightCount)
    {
      case 0:
        rightWindow.setSolidColorEfx(BLUE ,2000);
        break;
      case 1:
        rightWindow.setFadeEfx(0, topStrip.randomColor(), delayTime, rightWindow.fadeTypeCycle, count );
       break;
      case 2:
         rightWindow.setCircleEfx(leftStrip.randomColor(), delayTime, count,0);
      break;
      case 3:
         rightWindow.setDazzleEfx(delayTime, 50, count);
        break;
      default:
        rightWindow.setSolidColorEfx(topStrip.randomColor() ,2000);
        rightCount = -1;
    }
  }
  rightWindow.updateWindow();
}

////////////////////////
// parameterized test
int defaultEfxCount = 5;
#define DEFAULT_DELAYTIME 60
int windowStartEfxNum = 0;

NeoWindow &currWindow = topFullWindow;
extern void setCurrWindowRandomEfx();

NeoStrip *currStrip = NULL;
int startEfxNum =0;
int curWindowEffectNum = startEfxNum;

void setTestWindow(NeoWindow window, int efxNum)
{
  currWindow = window;
  if (startEfxNum < 0)
    setCurrWindowRandomEfx();
  else
    setCurrWindowEfx(startEfxNum);
  currStrip = window.getStrip();
}

void clearTestWindow()
{
  currWindow.setNoEfx();
  currWindow.fillBlack();
}

boolean updateTestWindow()
{
  boolean changeEfx = currWindow.effectDone();
  if (changeEfx)
  {
    setCurrWindowRandomEfx();
    if (startEfxNum < 0)
      setCurrWindowRandomEfx();
    else
      setCurrWindowEfx(++curWindowEffectNum);
  }
  currWindow.updateWindow();
  return changeEfx;
}

void setCurrWindowRandomEfx()
{
  int randomEffect = random(0,14);
  setCurrWindowEfx(randomEffect);
}

void setCurrWindowEfx(int windowEffectNum)
{
  int effectCount = defaultEfxCount; // changes per effect
  int delayTime = DEFAULT_DELAYTIME; // default is 1/4sec each step
  uint32_t randomColor = NeoStrip::randomColor();
  uint32_t randomColor2 = NeoStrip::randomColor();

  Serial.print("new window Effect:");Serial.print(windowEffectNum);
  switch (windowEffectNum) {
    //1 = SolidColorEfx
    // 2 = circle fwd
    // 3 = circle rev
    // 4 = wipe
    // 5 = randomWipe
    // 6 = reverseWipe
    // 7 = Blink
    // 8 = sparkle
    // 9 = MultiSparkle
    // 10 = Fade Once
    // 11 = Fade Cycle
    // 12 = Fade Jump
    // 13 = rainbow 255 len
    // 14 = rainbow even distrb
    // 15 = dazzle
    case 1:
      Serial.println(" Solid BLUE hold 5 sec");
      delayTime = 5000;
      currWindow.setSolidColorEfx(BLUE, delayTime);
      break;
    case 2:
    {
      //delayTime = 100;
      //effectCount = 3;
      Serial.print (" Circle fwd ");Serial.println(randomColor);
      currWindow.setCircleEfx(randomColor, delayTime, effectCount,0);
      break;
    }
    case 3:
      Serial.println(" Circle rev");
      delayTime = 100;
      effectCount = 3;
      currWindow.setCircleEfx(randomColor, delayTime, effectCount, 1);
      break;
   case 4:
      Serial.println(" WipeEfx");
      currWindow.setWipeEfx(randomColor, delayTime, effectCount );
      break;
   case 5:
      Serial.println(" randomWipeEfx");
      // no effect count?
      currWindow.setRandomWipeEfx(randomColor, randomColor2, delayTime );
      break;
   case 6:
      Serial.println(" reverseWipe");
      currWindow.setReverseWipeEfx(randomColor, delayTime, effectCount );
      break;
   case 7:
      Serial.println(" Blink");
      effectCount = 10;
      currWindow.setBlinkEfx(randomColor, delayTime, effectCount);
      break;
   case 8:
      Serial.println(" Sparkle");
      effectCount = 20;
      currWindow.setSparkleEfx(BLUE, delayTime, delayTime/2, 50);
      break;
   case 9:
      Serial.println(" MultiSparkle");
      effectCount = 20;
      currWindow.setMultiSparkleEfx(randomColor, delayTime/2, delayTime, currWindow.getNumPixels()/5, 50);
      break;
  case 10:
      Serial.println(" Fade Once");
      currWindow.setFadeEfx(0, randomColor, 10, currWindow.fadeTypeOnce, effectCount); // fade between two colors
      break;
  case 11:
      Serial.println(" Fade Cycle");
      //effectCount = 2; // default = once
      currWindow.setFadeEfx(0, randomColor, 10, currWindow.fadeTypeCycle, effectCount); // fade between two colors
      break;
  case 12:
      Serial.println(" Fade JumpBack");
      effectCount = 2; // default = once
      currWindow.setFadeEfx(0, randomColor, 10, currWindow.fadeTypeJumpBack, effectCount); // fade between two colors
      break;
  case 13:
      Serial.println(" Rainbow 255 len");
      currWindow.setRainbowEfx(delayTime, 0, effectCount);
      break;
  case 14:
      Serial.println(" Rainbow even distrib");
      Serial.println(" Rainbow 255 len");
      currWindow.setRainbowEfx(delayTime, 1, effectCount);
      break;
  case 15:
    currWindow.setDazzleEfx( delayTime, 50, 50);
    break;
  default: // black for sanity
    // when windowEffectNum increments past highest case above, it falls into state = 0
      Serial.println(" DEFAULT = black hold 5sec");
      windowEffectNum = windowStartEfxNum;
      currWindow.fillBlack( );
      currWindow.setHoldEfx(5000);
  }
}
