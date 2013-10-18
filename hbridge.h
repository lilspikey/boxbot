#ifndef __HBRIDGE_H__
#define __HBRIDGE_H__

class HBridgeMotor {
  private:
    const int _enablePin;
    const int _forwardPin;
    const int _backwardPin;
    const int _speedRange;
  
  public:
    explicit HBridgeMotor(int enablePin, int  forwardPin, int backwardPin, int speedRange=255);
    
    void velocity(float v);
};

#endif __HBRIDGE_H__
