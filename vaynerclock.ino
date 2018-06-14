#include "RTClib.h"
#include "U8glib.h"

// General variables
const int TIME_TO_SLEEP = 23; // time that you go to sleep (24-hour format)
String time_left; // calculated time left for the day
RTC_DS3231 rtc;
U8GLIB_PCD8544 u8g(8, 4, 7, 5, 6); // 5110 connections to Arduino UNO

// Initial setup for 5110 and RTC
void setup() {
  Serial.begin(9600);
  setupRtc(); 
//  setTime(2018, 6, 13, 19, 45, 0);
  u8g.setFont(u8g_font_fur42n);
  u8g.setColorIndex(1);
}

void loop() {
  u8g.firstPage();  
  do {
    draw();
  } while(u8g.nextPage());
  delay(1000);   
  printTime();
}

// Method that prints the time_left on 5110
void draw() {
  // alignment of display screen
  int row = 27;
  int col = 45;
  if (time_left.length() > 1) {
      row = 10;
  }
  u8g.drawStr(row, col, time_left.c_str());
}

// Starts the RTC
void setupRtc() {
  if (!rtc.begin()) {
    Serial.println("Couldn't find RTC");
    while (1);
  }
}

// Sets the RTC time (to be called once)
void setTime(int y, int m, int d, int h, int i, int s) {
  Serial.println("Setting time");
  rtc.adjust(DateTime(y, m, d, h, i, s));
}

//Calculate the time to be displayed
void printTime() {
  DateTime now = rtc.now();
  time_left = String(TIME_TO_SLEEP-now.hour());
}
 
