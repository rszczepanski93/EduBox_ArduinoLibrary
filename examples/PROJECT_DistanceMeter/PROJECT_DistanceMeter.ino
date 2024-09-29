#include <EduBox.h>

EduBox eduBox;

void setup() {
  eduBox.begin();
}

void loop() {
  float distanceCentimeters = eduBox.eduDistance_GetDistanceCentimeters();
  
  eduBox.edu7Segment_DisplayNumber(distanceCentimeters);

  delay(250);
}

