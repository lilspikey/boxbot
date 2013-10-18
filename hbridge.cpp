#include "Arduino.h"
#include "hbridge.h"


HBridgeMotor::HBridgeMotor(int enablePin, int  forwardPin, int backwardPin, int speedRange)
  : _enablePin(enablePin),
    _forwardPin(forwardPin),
    _backwardPin(backwardPin),
    _speedRange(speedRange)
{
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
}

void HBridgeMotor::velocity(float v)
{
  int s = (int)(_speedRange*min(1.0f, abs(v)));
  if ( s == 0 ) {
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardPin, LOW);
  }
  else if ( v >= 0 ) {
    digitalWrite(_forwardPin, HIGH);
    digitalWrite(_backwardPin, LOW);
  }
  else if ( v <= 0 ) {
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardPin, HIGH);
  }
  analogWrite(_enablePin, s);
}
