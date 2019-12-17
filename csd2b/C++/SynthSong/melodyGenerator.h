#include "AMSynth.h"
#include "additiveSynth.h"
#include <random>
#include <iostream>
using namespace std;

class MelodyGenerator {
public:
  // Constructor destructor
  MelodyGenerator();
  ~MelodyGenerator();

  // playing notes with given synth
  void AMPlay(int noteAmount);
  void AddPlay(int noteAmount);
  int randomNumber;
  float amplitude;
  float frequency1;
  float frequency2;
};
