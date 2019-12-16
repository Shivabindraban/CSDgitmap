#ifndef _ADDSYNTH_H_
#define _ADDSYNTH_H_

#include <iostream>
using namespace std;

class AdditiveSynth {
public:
  AdditiveSynth(float frequency, float amplitude);
  ~AdditiveSynth();
  float amplitude;
  float frequency;
  int argc;
  char **argv;
};
#endif
