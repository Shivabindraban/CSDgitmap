#ifndef _OSC_H_
#define _OSC_H_

#include <iostream>
using namespace std;

#include "math.h"
#define PI_2 6.28318530717959

class Oscillator {
public:
  // Constructor and destructor
  Oscillator();
  ~Oscillator();

  void tick();
  void setAmplitude(float amplitude);
  void setFrequency(float frequency);
  float getFrequency();

protected:
  float frequency;
  float amplitude;

};

#endif
