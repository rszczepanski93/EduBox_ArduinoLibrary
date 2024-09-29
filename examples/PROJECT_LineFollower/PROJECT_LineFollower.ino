#include <EduBox.h>

EduBox eduBox;

void setup() {
  eduBox.begin();
}

void loop() {
  float distanceCentimeters = eduBox.eduDistance_GetDistanceCentimeters();
  float leftSensor = eduBox.eduLineSensor_GetLeftSensorValue();
  float rightSensor = eduBox.eduLineSensor_GetRightSensorValue();

  if( distanceCentimeters <= 10 )
  {
    eduBox.eduStepperMotr_SetSpeed(0, false);
    eduBox.eduStepperMotr_SetSpeed(0, true);
  }
  else
  {
    if(leftSensor < rightSensor)
    {
      eduBox.eduStepperMotr_SetSpeed(0.1-0.01, false);
      eduBox.eduStepperMotr_SetSpeed(0.1+0.01, true);
    }
    else
    {
      eduBox.eduStepperMotr_SetSpeed(0.1+0.01, false);
      eduBox.eduStepperMotr_SetSpeed(0.1-0.01, true);
    }
  }

  delay(100);
}

