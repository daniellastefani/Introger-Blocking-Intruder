#define BLYNK_PRINT Serial
#include <ESP8266WiFi.h>
#include <BlynkSimpleEsp8266.h>
#include <LiquidCrystal_I2C.h>
#include <Wire.h>

char auth[] = "yourAuthToken";
char ssid[] = "yourWiFiName";
char pass[] = "yourWiFiPass";

LiquidCrystal_I2C lcd(0x27,16,2);


void setup() {
  lcd.init();
  lcd.backlight();
  Serial.begin(9600);
  Blynk.begin(auth,ssid,pass);
}

BLYNK_WRITE(V0){
  lcd.clear();
  String textIn = param.asStr();
  Serial.print(textIn + "\n");
  lcd.setCursor(0,0);
  lcd.print(textIn);
}

BLYNK_WRITE(V1){
  String textIn = param.asStr();
  Serial.print(textIn + "\n");
  lcd.setCursor(0,1);
  lcd.print(textIn);
}

void loop() {
  Blynk.run();
}
