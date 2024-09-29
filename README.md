# EduBox Library 

Arduino library for controlling the modules for teaching programming and electronics, named EduBox!

![image]()

---

## Installation

### First Method

![image]()

1. In the Arduino IDE, navigate to Sketch > Include Library > Manage Libraries
1. Then the Library Manager will open, and you will find a list of libraries that have already been installed or are ready for installation.
1. Then, search for EduBox using the search bar.
1. Click on the text area, select the specific version, and install it.

### Second Method

1. Navigate to the [Releases page]().
1. Download the latest release.
1. Extract the zip file
1. In the Arduino IDE, navigate to Sketch > Include Library > Add .ZIP Library

- ### GNU Lesser General Public License

  EduBox is free software: you can redistribute it and/or modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License or (at your option) any later version.

## Functions

  The functions are named as follows: moduleName_function()

- eduRGB_SetValues()
- eduButton_GetState()
- eduBuzzer_TurnOn()
- eduBuzzer_TurnOff()
- eduPotentiometer_GetValue()
- edu7Segment_DisplayNumber()
- eduDistance_GetDistanceMilimeters()
- eduDistance_GetDistanceCentimeters()
- eduDistance_GetDistanceMeters()
- eduLineSensor_GetLeftSensorValue()
- eduLineSensor_GetCenterSensorValue()
- eduLineSensor_GetRightSensorValue()
- eduStepperMotor_SetSpeed()
- eduStepperMotor_GetPosition()
- eduStepperMotor_SetPosition()
- eduStepperMotor_MakeRotation()
- eduTemprature_GetTemperature()
- eduTemprature_GetHumidity()
- eduServo_SetPosition()
- eduColorSensor_SetBrightness()
- eduColorSensor_GetRed()
- eduColorSensor_GetGreen()
- eduColorSensor_GetBlue()
- eduColorSensor_GetWhite()

## Examples

There are many examples implemented in this library. One of the examples is below. You can find other examples [here](https://github.com/rszczepanski93/EduBox_ArduinoLibrary/tree/main/examples)

### Simple

```Cpp
#include <EduBox.h>

EduBox eduBox;

void setup() {
  eduBox.begin();
}

void loop() {
  eduBox.eduRGB_SetValues(25, 0, 0);
  delay(1000);
  eduBox.eduRGB_SetValues(0, 25, 0);
  delay(1000);
  eduBox.eduRGB_SetValues(0, 0, 25);
  delay(1000);
}
```

## Credits

This library is written by Rafal "szczepi" Szczepanski for PICme Bot company.

## License

EduBox is free software: you can redistribute it and/or  modify it under the terms of the GNU Lesser General Public License as published by the Free Software Foundation, either version 3 of the License, or (at your option) any later version.
EduBox is distributed in the hope that it will be useful, but WITHOUT ANY WARRANTY; without even the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the [GNU Lesser General Public License](https://www.gnu.org/licenses/lgpl-3.0.en.html) for more details.
You should have received a copy of the GNU Lesser General Public License along with EduBox.  If not, see [this](https://www.gnu.org/licenses/).
