#include <EduBox.h>

EduBox eduBox;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
  
  eduBox.eduColorSensor_SetBrightness(20);
}

void loop() {
  float red = eduBox.eduColorSensor_GetRed();
  float green = eduBox.eduColorSensor_GetGreen();
  float blue = eduBox.eduColorSensor_GetBlue();

  Serial.print("R: ");
  Serial.print(red);
  Serial.print(" G: ");
  Serial.print(green);
  Serial.print(" B: ");
  Serial.print(blue);
  Serial.println();

  if( red > green ) {
    if( red > blue )
      Serial.println("It's red!");
    else
      Serial.println("It's blue!");
  }
  else {
    if( green > blue )
      Serial.println("It's green!");
    else
      Serial.println("It's blue!");
  }
    
  delay(3000);
}

