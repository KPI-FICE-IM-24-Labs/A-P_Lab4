#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

const int SCREEN_WIDTH = 128;
const int SCREEN_HEIGHT = 64;

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

boolean showName = true;

const int POT = A0;

#define GRAPH_WIDTH 128
int graphValues[GRAPH_WIDTH] = {0};

void setup() {
  Serial.begin(9600);

  pinMode(POT, INPUT);

  if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
    Serial.println(F("SSD1306 allocation failed"));
    while(true);
  }

  display.clearDisplay();
  display.setTextSize(1);
  display.setTextColor(WHITE);
  display.setCursor(0, 0);
  display.println("YAKYMCHUK");
  display.display();
  delay(3000);
}

void loop() {
  int potValue = analogRead(POT);
  int mappedValue = map(potValue, 0, 1023, 0, SCREEN_HEIGHT - 1);

  Serial.println(mappedValue);
  
  for(int i = 0; i < GRAPH_WIDTH - 1; i++) {
    graphValues[i] = graphValues[i + 1];
  }
  graphValues[GRAPH_WIDTH - 1] = mappedValue;
  
  display.clearDisplay();
  
  for(int x = 0; x < GRAPH_WIDTH - 1; x++) {
    display.drawLine(x, SCREEN_HEIGHT - graphValues[x], x+1, SCREEN_HEIGHT - graphValues[x+1], WHITE);
  }

  display.display();

  delay(50);
}
