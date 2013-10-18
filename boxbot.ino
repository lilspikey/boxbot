#include "hbridge.h"

#define TOP_SPEED 200

HBridgeMotor leftMotor(6, 7, 8);
HBridgeMotor rightMotor(11, 10, 9);

void setup()
{
  leftMotor.velocity(0);
  rightMotor.velocity(0);
  Serial.begin(9600);
}

void loop()
{
  if ( Serial.available() ) {
    switch(Serial.read()) {
      case 'a': {
        leftMotor.velocity(-TOP_SPEED);
        rightMotor.velocity(TOP_SPEED);
        Serial.println("left");
        break;
      }
      case 'd': {
        leftMotor.velocity(TOP_SPEED);
        rightMotor.velocity(-TOP_SPEED);
        Serial.println("right");
        break;
      }
      case 'w': {
        leftMotor.velocity(TOP_SPEED);
        rightMotor.velocity(TOP_SPEED);
        Serial.println("forward");
        break;
      }
      case 's': {
        leftMotor.velocity(-TOP_SPEED);
        rightMotor.velocity(-TOP_SPEED);
        Serial.println("back");
        break;
      }
      case '.': {
        leftMotor.velocity(0);
        rightMotor.velocity(0);
        Serial.println("stop");
        break;
      }
    }
  }
  delay(100);
}
