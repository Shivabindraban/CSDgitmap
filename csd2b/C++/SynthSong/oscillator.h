#ifndef _OSC_H_
#define _OSC_H_
#include <iostream>
using namespace std;

#define PI_2 6.28318530717959

class Oscillator{
public:
  //Constructor and destructor
  Oscillator(float freq, float amp);
  ~Oscillator();
  //return the current sample
  float getSample();

protected:
  float freq;
  float amp;
  float phase;
  // contains the current sample
  float sample;
  float samplerate;
};

#endif
