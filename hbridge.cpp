#include "Arduino.h"
#include "hbridge.h"


HBridgeMotor::HBridgeMotor(int enablePin, int  forwardPin, int backwardPin)
  : _enablePin(enablePin),
    _forwardPin(forwardPin),
    _backwardPin(backwardPin)
{
  pinMode(enablePin, OUTPUT);
  pinMode(forwardPin, OUTPUT);
  pinMode(backwardPin, OUTPUT);
}

void HBridgeMotor::velocity(int v)
{
  int s = abs(v);
  if ( v > 0 ) {
    digitalWrite(_forwardPin, HIGH);
    digitalWrite(_backwardPin, LOW);
  }
  else if ( v < 0 ) {
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardPin, HIGH);
  }
  else {
    digitalWrite(_forwardPin, LOW);
    digitalWrite(_backwardPin, LOW);
  }
  analogWrite(_enablePin, s);
}
