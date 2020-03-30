#ifndef _FLANGER_H_
#define _FLANGER_H_

#include <iostream>
#include "math.h"
using namespace std;
#include "circBuffer.h"
#include "lfo_sine.h"

class Flanger
{
public:
  CircBuffer buffer;
  Lfo_sine flangerLFOsine1;

  Flanger(float samplerate, int feedback, float lfoFreq, float lfoDepth);
  ~Flanger();

  void setFeedback(int feedback);
  void setLfoFreq(float lfoFreq);
  void setLfoDepth(float lfoDepth);
  float getSample(float input);


protected:
  int numSamplesFlanger;
  float samplerate;
  int feedback;
  float lfoFreq;
  float lfoDepth;
  float input;
  float output;
};
#endif
