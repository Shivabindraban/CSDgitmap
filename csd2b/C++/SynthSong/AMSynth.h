#include "unistd.h"
#include "jack_module.h"
#include "sine.h"
#include "saw.h"

#include <iostream>
using namespace std;

class AMSynth {
public:
  AMSynth();
  ~AMSynth();

  int set(float frequency1, float frequency2, float amplitude);
  float amplitude;
  float frequency1;
  float frequency2;
};
