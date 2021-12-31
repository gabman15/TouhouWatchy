#include "Touhou_Watchy.h"
#include <stdlib.h>     //srand, rand

//Ratfink Artsheet 


TouhouWatchy::TouhouWatchy(){} //constructor

void TouhouWatchy::drawWatchFace(){
  display.fillScreen(GxEPD_BLACK);
  display.drawBitmap(0, 0, cirno, 170, DISPLAY_HEIGHT, GxEPD_WHITE);
  drawTime();
  drawDateAndSteps();

}

/*void TouhouWatchy::handleButtonPress() {
  display.fillRect(0,0,10,10, GxEPD_WHITE);
  uint64_t wakeupBit = esp_sleep_get_ext1_wakeup_status();
  //if ((wakeupBit & (UP_BTN_MASK | DOWN_BTN_MASK)) == (UP_BTN_MASK | DOWN_BTN_MASK))
  if (wakeupBit & BACK_BTN_MASK)
    sensor.resetStepCounter();
  //Watchy::handleButtonPress();
}*/

void TouhouWatchy::drawTime() {
  display.setFont(&LcdSolid27pt7b);
  display.setCursor(127, 27+20);
  int displayHour;
  if(HOUR_12_24==12){
    displayHour = ((currentTime.Hour+11)%12)+1;
  } else {
    displayHour = currentTime.Hour;
  }
  if(displayHour < 10){
    display.print("0");
  }
  display.print(displayHour);
  display.setCursor(127,27+20+43);
  if(currentTime.Minute < 10){
    display.print("0");
  }  
  display.println(currentTime.Minute);  
}

void TouhouWatchy::drawDateAndSteps(){
  int16_t lasty = 200 - 16;
  
  display.setFont(&DIN_1451_Engschrift_Regular12pt7b);

  drawSteps(&lasty);

  drawDate(&lasty);
  
}

void TouhouWatchy::drawSteps(int16_t* lasty) {
  int16_t x1,y1;
  uint16_t w,h;
  String textstring;
  textstring = sensor.getCounter();
  textstring += " steps";
  display.getTextBounds(textstring, 75, 0, &x1, &y1, &w, &h);
  display.fillRoundRect(200-w-13, *lasty-h-2,w + 7,h+4,2,GxEPD_WHITE);
  display.setCursor(200-w-10, *lasty-3);
  display.setTextColor(GxEPD_BLACK);
  display.print(textstring);
  display.setTextColor(GxEPD_WHITE);
  *lasty += -8-h;
}

void TouhouWatchy::drawDate(int16_t* lasty) {
  int16_t x1,y1;
  uint16_t w,h;
  
  String textstring;

  // draw day
  textstring = dayStr(currentTime.Wday);
  display.getTextBounds(textstring, 75, 0, &x1, &y1, &w, &h);
  display.setCursor(200-w-10, *lasty);
  display.print(textstring);
  *lasty += -20;

  // draw year
  textstring = currentTime.Year + YEAR_OFFSET;
  display.getTextBounds(textstring, 75, 0, &x1, &y1, &w, &h);
  display.setCursor(200-w-10, *lasty);
  display.print(textstring);
  *lasty += -20;

  // draw date
  textstring = monthShortStr(currentTime.Month);
  textstring += " ";
  textstring += currentTime.Day;
  display.getTextBounds(textstring, 125, 0, &x1, &y1, &w, &h);
  display.setCursor(200-w-10, *lasty);
  display.print(textstring);
  *lasty += -40;
}
