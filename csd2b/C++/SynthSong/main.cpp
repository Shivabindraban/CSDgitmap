#include <iostream>
#include <thread>
#include "synth.h"

using namespace std;

int main(int argc, char **argv){
  Synth synth1;
  synth1.additive(220,0.7);
  return 0;
}
