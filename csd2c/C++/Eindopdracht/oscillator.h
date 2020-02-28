#ifndef _OSC_H_
#define _OSC_H_

#include <iostream>
using namespace std;

#include "math.h"
#define PI_2 6.28318530717959

class Oscillator {
public:
  // Constructor and destructor
  Oscillator(float freq);
  ~Oscillator();
  // Setters
  void setAmplitude(float amplitude);
  // Return the current sample
  float getSample();

protected:
  float freq;
  float amplitude;
  float phase;
  // Contains the current sample
  float sample;
  float samplerate;
};

#endif
