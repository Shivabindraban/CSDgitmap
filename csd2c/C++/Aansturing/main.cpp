#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "flanger.h"
#include "osc.h"

float oscLfoFreq;
float oscLfoDepth;

#define PI_2 6.28318530717959

// subclass OSC into a local class so we can provide our own callback
class localOSC : public OSC
{
  int realcallback(const char *path,const char *types,lo_arg **argv,int argc)
  {
  // osc "paramater" name
  string msgpath=path;
    // if osc "parameter" name is /oscLfoFreq
    if(!msgpath.compare("/oscLfoFreq")){
      oscLfoFreq = argv[0]->f;
    }
    // if osc "parameter" name is /oscLfoDepth
    if(!msgpath.compare("/oscLfoDepth")){
      oscLfoDepth = argv[0]->f;
    }
    return 0;
  }
};


int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();

  // setting up OSC server
  localOSC osc;
  string serverport="10024";
  osc.init(serverport);
  osc.set_callback("/oscLfoFreq","f");
  osc.set_callback("/oscLfoDepth","f");
  osc.start();
  cout << "Listening on port " << serverport << endl;

  // Flanger(samplerate,feedback,lfoFreq,lfoDepth,drywetmix)
  Flanger flanger1(samplerate, 80, 0.1, 50, 90);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {

      //variables received over OSC
      flanger1.setLfoFreq(oscLfoFreq);
      cout << oscLfoFreq << " " << oscLfoDepth  <<endl;
      flanger1.setLfoDepth(oscLfoDepth);

      outBufL[i] = flanger1.getSample(inBuf[i]);
      outBufR[i] = flanger1.getSample(inBuf[i]);
      // inverted
      // outBufR[i] = ((2*(1-((flanger1.getSample(inBuf[i])*0.5)+0.5)))-1);
    }
    return 0;
  };

  jack.autoConnect();

  cout << "\n\nPress 'q' when you want to quit the program.\n";
  cout << "\n\nPress 'f' to change the feedback amount.\n";
  cout << "\n\nPress 'm' to change the dry/wet mix.\n";
  bool running = true;
  while (running)
  {
    switch (cin.get())
    {
      case 'q':
        running = false;
        jack.end();
        break;

      case 'f':
        float feedback;
        cout << "Enter any whole number between 1 to 99: ";
        while(true)
          {
            cin >> feedback;
            if(feedback >= 1 && feedback <= 99){
              cout << "The feedback percentage amount is set @ " << feedback<< "%"<< endl ;
              break;
            }
            else {
              cin.clear();
              cin.ignore();
              cout << "Please enter a whole number between 1 and 99" << endl;
            };
          };
        flanger1.setFeedback(feedback);
        break;

      case 'm':
        float drywetmix;
        cout << "Enter any whole number between 1 to 100. Higher amount = More Wetness: ";
        while(true)
          {
            cin >> drywetmix;
            if(drywetmix >= 1 && drywetmix <= 100){
              cout << "The drywetmix percentage is set @ " << drywetmix<< "%" << endl ;
              break;
            }
            else {
              cin.clear();
              cin.ignore();
              cout << "Please enter a whole number between 1 and 100" << endl;
            };
          };
        flanger1.setDryWetMix(drywetmix);
        break;
    }
  }

  //end the program
  return 0;
} // main()
