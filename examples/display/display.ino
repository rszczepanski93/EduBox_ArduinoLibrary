#include <EduBox.h>

EduBox eduBox;

int number = 0;

void setup() {
  Serial.begin(115200);
  eduBox.begin();
}

void loop() {
  number++;
  if( number > 99 )
    number = 0;

  eduBox.edu7Segment_DisplayNumber(number);
    
  delay(250);
}

