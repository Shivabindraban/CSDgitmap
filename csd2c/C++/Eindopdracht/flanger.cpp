#include <thread>
#include <iostream>
#include "flanger.h"
#include "lfosine.h"
#include "oscillator.h"
#include "jack_module.h"
#include "math.h"

Flanger::Flanger(float samplerate, int feedback, float lfoFreq, float lfoDepth, int drywetmix)
{
  this->samplerate = samplerate;
  this->feedback = feedback;
  this->lfoFreq = lfoFreq;
  this->lfoDepth = lfoDepth;
  this->drywetmix = drywetmix;

  //Delay time for a flanger starts at 5ms, hence *0.005
  numSamplesFlanger = samplerate * 0.005;
  //Buffer must be twice as long as desired flanger.
  buffer.resetSize(numSamplesFlanger * 2);
  buffer.setDistanceRW(numSamplesFlanger);

}

Flanger::~Flanger(){
};

void Flanger::setFeedback(int feedback){
  this->feedback = feedback;
}

void Flanger::setLfoFreq(float lfoFreq){
  this->lfoFreq = lfoFreq;
}

void Flanger::setLfoDepth(float lfoDepth){
  this->lfoDepth = lfoDepth;
}

void Flanger::setDryWetMix(int drywetmix){
  this->drywetmix = drywetmix;
}

/*
For every tick in the samplerate, the Input will be written to the buffer
During this tick the readhead position will be determined and modulated by the sine LFOsine
LFO depth is used to increase the range for the digression of the LFO values
To get Feedback, the output also needs to be written back in to the buffer, decreases to prevent resonance
*/
float Flanger::getSample(float input){
  this->input = input;
  float modulationTime = flangerLFOsine1.getSample() * lfoDepth;
  buffer.setDistanceRW(numSamplesFlanger + modulationTime);
  flangerLFOsine1.tick(samplerate);
  buffer.write(input + output * (float)(feedback/100.0));
  buffer.incrWriteH();;
  output = buffer.read() * (100.0/drywetmix) + input * (1-(100.0/drywetmix));
  buffer.incrReadH();
  return output;
}
