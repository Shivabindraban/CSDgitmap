#include <iostream>
#include <thread>
// #include "synth.h"
#include "additiveSynth.h"
#include "AMSynth.h"
using namespace std;



int main(int argc, char **argv){

  cout << "Hey! I will present to you some synths. \nHere we go!\n" << endl;

  AdditiveSynth addsynth1(400.0,1.0);
  // AMSynth AMsynth1(400.0,3.0,1.0);

  // Synth synth2;
  // Synth synth3;

  // synth2.FM(200,400,1);
  // synth3.AM(300,150);

  return 0;
}
