#include "sineLFO.h"

SineLFO::SineLFO() : Sine() {
 cout << "SineLFO constructor" << endl;
}
SineLFO::~SineLFO() {
 cout << "SineLFO destructor" << endl;
}

void Sine::tick() {
  // TODO - frequency / SAMPLERATE can be implemented in a more efficient way
  phase += frequency / SAMPLERATE;
  sample = sin(M_PI * 2 * phase);
}

//getters and setters
void Sine::setFrequency(float frequency)
{
  // TODO add check to see if parameter is valid
  this->frequency = frequency;
}
