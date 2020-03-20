#ifndef _SIN_H_
#define _SIN_H_
#include <iostream>
using namespace std;
#include "oscillator.h"

class Sine : public Oscillator {
public:
 // Constructor and destructor
 Sine();
 ~Sine();
 // Calculation of sine wave
 void tick(double samplerate);
 float getSample();
 float phase;
 float sample;
 float samplerate;

protected:

};
#endif
