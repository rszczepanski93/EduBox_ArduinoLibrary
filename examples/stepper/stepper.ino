#include <EduBox.h>

#include <EduBox.h>

EduBox eduBox;
Test321 test;

int _5s_counter = 0;
float speed = 0.1;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
  delay(100);
}

void loop() {
  _5s_counter++;
  if (_5s_counter > 5000 / 100) {
    _5s_counter = 0;
    speed *= -1.0;
  }

  eduBox.eduStepperMotr_SetSpeed(speed);

  float position = eduBox.eduStepperMotr_GetPosition();

  Serial.println("Speed = ");
  Serial.println(speed);
  Serial.println(" Position = ");
  Serial.println(position);
  Serial.println();

  delay(100);
}
