
#include <LiquidCrystal_I2C.h>
#include <Wire.h> //SDA y SCL

LiquidCrystal_I2C lcd(0x27, 2, 1, 0, 4, 5, 6, 7, 3, POSITIVE);

void setup() {
  
  Serial.begin(9600);
  lcd.begin(20, 4);
  lcd.backlight();
  Serial.print();
  
}

void loop() {
  lcd.setCursor(5, 0);
  lcd.print("CUCUMARI");
  lcd.setCursor(1, 1);
  lcd.print("INSTITUTO ISMAC");
  delay(1000);
}
