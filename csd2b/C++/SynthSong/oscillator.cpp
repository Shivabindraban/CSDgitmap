#include "oscillator.h"

Oscillator::Oscillator(float freq, float amp) {
  this->freq = freq;
  this->amp = amp;
  cout << "Oscillator constructor" << endl;
}

Oscillator::~Oscillator() {
  cout << "Oscillator destructor" << endl;
}

float Oscillator::getSample() {
  return sample;
}
