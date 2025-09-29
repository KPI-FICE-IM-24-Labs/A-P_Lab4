#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);

String lastName = "YAKYMCHUK";

byte YA[8] = {
  B00111,
  B01001,
  B01001,
  B00101,
  B00111,
  B01101,
  B11001,
  B10001,
};

byte K[8] = {
  B10001,
  B10010,
  B10100,
  B11000,
  B10100,
  B10010,
  B10010,
  B10001,
};

byte I[8] = {
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
  B00100,
};

byte M[8] = {
  B10001,
  B11011,
  B10101,
  B10101,
  B10001,
  B10001,
  B10001,
  B10001,
};

byte CH[8] = {
  B10001,
  B10001,
  B10001,
  B11111,
  B00001,
  B00001,
  B00001,
  B00001,
};

byte U[8] = {
  B10001,
  B10001,
  B01001,
  B00110,
  B00010,
  B00100,
  B01000,
  B10000,
};

void setup()
{
  Serial.begin(9600);
  lcd.init();					
  lcd.clear();	
  lcd.backlight();
  
  lcd.createChar(0, YA);
  lcd.createChar(1, K);
  lcd.createChar(2, I);
  lcd.createChar(3, M);
  lcd.createChar(4, CH);
  lcd.createChar(5, U);
  
  lcd.setCursor(4, 1);
  lcd.write(byte(0));
  lcd.write(byte(1));
  lcd.write(byte(2));
  lcd.write(byte(3));
  lcd.write(byte(4));
  lcd.write(byte(5));
  lcd.write(byte(1));
}

void loop() {

}