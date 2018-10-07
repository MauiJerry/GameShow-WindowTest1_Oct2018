int topFullCount = 0,
    topLeftCount = 0,
    topRightCount = 0,
    rightCount =0,
    leftCount = 0;

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
