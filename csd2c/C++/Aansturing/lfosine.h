#ifndef _LFOSIN_H_
#define _LFOSIN_H_
#include <iostream>
using namespace std;
#include "oscillator.h"

class LFOsine : public Oscillator {
public:
 // Constructor and destructor
 LFOsine();
 ~LFOsine();
 // Calculation of sine wave
 void tick(double samplerate);
 float getSample();
 float phase;
 float sample;
 float samplerate;

protected:

};
#endif
