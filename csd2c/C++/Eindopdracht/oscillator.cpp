#include "oscillator.h"

// Constructor & Destructor
Oscillator::Oscillator() {
}
Oscillator::~Oscillator() {
}

void Oscillator::setAmplitude(float amplitude) {
  this->amplitude = amplitude;
}

void Oscillator::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}

float Oscillator::getFrequency(){
  return frequency;
}
