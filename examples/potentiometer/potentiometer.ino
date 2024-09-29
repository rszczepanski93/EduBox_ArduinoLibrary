#include <EduBox.h>

EduBox eduBox;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
}

void loop() {
  float analogValue = eduBox.eduPotentiometer_GetValue();

  Serial.print("Potentiometer value = ");
  Serial.print(analogValue);
  Serial.println();
    
  delay(250);
}

