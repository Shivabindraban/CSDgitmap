#include <iostream>
#include <thread>
#include "synth.h"

int main(int argc, char **argv){
  Synth synth1;
  synth1.additive(220,0.6);
  return 0;
}
