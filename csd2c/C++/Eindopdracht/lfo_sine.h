#ifndef _LFOSIN_H_
#define _LFOSIN_H_
#include <iostream>
using namespace std;
#include "oscillator.h"

class Lfo_sine : public Oscillator {
public:
 // Constructor and destructor
 Lfo_sine();
 ~Lfo_sine();
 // Calculation of sine wave
 void tick(double samplerate);
 float getSample();
 float phase;
 float sample;
 float samplerate;

protected:

};
#endif
