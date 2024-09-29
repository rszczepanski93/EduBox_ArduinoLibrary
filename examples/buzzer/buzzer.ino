#include <EduBox.h>

EduBox eduBox;

void setup() {
  eduBox.begin();
}

void loop() {
  eduBox.eduBuzzer_TurnOn();
  delay(100);
  eduBox.eduBuzzer_TurnOff();
  delay(1000);
}

