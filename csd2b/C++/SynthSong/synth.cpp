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
#include "unistd.h"

Synth::Synth(){
  cout << "Synth constructor" << endl;
}
Synth::~Synth(){
  cout << "Synth destructor" << endl;
}


//additive synth
int Synth::additive(float frequency, float amplitude){
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();
  // additive synthesis with 1 Sine and one Pulse
  Sine  sine1(  frequency/4 ,amplitude/2  );
  Pulse pulse1( frequency   ,amplitude/8  ,0.9);

  // TODO change 128 in to a variable BPM
  Saw   volumeEnv1((1.0/(60.0/128.0)), amplitude);
  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
   jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      sine1.tick(samplerate);
      pulse1.tick(samplerate);
      volumeEnv1.tick(samplerate);
      outBuf[i] = ((sine1.getSample() + pulse1.getSample()) / 2);
      outBuf[i] *= (1-((volumeEnv1.getSample() + 1) /2));
    }
  return 0;
  };
  jack.autoConnect();
  // TODO change 128 here in the same variable BPM
  sleep((60.0/128.0)*5); // How long Synth works in SECONDS
  jack.end();
  return 0;
}

// int Synth::FM(float frequency1, float frequency2, float Harmocity){
//   JackModule jack;
//   jack.init();
//   double samplerate = jack.getSamplerate();
//     Sine  sine1(  frequency1, 1);
//     Sine  sine2(  frequency2, Harmocity);
//
//
//     //assign a function to the JackModule::onProces
//     jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
//        jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
//
//       for(unsigned int i = 0; i < nframes; i++) {
//         sine1.tick(samplerate);
//         sine2.tick(samplerate);
//         outBuf[i] = sine1.getSample() + sine2.getSample();
//         // sine(sine()*Harmocity)
//       }
//
//     return 0;
//   };
//
//   jack.autoConnect();
//
//   //keep the program running and listen for user input, q = quit
//   std::cout << "\n\nPress 'q' when you want to quit the program.\n";
//   bool running = true;
//   while (running)
//   {
//     switch (std::cin.get())
//     {
//       case 'q':
//         running = false;
//         jack.end();
//         break;
//     }
//   }
//   return 0;
// }

// int Synth::AM(float frequency1, float frequency2){
//   JackModule jack;
//   jack.init();
//   double samplerate = jack.getSamplerate();
//     Sine  sine1(  frequency1, 0.5);
//     Sine  sine2(  frequency2, 0.5);
//     //assign a function to the JackModule::onProces
//     jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
//        jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
//
//       for(unsigned int i = 0; i < nframes; i++) {
//         sine1.tick(samplerate);
//         sine2.tick(samplerate);
//         outBuf[i] = (sine1.getSample() * ((sine2.getSample()/2)+1/2));
//       }
//     return 0;
//   };
//
//   jack.autoConnect();
//
//   //keep the program running and listen for user input, q = quit
//   std::cout << "\n\nPress 'q' when you want to quit the program.\n";
//   bool running = true;
//   while (running)
//   {
//     switch (std::cin.get())
//     {
//       case 'q':
//         running = false;
//         jack.end();
//         break;
//     }
//   }
//   return 0;
// }
