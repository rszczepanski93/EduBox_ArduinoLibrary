#include <EduBox.h>

EduBox eduBox;

void setup() {
  eduBox.begin();
}

void loop() {
  eduBox.eduRGB_SetValues(25, 0, 0);
  delay(1000);
  eduBox.eduRGB_SetValues(0, 25, 0);
  delay(1000);
  eduBox.eduRGB_SetValues(0, 0, 25);
  delay(1000);
}

