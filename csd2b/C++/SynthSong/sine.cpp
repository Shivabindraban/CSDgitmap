#include "sine.h"
#include "math.h"

Sine::Sine() : Oscillator() {
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