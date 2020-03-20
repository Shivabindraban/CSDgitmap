#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "circBuffer.h"
#include "flanger.h"

// // 10 seconds if samplerate = 44100
// #define MAX_DELAY_SIZE 441000
// #define DELAY_TIME_SEC 3.0f

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();

  // Flanger(samplerate,feedback,lfoFreq,lfoDepth,drywetmix)
  Flanger flanger1(samplerate, 80, 0.1, 50, 90);

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
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
  cout << "\n\nPress 'l' to change the LFO frequency.\n";
  cout << "\n\nPress 'd' to change the modulation Depth for the LFO.\n";
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

      case 'l':
        float lfoFreq;
        cout << "Enter any (float) number between 0 and 5: ";
        while(true)
          {
            cin >> lfoFreq;
            if(lfoFreq >= 0 && lfoFreq <= 5){
              cout << "The LFO frequency is set @ " << lfoFreq<< "Hz" << endl ;
              break;
            }
            else {
              cin.clear();
              cin.ignore();
              cout << "Please enter a number between 0 and 5" << endl;
            };
          };
        flanger1.setLfoFreq(lfoFreq);
        break;

      case 'd':
        float lfoDepth;
        cout << "Enter any positive number between 0 and 200: ";
        while(true)
          {
            cin >> lfoDepth;
            if(lfoFreq >= 0 && lfoFreq <= 200){
              cout << "The LFO depth is set @ " << lfoDepth<< endl ;
              break;
            }
            else {
              cin.clear();
              cin.ignore();
              cout << "Please enter a positive number between 0 and 200" << endl;
            };
          };
        flanger1.setLfoDepth(lfoDepth);
        break;
    }
  }

  //end the program
  return 0;
} // main()
