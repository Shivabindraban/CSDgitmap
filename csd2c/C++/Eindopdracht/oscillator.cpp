#include "oscillator.h"

// Constructor & Destructor
Oscillator::Oscillator(float freq) {
  this->freq = freq;
}
Oscillator::~Oscillator() {
}

void Oscillator::setAmplitude(float amplitude) {
  this->amplitude = amplitude;
}

float Oscillator::getSample() {
  return sample;
}
