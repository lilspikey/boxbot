#include "hbridge.h"

// different speeds
// to counter tendency to veer left
#define SPEED_LEFT 250
#define SPEED_RIGHT 140

HBridgeMotor leftMotor(6, 7, 8, SPEED_LEFT);
HBridgeMotor rightMotor(11, 10, 9, SPEED_RIGHT);

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
        leftMotor.velocity(-1);
        rightMotor.velocity(1);
        Serial.println("left");
        break;
      }
      case 'd': {
        leftMotor.velocity(1);
        rightMotor.velocity(-1);
        Serial.println("right");
        break;
      }
      case 'w': {
        leftMotor.velocity(1);
        rightMotor.velocity(1);
        Serial.println("forward");
        break;
      }
      case 's': {
        leftMotor.velocity(-1);
        rightMotor.velocity(-1);
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
    Serial.println();
  }
  delay(100);
}
