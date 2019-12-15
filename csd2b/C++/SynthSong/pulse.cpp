#include "pulse.h"
#include "math.h"

Pulse::Pulse(float freq, float amp, float pulseWidth) : Oscillator(freq, amp) {
  cout << "Pulse constructor" << endl;
  this->freq = freq;
  this->amp = amp;
  if (pulseWidth > 1.0 || pulseWidth < 0.0){
    cout << "Value Error, pulse Width value should be between 0.0 and 1.0" << endl;
    pulseWidth = 0.5;
  }
  else {
    this-> pulseWidth = pulseWidth;
  }
}
Pulse::~Pulse() {
  cout << "Pulse destructor" << endl;
}

// Pulse wave formula
void Pulse::tick(double samplerate) {
 phase += freq / samplerate;
 sample = 1 * (sin(phase * PI_2));

 if (sample >= pulseWidth)
   sample = amp;
 else
   sample = -amp;
}
