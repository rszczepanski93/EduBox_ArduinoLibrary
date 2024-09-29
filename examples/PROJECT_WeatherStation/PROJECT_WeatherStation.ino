#include <EduBox.h>

EduBox eduBox;

void setup() {
  eduBox.begin();
}

void loop() {
  float temperature = eduBox.eduTemprature_GetTemperature();
  float humidity = eduBox.eduTemprature_GetHumidity();
  
  eduBox.edu7Segment_DisplayNumber(temperature, false);
  eduBox.edu7Segment_DisplayNumber(humidity, true);

  delay(500);
}

