#include "sine.h"
#include "math.h"


// Constructor & Destructor
Sine::Sine() : Oscillator() {
}
Sine::~Sine() {
}

// Gives a new a samplevalue every new "tick" from the samplerate
void Sine::tick(double samplerate) {
  phase += frequency / samplerate;
  // Normal Sine
  sample = sin(phase * PI_2);
}
