#ifndef _AMSYNTH_H_
#define _AMSYNTH_H_

#include <iostream>
using namespace std;

class AMSynth {
public:
  AMSynth(float frequency1, float frequency2, float amplitude);
  ~AMSynth();
  float amplitude;
  float frequency1;
  float frequency2;
  int argc;
  char **argv;
};
#endif
