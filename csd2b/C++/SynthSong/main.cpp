#include <iostream>
#include <thread>
#include "synth.h"
using namespace std;


int main(int argc, char **argv){
  cout << "Hey! I will present to you a synths. \nHere we go!\n" << endl;


  Synth synth1;
  Synth synth2;
  synth1.additive(2200,0.6);
  synth2.FM(200,400,1);
  // Hulp met scaling/limiting
  // Hulp met Sinus binnen sinus voor LFO en FM

  return 0;
}
