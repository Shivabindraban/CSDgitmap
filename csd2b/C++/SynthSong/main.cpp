#include <iostream>
#include <thread>
#include "synth.h"
using namespace std;


int main(int argc, char **argv){
  cout << "Hey! I will present to you some synths. \nHere we go!\n" << endl;


  Synth synth1;
  Synth synth2;
  Synth synth3;
  synth1.additive(400,0.6);
  // synth2.FM(200,400,1);
  // synth3.AM(300,150);

  // Hulp met scaling/limiting
  // Hulp met Sinus binnen sinus voor LFO en FM
  // Hulp met AM

  return 0;
}
