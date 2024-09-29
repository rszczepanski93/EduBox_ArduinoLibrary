#include <EduBox.h>

EduBox eduBox;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
}

void loop() {
  float distanceCentimeters = eduBox.eduDistance_GetDistanceCentimeters();
  
  Serial.print("Distance = ");
  Serial.print(distanceCentimeters);
  Serial.print(" cm");
  Serial.println();

  delay(250);
}

