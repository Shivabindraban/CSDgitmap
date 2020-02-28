#include <iostream>
#include <thread>
#include "jack_module.h"
#include "math.h"
#include "sine.h"
#include "circBuffer.h"

// 10 seconds if samplerate = 44100
#define MAX_DELAY_SIZE 441000
#define DELAY_TIME_SEC 0.5f

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{
  Sine sine1(0.5);
  Sine sine2(0.6);
  sine1.setAmplitude(1);
  sine2.setAmplitude(1);
  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  float samplerate = jack.getSamplerate();

  float delayTimeSec = DELAY_TIME_SEC;
  if(argc >= 2) delayTimeSec = (float) atof(argv[1]);
  std::cout <<  "\nDelay time in seconds: " << delayTimeSec << "\n";

  int numSamplesDelay = samplerate * delayTimeSec;
  std::cout << "\ninput is delay by " << numSamplesDelay << " number of samples\n";

  CircBuffer circBuffer(numSamplesDelay * 2);

  circBuffer.setDistanceRW(numSamplesDelay);
  circBuffer.logAllSettings();

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      sine1.tick(samplerate);
      sine2.tick(samplerate);
      circBuffer.write(inBuf[i]);
      circBuffer.incrWriteH();


      #if 1
      outBufL[i] = (circBuffer.read() * 0.5);
      outBufR[i] = (circBuffer.read() * 0.5);
      #endif

      #if 0
      outBufL[i] = sine1.getSample();
      outBufR[i] = sine1.getSample();
      #endif
      circBuffer.incrReadH();
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

  //end the program
  return 0;
} // main()
