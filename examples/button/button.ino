#include <EduBox.h>

EduBox eduBox;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
}

void loop() {
  bool buttonState = eduBox.eduButton_GetState();

  if( buttonState )
    Serial.println("Button is pushed!");
  else
    Serial.println("Button is released!");
    
  delay(250);
}

