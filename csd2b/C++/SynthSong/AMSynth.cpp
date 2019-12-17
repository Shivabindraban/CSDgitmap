#include "AMSynth.h"

AMSynth::AMSynth(){
  cout << "AM Synth constructor" << endl;
}

AMSynth::~AMSynth(){
  cout << "AM Synth destructor" << endl;
}

int AMSynth::set(float frequency1, float frequency2, float amplitude){
  double amplituda;
  cout << "AM Synth constructor" << endl;
  this->frequency1 = frequency1;
  this->frequency2 = frequency2;
  this->amplitude = amplitude;

  // Jack Initialisation
  JackModule jack;
  jack.init();
  double samplerate = jack.getSamplerate();

  // AM synthesis with 1 Sine and one Pulse
  Sine  sine1(  frequency1, 0.5);
  Sine  sine2(  frequency2, 0.5);

  // TODO change 60 in to a variable BPM
  // Saw   volumeEnv1((1.0/(60.0/60.0)), amplitude);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
   jack_default_audio_sample_t *outBuf, jack_nframes_t nframes) {
    for(unsigned int i = 0; i < nframes; i++) {
      sine1.tick(samplerate);
      sine2.tick(samplerate);
      outBuf[i] = (sine1.getSample() * ((sine2.getSample()/2)+1/2));
      outBuf[i] *= amplituda;
    }
    return 0;
  };
  // Program runtime used for additive synth did not work
  // Changed the envelope type, without a saw
  jack.autoConnect();
while(amplituda<1){
  amplituda+=0.00000001;
}
while(amplituda>0){
  amplituda-=0.00000001;
}
  jack.end();
  return 0;
}
