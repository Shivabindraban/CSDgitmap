#include "oscillator.h"

Oscillator::Oscillator() {
  cout << "Oscillator constructor" << endl;
}

Oscillator::~Oscillator() {
  cout << "Oscillator destructor" << endl;
}

void Oscillator::frequency(float freq) {
  this->freq = freq;
}

void Oscillator::amplitude(float amp) {
  this->amp = amp;
}

float Oscillator::getSample() {
  return sample;
}
