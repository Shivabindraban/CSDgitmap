#include <iostream>
#include <thread>
#include "math.h"

#include "jack_module.h"
#include "lfo_sine.h"
#include "distortion.h"
#include "circBuffer.h"
#include "flanger.h"

using namespace std;

/*
 * NOTE: jack2 needs to be installed
 * jackd invokes the JACK audio server daemon
 * https://github.com/jackaudio/jackaudio.github.com/wiki/jackd(1)
 * on mac, you can start the jack audio server daemon in the terminal:
 * jackd -d coreaudio
 */

#define PI_2 6.28318530717959

int main(int argc,char **argv)
{

  // distortions for both audio channels
  Distortion distL;
  Distortion distR;

  // lfo's for left and right audio channels
  Lfo_sine lfoR;
  Lfo_sine lfoL;

  // create a JackModule instance
  JackModule jack;

  // init the jack, use program name as JACK client name
  jack.init(argv[0]);
  double samplerate = jack.getSamplerate();

  // Flanger(samplerate,feedback,lfoFreq,lfoDepth)
  Flanger flanger(samplerate, 80, 1, 50);

  // variables for the scaling of the input to parameters
  int flang_fdbck_scale = 100;
  int flang_fdbck_offset = 20;
  int flang_lfoFreq_scale = 1;
  int flang_lfoFreq_offset = 0;
  int flang_lfoDepth_scale = 80;
  int flang_lfoDepth_offset = 20;

  int dist_lfoR_scale = 8;
  int dist_lfoR_offset = 3;
  int dist_lfoL_scale = 10;
  int dist_lfoL_offset = 2;
  int dist_lfoDepth_scale = 20;
  int dist_lfoDepth_offset = 5;

  //assign a function to the JackModule::onProces
  jack.onProcess = [&](jack_default_audio_sample_t *inBuf,
     jack_default_audio_sample_t *outBufL, jack_default_audio_sample_t *outBufR, jack_nframes_t nframes) {

    for(unsigned int i = 0; i < nframes; i++) {
      // ticking lfo's

      lfoL.tick(samplerate);
      lfoR.tick(samplerate);

      // "flanging"  the input buffer"
      float flanged_input = flanger.getSample(inBuf[i]);

      // converting the input buffer from -1/1 0/1
      float mic_in = inBuf[i];
      float mic_abs = abs(mic_in);

      // parameters to be controlled by audio input
      flanger.setFeedback((mic_abs * flang_fdbck_scale) - flang_fdbck_offset);
      flanger.setLfoFreq((mic_abs * flang_lfoFreq_scale) + flang_lfoFreq_offset);
      flanger.setLfoDepth((mic_abs * flang_lfoDepth_scale) + flang_lfoDepth_offset);

      lfoR.setFrequency((mic_abs * dist_lfoR_scale) + dist_lfoR_offset);
      lfoL.setFrequency((mic_abs * dist_lfoL_scale) + dist_lfoL_offset);
      float lfoDepth = ((mic_abs * dist_lfoDepth_scale) + dist_lfoDepth_offset);

      // left channel drive with lfo modulation
      float driveL = ((lfoL.getSample() * lfoDepth) + 1);

      //right channel drive with lfo modulation
      float driveR = ((lfoR.getSample() * lfoDepth) + 1);

      // distorting the "flanged_input" with distL and distR
      outBufL[i] = (distL.getSample((flanged_input * driveL)) / driveL);
      outBufR[i] = (distR.getSample((flanged_input * driveR)) / driveR);

    }
    return 0;
  };

  jack.autoConnect();

  //keep the program running and listen for user input, q = quit
  std::cout << "\n\nPress 'q' to quit.\n";
  std::cout << "Press '1' for normal mode.\n";
  std::cout << "Press '2' for crazy mode.\n";
  bool running = true;
  while (running)
  {
    switch (std::cin.get())
    {
      // user input for quiting and changing settings
      case 'q':
        running = false;
        jack.end();
        break;
      // normal mode
      case '1':
        flang_fdbck_scale = 100;
        flang_fdbck_offset = 20;
        flang_lfoFreq_scale = 1;
        flang_lfoFreq_offset = 0;
        flang_lfoDepth_scale = 80;
        flang_lfoDepth_offset = 20;

        dist_lfoR_scale = 8;
        dist_lfoR_offset = 3;
        dist_lfoL_scale = 10;
        dist_lfoL_offset = 2;
        dist_lfoDepth_scale = 20;
        dist_lfoDepth_offset = 5;
        break;
      // crazy mode
      case '2':
        flang_fdbck_scale = 100;
        flang_fdbck_offset = 10;
        flang_lfoFreq_scale = 200;
        flang_lfoFreq_offset = 20;
        flang_lfoDepth_scale = 200;
        flang_lfoDepth_offset = 20;

        dist_lfoR_scale = 20;
        dist_lfoR_offset = 3;
        dist_lfoL_scale = 23;
        dist_lfoL_offset = 2;
        dist_lfoDepth_scale = 30;
        dist_lfoDepth_offset = 5;
        break;
    }
  }

  //end the program
  return 0;
} // main()
