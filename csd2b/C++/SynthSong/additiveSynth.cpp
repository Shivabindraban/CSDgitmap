#include "additiveSynth.h"

AdditiveSynth::AdditiveSynth(){
  cout << "Additive Synth constructor" << endl;
}

AdditiveSynth::~AdditiveSynth(){
  cout << "Additive Synth destructor" << endl;
}

int AdditiveSynth::set(float frequency1, float amplitude){
  cout << "Additive Synth constructor" << endl;
  this->frequency1 = frequency1;
  this->amplitude = amplitude;

  // Jack Initialisation
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();

  // additive synthesis with 1 Sine and one Pulse
  Sine  sine1(  frequency1/4 ,amplitude/2  );
  Pulse pulse1( frequency1   ,amplitude/8  ,0.9);

  // TODO change 60 in to a variable BPM
  Saw   volumeEnv1((1.0/(60.0/60.0)), amplitude);

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
  usleep(4000000);
  jack.end();
  return 0;
}
