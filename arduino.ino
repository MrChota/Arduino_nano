//included libraries for arduino and oled screen 
//software id serial library
#include <Wire.h>
#include <SimpleDHT.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SH1106.h>
#include <SoftwareSerial.h>

#define OLED_RESET -1
Adafruit_SH1106 display(OLED_RESET);

int pinDHT11 = 2;

SimpleDHT11 dht11;

byte temperature = 0;
byte humidity = 0;
byte data[40] = {0};

void setup() {

   Serial.begin(9600);

   //start up display
   display.begin(SH1106_SWITCHCAPVCC,0x3C);
   
   display.clearDisplay();
   display.setTextSize(1);

  //bluetooth

  //pulse sensor
  
   
  //heat sensor
  if (dht11.read(pinDHT11, &temperature, &humidity, data)) {
    display.print("Read DHT11 failed");
    return;
  }
}

void loop() {
  display.clearDisplay();

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,0.5);
  display.print("now" );

 /*time and date display on oled*/
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(50,0);
  display.print("09 : 43 PM");

  
  display.setTextSize(2);
  display.setTextColor(WHITE);
  display.setCursor(90,30);
  display.print("*O*");

  /*temperature sensor display on oled*/
  dht11.read(pinDHT11, &temperature, &humidity, data);
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,15);
  display.print("Temp  : ");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(50,15);
  display.print(temperature);
  display.println("   C");

 /*humidity sensor display on oled*/
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,25);
  display.print("Hum   : ");
  
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(50,25);
  display.print(humidity);
  display.println("   %");

  
 /*pulse sensor display on oled*/
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0,35);
  display.print("Pulse : ");

  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(45,35);
  display.print("38");
  
 /*test results display on oled*/
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(30,55);
  display.print("Results : + ");
  
  display.display();
}
