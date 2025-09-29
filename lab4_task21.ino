#include <LiquidCrystal_I2C.h>

LiquidCrystal_I2C lcd(0x26, 16, 2);

int val;
int TEMP = A0;

void setup()
{
  Serial.begin(9600);
  lcd.init();					
  lcd.clear();	
  lcd.backlight();
}

void loop() {  
  val = analogRead(TEMP);
  float mv = (val / 1023.0) * 5;
  float cel = (mv - 0.5) * 100;
  float farh = (cel * 9) / 5 + 32;
  
  lcd.setCursor(0, 0);
  lcd.print(String(cel) + "*C");
  
  lcd.setCursor(0, 1);
  lcd.print(String(farh) + "*F");

  delay(500);
}