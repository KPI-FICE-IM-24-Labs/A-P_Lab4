#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);

String lastName = "YAKYMCHUK";

String line1 = "";
String line2 = "";

void setup()
{
  Serial.begin(9600);
  lcd.init();					
  lcd.clear();	
  lcd.backlight();
  
  for (int i = 0; i < lastName.length(); i++) {
    if (i % 2 == 0) {
      line1 += lastName[i];
      line2 += " ";
    } else {
      line2 += lastName[i];
      line1 += " ";
    }
  }
  
  lcd.setCursor(3, 0);
  lcd.print(line1);
  
  lcd.setCursor(3, 1);
  lcd.print(line2);
}

void loop() {

}