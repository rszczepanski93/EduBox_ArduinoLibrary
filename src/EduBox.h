#ifndef EDUBOX_H
#define EDUBOX_H

#include <Arduino.h>
#include <stdbool.h>

class EduBox
{
  public:
    EduBox(void);
    
    void begin(void);

    float eduRGB_SetValues(unsigned char r, unsigned char g, unsigned char b, bool secondModule = false);
    
    float eduButton_GetState(bool secondModule = false);

    float eduBuzzer_TurnOn(bool secondModule = false);
    float eduBuzzer_TurnOff(bool secondModule = false);

    float eduPotentiometer_GetValue(bool secondModule = false);

    float edu7Segment_DisplayNumber(int value, bool secondModule = false);

    float eduDistance_GetDistanceMilimeters(bool secondModule = false );
    float eduDistance_GetDistanceCentimeters(bool secondModule = false );
    float eduDistance_GetDistanceMeters(bool secondModule = false );

    float eduLineSensor_GetLeftSensorValue(bool secondModule = false);
    float eduLineSensor_GetCenterSensorValue(bool secondModule = false);
    float eduLineSensor_GetRightSensorValue(bool secondModule = false);

    float eduStepperMotor_SetSpeed(float rotationsPerSecond, bool secondModule = false);
    float eduStepperMotor_GetPosition(bool secondModule = false);
    float eduStepperMotor_SetPosition(float rotation, float rotationsPerSecond, bool secondModule = false);
    float eduStepperMotor_MakeRotation(float rotation, float rotationsPerSecond, bool secondModule = false);

    float eduTemprature_GetTemperature(bool secondModule = false);
    float eduTemprature_GetHumidity(bool secondModule = false);
    
    float eduServo_SetPosition(int8_t positionDegrees, bool secondModule = false);

    float eduColorSensor_SetBrightness(int brigthness, bool secondModule = false);
    float eduColorSensor_GetRed(bool secondModule = false);
    float eduColorSensor_GetGreen(bool secondModule = false);
    float eduColorSensor_GetBlue(bool secondModule = false);
    float eduColorSensor_GetWhite(bool secondModule = false);
    
  private:
    bool sendData(int addr, unsigned char  *data, int n);
    bool receiveData(int addr, unsigned char *data, int n);
};

#endif // EDUBOX_H