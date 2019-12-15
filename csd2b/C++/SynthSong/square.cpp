#include "square.h"
#include "math.h"

Square::Square(float freq, float amp) : Oscillator(freq, amp) {
  cout << "Square constructor" << endl;
  // this->freq = freq;
  // this->amp = amp;
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
