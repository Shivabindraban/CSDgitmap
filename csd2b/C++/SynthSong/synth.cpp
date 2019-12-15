#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "saw.h"
#include "square.h"
// #include "sineLFO.h"
#include "oscillator.h"
#include "synth.h"

Synth::Synth(){
  cout << "Synth constructor" << endl;
}
Synth::~Synth(){
  cout << "Synth destructor" << endl;
}

int Synth::additive(float frequency, float amplitude){
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();

    Sine sine1(frequency,amplitude*0.5);
    Saw saw1(frequency*2.5,amplitude/8);
    Square square1(frequency/4, amplitude/8);

    //assign a function to the JackModule::onProces
    jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
       jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {

      for(unsigned int i = 0; i < nframes; i++) {
        outBuf[i] = sine1.getSample() + saw1.getSample() + square1.getSample();
        sine1.tick(samplerate);
        saw1.tick(samplerate);
        square1.tick(samplerate);
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
