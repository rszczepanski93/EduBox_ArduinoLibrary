#include <EduBox.h>

EduBox eduBox;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
}

void loop() {
  float left = eduBox.eduLineSensor_GetLeftSensorValue();
  float center = eduBox.eduLineSensor_GetCenterSensorValue();
  float right = eduBox.eduLineSensor_GetRightSensorValue();

  Serial.print("left: ");
  Serial.print(left);
  Serial.print(" center: ");
  Serial.print(center);
  Serial.print(" right: ");
  Serial.print(right);
  Serial.println();

  delay(250);
}

