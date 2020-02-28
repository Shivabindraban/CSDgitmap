#include "sine.h"
#include "math.h"


// Constructor & Destructor
Sine::Sine(float freq) : Oscillator(freq) {
}
Sine::~Sine() {
}

// sine wave formula
void Sine::tick(double samplerate) {
  phase += freq / samplerate;
  // Normal Sine
  // sample = amplitude * (sin(phase * PI_2));
  // Absolute Sine
  sample = (((amplitude * (sin(phase * PI_2)))*0.5)+0.5);
}
