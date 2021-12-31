#ifndef TOUHOU_WATCHY_H
#define TOUHOU_WATCHY_H

#include "Watchy.h"
#include <stdlib.h>
#include "DSEG7_Classic_Bold_25.h"
#include "DSEG7_Classic_Regular_39.h"
#include "DIN_1451_Engschrift_Regular12pt7b.h"
#include "Seven_Segment10pt7b.h"
#include "LcdSolid27pt7b.h"
#include "artsheet.h"

class TouhouWatchy : public Watchy{
  
public:
  TouhouWatchy();
  void drawWatchFace();
  void drawTime();
  void drawDateAndSteps();
  void drawDate(int16_t*);
  void drawSteps(int16_t*);
  void checkButtons();
  void handleButtonPress();
};

#endif
