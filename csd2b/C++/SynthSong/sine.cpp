#include "sine.h"
#include "math.h"

Sine::Sine(float freq, float amp) : Oscillator(freq, amp) {
  // this->freq = freq;
  // this->amp = amp;
  cout << "Sine constructor" << endl;
}
Sine::~Sine() {
  cout << "Sine destructor" << endl;
}

// sine wave formula
void Sine::tick(double samplerate) {
  phase += freq / samplerate;
  sample = amp * (sin(phase * PI_2));
}
