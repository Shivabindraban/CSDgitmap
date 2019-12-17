#include "unistd.h"
#include "jack_module.h"
#include "sine.h"
#include "pulse.h"
#include "saw.h"

#include <iostream>
using namespace std;

class AdditiveSynth {
public:
  AdditiveSynth();
  ~AdditiveSynth();
  int set(float frequency1, float amplitude);
  float amplitude;
  float frequency1;
};
