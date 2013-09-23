#ifndef __HBRIDGE_H__
#define __HBRIDGE_H__

class HBridgeMotor {
  private:
    const int _enablePin;
    const int _forwardPin;
    const int _backwardPin;
  
  public:
    explicit HBridgeMotor(int enablePin, int  forwardPin, int backwardPin);
    
    void velocity(int v);
};

#endif __HBRIDGE_H__
