#include <EduBox.h>

EduBox eduBox;

void setup() {
  eduBox.begin();
}

void loop() {
  eduBox.eduServo_SetPosition(0);
  delay(2000);
  eduBox.eduServo_SetPosition(90);
  delay(2000);
  eduBox.eduServo_SetPosition(180);
  delay(2000);
}

