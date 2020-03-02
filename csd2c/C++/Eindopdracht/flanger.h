#ifndef _FLANGER_H_
#define _FLANGER_H_

#include <iostream>
#include "math.h"
using namespace std;
#include "circBuffer.h"
#include "lfosine.h"

class Flanger
{
public:
  CircBuffer buffer;
  LFOsine flangerLFOsine1;

  Flanger(float samplerate, int feedback, float lfoFreq, float lfoDepth, int drywetmix);
  ~Flanger();

  void setFeedback(int feedback);
  void setLfoFreq(float lfoFreq);
  void setLfoDepth(float lfoDepth);
  void setDryWetMix(int drywetmix);
  float getSample(float input);


protected:
  int numSamplesFlanger;
  float samplerate;
  int feedback;
  float lfoFreq;
  float lfoDepth;
  int drywetmix;
  float input;
  float output;
};
#endif
