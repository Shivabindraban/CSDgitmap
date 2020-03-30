#include "lfo_sine.h"
#include "math.h"
#include "oscillator.h"

// Constructor & Destructor
Lfo_sine::Lfo_sine() : Oscillator() {
}
Lfo_sine::~Lfo_sine() {
}

// Gives a new a samplevalue every new "tick" from the samplerate
void Lfo_sine::tick(double samplerate) {
  phase += frequency / samplerate;
  // Absolute LFOsine
  sample = ((sin(phase * PI_2))*0.5)+0.5;
}

float Lfo_sine::getSample() {
  return sample;
}
