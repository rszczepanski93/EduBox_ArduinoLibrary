#include <Arduino.h>
#include <stdbool.h>
#include <Wire.h>

#include "EduBox.h"
#include "EduBox_Addr.h"

// ------------------------------------------
// Public functions
// ------------------------------------------
EduBox::EduBox(void)
{

}

void EduBox::begin(void)
{
    Wire.begin(); 
    delay(100);
}

float EduBox::eduRGB_SetValues(unsigned char r, unsigned char g, unsigned char b, bool secondModule)
{  
  unsigned char data[3] = {r, g, b};
  if( this->sendData(EDUBOX_ADDR_EDURGB + (secondModule ? 1 : 0), data, 3) )
    return 0.0f;
  else
    return -1.0f;
}

float EduBox::eduButton_GetState(bool secondModule)
{
  unsigned char data[1] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUBUTTON + (secondModule ? 1 : 0), data, 1) )
    return (float)(data[0] == 0);
  else
    return -1.0f;
}

float EduBox::eduBuzzer_TurnOn(bool secondModule)
{  
  unsigned char data[1] = {1u};
  if( this->sendData(EDUBOX_ADDR_EDUBUZZER + (secondModule ? 1 : 0), data, 1) )
    return 0.0f;
  else
    return -1.0f;
}

float EduBox::eduBuzzer_TurnOff(bool secondModule)
{  
  unsigned char data[1] = {0u};
  if( this->sendData(EDUBOX_ADDR_EDUBUZZER + (secondModule ? 1 : 0), data, 1) )
    return 0.0f;
  else
    return -1.0f;
}

float EduBox::eduPotentiometer_GetValue(bool secondModule)
{
  unsigned char data[1] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUPOTENTIOMETER + (secondModule ? 1 : 0), data, 1) )
    return 1.0f - (float)data[0] / 256.0f;
  else
    return -1.0f;
}

float EduBox::edu7Segment_DisplayNumber(int value, bool secondModule)
{
  if(value > 99) value = 99;

  uint8_t digit1 = (value / 10) % 10;
  uint8_t digit2 = value % 10;
  
  unsigned char data[2] = {(unsigned char)digit1, (unsigned char)digit2};
  if( this->sendData(EDUBOX_ADDR_EDU7SEGMENT + (secondModule ? 1 : 0), data, 2) )
    return 0.0f;
  else
    return -1.0f;
}

float EduBox::eduDistance_GetDistanceMilimeters(bool secondModule)
{
  unsigned char data[2] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUDISTANCE + (secondModule ? 1 : 0), data, 2) )
    return (float)(((uint16_t)data[0] << 8) + (uint16_t)data[1]);
  else
    return -1.0f;
}

float EduBox::eduDistance_GetDistanceCentimeters(bool secondModule)
{
  return this->eduDistance_GetDistanceMilimeters(secondModule) / 10;
}

float EduBox::eduDistance_GetDistanceMeters(bool secondModule)
{
  return this->eduDistance_GetDistanceMilimeters(secondModule) / 1000;
}

float EduBox::eduLineSensor_GetLeftSensorValue(bool secondModule)
{
  unsigned char data[3] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDULINEDETECTOR + (secondModule ? 1 : 0), data, 3) )
    return (float)data[0] / 255.0f;
  else
    return -1.0f;
}

float EduBox::eduLineSensor_GetCenterSensorValue(bool secondModule)
{
  unsigned char data[3] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDULINEDETECTOR + (secondModule ? 1 : 0), data, 3) )
    return (float)data[1] / 255.0f;
  else
    return -1.0f;
}

float EduBox::eduLineSensor_GetRightSensorValue(bool secondModule)
{
  unsigned char data[3] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDULINEDETECTOR + (secondModule ? 1 : 0), data, 3) )
    return (float)data[2] / 255.0f;
  else
    return -1.0f;
}

float EduBox::eduStepperMotor_SetSpeed(float rotationsPerSecond, bool secondModule)
{
  int32_t freq = 2048*rotationsPerSecond;
  uint8_t *ptr = (uint8_t *)&freq;

  if( this->sendData(EDUBOX_ADDR_EDUSTEPPERMOTOR + (secondModule ? 1 : 0), ptr, 4) )
    return 0.0f;
  else
    return -1.0f;
}

float EduBox::eduStepperMotor_GetPosition(bool secondModule)
{
  unsigned char data[4] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUSTEPPERMOTOR + (secondModule ? 1 : 0), data, 4) ){
    int32_t *ptr = (int32_t *)data;
    return (float)*ptr / 2048.0f;
  }  
  else
    return -1.0f;
}

