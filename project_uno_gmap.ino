#include <SoftwareSerial.h>
#include <TinyGPS.h>
#include <Adafruit_SSD1306.h>
#include <Adafruit_GFX.h>
#include <Wire.h>
#include <SPI.h>

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET 4

void drawHeader();

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);
SoftwareSerial ss(3, 2);
TinyGPS gps;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)){
      Serial.print("SSD1306 allocation failed"); while(true){}
  } 
}

void loop() {
  // put your main code here, to run repeatedly:
  display.clearDisplay();
  drawHeader();
}

void drawHeader(){
  display.setTextColor(WHITE);
  display.setTextSize(1);
  display.setCursor(0, 0);
  display.print("Time: ");

  display.drawCircle(50, 5, 5, WHITE);
  display.drawLine(48, 5, 52, 5, WHITE);
  display.drawLine(50, 3, 50, 7, WHITE);
  display.display();
}
