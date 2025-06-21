
#include <TinyWireM.h>
#include <Tiny4kOLED.h>
#include <dht.h>

#define DHT_PIN 1 // DHT11 connected to PB1 (physical pin 6)
dht DHT;

void setup() {
  // OLED setup
  oled.begin();
  oled.clear();
  oled.on();
  oled.setFont(FONT8X16);

  // Intro message
  oled.setCursor(0, 0);
  oled.print(F("WeatherBadge"));
  oled.setCursor(0, 2);
  oled.print(F("Starting..."));
  delay(2000);
  oled.clear();
}

void loop() {
  // Read temperature
  int chk = DHT.read11(DHT_PIN);
  float temp = DHT.temperature;

  // Display message with temp
  oled.clear();
  oled.setCursor(0, 0);
  oled.print(F("Hello Ankit!"));

  oled.setCursor(0, 2);
  oled.print(F("Temp: "));
  oled.print(temp);
  oled.print(F(" C"));

  // Scroll message loop
  for (int i = 0; i < 128; i++) {
    oled.scrollLeft();
    delay(50);
  }

  delay(3000); // Wait 3 seconds before reading again
}