float EduBox::eduStepperMotor_SetPosition(float rotation, float rotationsPerSecond, bool secondModule) 
{
  if( (rotation < 0 && rotationsPerSecond > 0) || (rotation > 0 && rotationsPerSecond < 0))
    rotationsPerSecond *= -1.0f;
  float currentPosition;
  if( false == this->eduStepperMotor_SetSpeed(rotationsPerSecond, secondModule) )
    return -1.0f;
  do {
    currentPosition = this->eduStepperMotor_GetPosition(secondModule);
    delay(10);
  } while( (currentPosition < rotation && rotationsPerSecond > 0) || (currentPosition > rotation && rotationsPerSecond < 0) ); 
  if( false == this->eduStepperMotor_SetSpeed(0.0f, secondModule) )
    return -1.0f;
  return 0.0f;
}

float EduBox::eduStepperMotor_MakeRotation(float rotation, float rotationsPerSecond, bool secondModule)
{
  if( (rotation < 0 && rotationsPerSecond > 0) || (rotation > 0 && rotationsPerSecond < 0))
    rotationsPerSecond *= -1.0f;
  float initPosition = this->eduStepperMotor_GetPosition(secondModule);
  float currentPosition = initPosition;
  if( false == this->eduStepperMotor_SetSpeed(rotationsPerSecond, secondModule) )
    return -1.0f;
  do {
    currentPosition = this->eduStepperMotor_GetPosition(secondModule);
    delay(10);
  } while( abs(currentPosition - initPosition) < abs(rotation) );
  if( false == this->eduStepperMotor_SetSpeed(0.0f, secondModule) )
    return -1.0f;
  return 0.0f;
}

float EduBox::eduTemprature_GetTemperature(bool secondModule)
{
  unsigned char data[4] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUTEMPERATURE + (secondModule ? 1 : 0), data, 4) )
    return (float)(((uint16_t)data[0] << 8) + (uint16_t)data[1]) * 165.0f / 65536.0f - 40.0f;
  else
    return -1.0f;
}

float EduBox::eduTemprature_GetHumidity(bool secondModule)
{
  unsigned char data[4] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUTEMPERATURE + (secondModule ? 1 : 0), data, 4) )
    return (float)(((uint16_t)data[2] << 8) + (uint16_t)data[3]) * 100.0f / 65536.0f;
  else
    return -1.0f;
}

float EduBox::eduServo_SetPosition(int8_t positionDegrees, bool secondModule)
{  
  unsigned char data[1] = {(uint8_t)((((int)positionDegrees+100)/5 + 10)*10 / 9) };
  if( this->sendData(EDUBOX_ADDR_EDUSERVO + (secondModule ? 1 : 0), data, 1) )
    return 0.0f;
  else
    return -1.0f;
}


float EduBox::eduColorSensor_SetBrightness(int brigthness, bool secondModule)
{
  unsigned char data = brigthness;
  if( this->sendData(EDUBOX_ADDR_EDUCOLORSENSOR + (secondModule ? 1 : 0), &data, 1) )
    return 0.0f;
  else
    return -1.0f;
}

float EduBox::eduColorSensor_GetRed(bool secondModule)
{
  unsigned char data[8] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUCOLORSENSOR + (secondModule ? 1 : 0), data, 8) )
    return (float)(((uint16_t)data[1] << 8) + (uint16_t)data[0]) * 0.007865f;
  else
    return -1.0f;
}

float EduBox::eduColorSensor_GetGreen(bool secondModule)
{
  unsigned char data[8] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUCOLORSENSOR + (secondModule ? 1 : 0), data, 8) )
    return (float)(((uint16_t)data[3] << 8) + (uint16_t)data[2]) * 0.007865f;
  else
    return -1.0f;
}

float EduBox::eduColorSensor_GetBlue(bool secondModule)
{
  unsigned char data[8] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUCOLORSENSOR + (secondModule ? 1 : 0), data, 8) )
    return (float)(((uint16_t)data[5] << 8) + (uint16_t)data[4]) * 0.007865f;
  else
    return -1.0f;
}

float EduBox::eduColorSensor_GetWhite(bool secondModule)
{
  unsigned char data[8] = {0};
  if( this->receiveData(EDUBOX_ADDR_EDUCOLORSENSOR + (secondModule ? 1 : 0), data, 8) )
    return (float)(((uint16_t)data[7] << 8) + (uint16_t)data[6]) * 0.007865f;
  else
    return -1.0f;
}


// ------------------------------------------
// Private functions
// ------------------------------------------
bool EduBox::sendData(int addr, uint8_t *data, int n)
{
    Wire.beginTransmission(addr);
    while(n--)
    {
        Wire.write(*data++);
    }
    return 0 == Wire.endTransmission();
}

bool EduBox::receiveData(int addr, uint8_t *data, int n)
{
    Wire.requestFrom(addr, n);
    if (n <= Wire.available()) 
    { 
        while(n--)
        {
            *data++ = Wire.read();
        }
        return true;
    }
    else
      return false;
}