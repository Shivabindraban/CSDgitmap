#include "melodyGenerator.h"

MelodyGenerator::MelodyGenerator() {
  cout << "MelodyGenerator constructor" << endl;
}

MelodyGenerator::~MelodyGenerator() {
  cout << "MelodyGenerator destructor" << endl;
}

void MelodyGenerator::AMPlay(int noteAmount){
  AMSynth AMsynth1;

  // Looping untill noteAmount is reached
  for (int i = 1; i < noteAmount;){
    // random_device dev;
    // mt19937 rng(dev());
    // uniform_int_distribution<std::mt19937::result_type> dist(1,3);
    // cout << i << endl;
    switch (i) {
      case 1:
        AMsynth1.set(300.0,10.0,1.0);
        break;
      case 2:
        AMsynth1.set(300.0*(6.0/5.0),10.0,1.0);
        break;
      case 3:
        AMsynth1.set(300.0*(3.0/2.0),10.0,1.0);
        break;
    }
    i++;
  }
}

void MelodyGenerator::AddPlay(int noteAmount) {
  AdditiveSynth addsynth1;

  // Looping untill noteAmount is reached
  for (int i = 1; i < noteAmount;){
    switch (i) {
      case 1:
        addsynth1.set(300.0,1.0);
        break;
      case 2:
        addsynth1.set(300.0*(6.0/5.0),1.0);
        break;
      case 3:
        addsynth1.set(300.0*(3.0/2.0),1.0);
        break;
    }
    i++;
  }
}
