#include "lfosine.h"
#include "math.h"
#include "oscillator.h"

// Constructor & Destructor
LFOsine::LFOsine() : Oscillator() {
}
LFOsine::~LFOsine() {
}

// Gives a new a samplevalue every new "tick" from the samplerate
void LFOsine::tick(double samplerate) {
  phase += frequency / samplerate;
  // Absolute LFOsine
  sample = ((sin(phase * PI_2))*0.5)+0.5;
}

float LFOsine::getSample() {
  return sample;
}
