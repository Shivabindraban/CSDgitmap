#include "square.h"
#include "math.h"

Square::Square() : Oscillator() {
  cout << "Square constructor" << endl;
}
Square::~Square() {
  cout << "Square destructor" << endl;
}

// square wave formula
void Square::tick(double samplerate) {
 phase += freq / samplerate;
 sample = 1 * (sin(phase * PI_2));

 if (sample >= 0.0)
   sample = amp;
 else
   sample = -amp;
}