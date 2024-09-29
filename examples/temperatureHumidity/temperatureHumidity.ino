#include <EduBox.h>

EduBox eduBox;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
}

void loop() {
  float temperature = eduBox.eduTemprature_GetTemperature();
  float humidity = eduBox.eduTemprature_GetHumidity();
  
  Serial.println("Temperature = " + temperature + " °C");
  Serial.println("Humidity = " + humidity + "%");

  delay(250);
}

