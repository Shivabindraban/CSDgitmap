#include "saw.h"
#include "math.h"

Saw::Saw(float freq, float amp) : Oscillator(freq, amp) {
  // this->freq = freq;
  // this->amp = amp;
  cout << "Saw constructor" << endl;
}
Saw::~Saw() {
  cout << "Saw destructor" << endl;
}

// saw wave formula
void Saw::tick(double samplerate) {
  phase += freq / samplerate;
  sample = ((fmod(phase,1)*2)-1)*amp;
}
