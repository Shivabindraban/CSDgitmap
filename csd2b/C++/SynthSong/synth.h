#ifndef _SYNTH_H_
#define _SYNTH_H_

#include <iostream>
using namespace std;

class Synth{
public:
  Synth();
  ~Synth();
int argc;
char **argv;
int additive(float frequency, float amplitude);

};

#endif