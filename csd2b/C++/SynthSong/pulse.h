#ifndef _PULSE_H_
#define _PULSE_H_
#include "oscillator.h"
#include <iostream>
using namespace std;

class Pulse : public Oscillator {
public:
  Pulse(float freq, float amp, float pulseWidth);
  ~Pulse();

  void tick(double samplerate);
protected:
  float pulseWidth;
};
#endif
