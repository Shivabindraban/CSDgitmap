#ifndef _SQUARE_H_
#define _SQUARE_H_
#include "oscillator.h"
#include <iostream>
using namespace std;

class Square : public Oscillator {
public:
  Square(float freq, float amp);
  ~Square();

  void tick(double samplerate);
};
#endif
