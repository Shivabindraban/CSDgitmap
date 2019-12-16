#include "oscillator.h"

Oscillator::Oscillator(float freq, float amp) {
  cout << "Oscillator constructor" << endl;
  if (freq < 0 || freq > 500){
    cout << "Value Error, frequency can only be between 50 and 500" << endl;
    this->freq = 10;
  }
  else {
    this->freq = freq;
  }
  if (amp < 0.0 || amp > 1.0){
    cout << "Value Error, frequency can only be between 50 and 500" << endl;
    this->amp = 1.0;
  }
  else {
    this->amp = amp;
  }
}

Oscillator::~Oscillator() {
  cout << "Oscillator destructor" << endl;
}

float Oscillator::getSample() {
  return sample;
}
