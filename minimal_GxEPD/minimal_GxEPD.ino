
#include <GxEPD.h>
#include <GxGDEW042T2/GxGDEW042T2.h>      // 4.2" b/w
#include <GxIO/GxIO_SPI/GxIO_SPI.h>
#include <GxIO/GxIO.h>
#include "alberteinstein.h"

GxIO_Class io(SPI, /*CS=*/ 22, /*DC=*/ 15, /*RST=*/ 13);
GxEPD_Class display(io, /*RST=*/ 13, /*BUSY=*/ 34);

void setup()
{
  pinMode(12, OUTPUT);
  
  // Enable power to EPD
  digitalWrite(12, LOW);
  Serial.begin(115200);
  Serial.println();
  Serial.println("setup");

  display.init(115200); // enable diagnostic output on Serial
  display.setRotation(0);
  Serial.println("Setup done");

  display.fillScreen(GxEPD_WHITE);
  display.drawBitmap(gImage_alberteinstein, 0, 0, 400, 300, GxEPD_BLACK);
  display.update();

  // Disable power to EPD
  digitalWrite(12, HIGH);
}

void loop()
{
  // Nothing here  
}
