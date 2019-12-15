#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
#include "pulse.h"
// #include "sineLFO.h"
#include "oscillator.h"
#include "synth.h"

Synth::Synth(){
  cout << "Synth constructor" << endl;
}
Synth::~Synth(){
  cout << "Synth destructor" << endl;
}

//additive synth
int Synth::additive(float frequency, float amplitude){
  // if (frequency < 50 || frequency > 500){
  //   cout << "Value Error, frequency can only be between 50 and 500" << endl;
  //   frequency = 220;
  // }
  // else {
  //   frequency = frequency;
  // }
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();

    cout << frequency << endl;

    Sine  sine1(  frequency       ,amplitude/2  );
    Saw   saw1(   frequency*(3/2) ,amplitude/4  );
    Pulse pulse1( frequency*(5/2) ,amplitude/8    ,0.9);
    Pulse pulse2( frequency/4     ,amplitude/8    ,0.5);

    //assign a function to the JackModule::onProces
    jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
       jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

      for(unsigned int i = 0; i < nframes; i++) {
        sine1.tick(samplerate);
        saw1.tick(samplerate);
        pulse1.tick(samplerate);
        pulse2.tick(samplerate);
        outBuf[i] = sine1.getSample() + saw1.getSample() + pulse1.getSample() + pulse2.getSample();

      }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
  return 0;
}

int Synth::FM(float frequency1, float frequency2, float Harmocity){
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();
    Sine  sine1(  frequency1, 1);
    Sine  sine2(  frequency2, Harmocity);


    //assign a function to the JackModule::onProces
    jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
       jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

      for(unsigned int i = 0; i < nframes; i++) {
        sine1.tick(samplerate);
        sine2.tick(samplerate);
        outBuf[i] = sine1.getSample() + sine2.getSample();
        sine1.tick(samplerate);
        sine2.tick(samplerate);
      }

    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' when you want to quit the program.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;
    }
  }
  return 0;
}
