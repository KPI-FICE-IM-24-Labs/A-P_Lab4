#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);

String firstName = "KIRIL           ";
String lastName = "YAKYMCHUK       ";


String scrollFirst = firstName + firstName;
String scrollLast  = lastName + lastName;

int offset = 0;

void setup()
{
  Serial.begin(9600);
  lcd.init();					
  lcd.clear();	
  lcd.backlight();
}

void loop() {
  lcd.setCursor(0, 0);
  lcd.print(scrollFirst.substring(offset, offset + 16));

  lcd.setCursor(0, 1);
  lcd.print(scrollLast.substring(offset, offset + 16));

  offset++;
  
  if (offset >= firstName.length()) offset = 0;

  delay(100);
}