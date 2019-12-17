#include <iostream>
#include <thread>
// #include "synth.h"
#include "melodyGenerator.h"
#include "jack_module.h"

using namespace std;

int main()
{
  int noteAmount;
  MelodyGenerator Mel;
  MelodyGenerator Mel2;
  bool test = true;
  cout << "Hey there, Buckle up for some wild tunes...\n";
  cout << "In order to play, you will have to choose > 1 < for an AM-synth or > 2 < for an Additive synth. \n";
  cout << "If you don't like the synth, leave with > q <  \n";
  cout << "Please enter one of the two numbers: ";
  while (test){
    switch (cin.get()) {
      case '1':
        test=false;
        cout << "\nPlease enter the number of notes you want to play:\n";
        cin >> noteAmount;
        while (!cin.good()){
          cout << "Enter a valid number!\n";
          cin.clear();
        }
        Mel.AMPlay(noteAmount);
        break;
      case '2':
        test=false;
        cout << "\nPlease enter the number of notes you want to play:\n";
        cin >> noteAmount;
        while (!cin.good()){
          cout << "Enter a valid number!\n";
          cin.clear();
        }
        Mel2.AddPlay(noteAmount);
        break;
      case 'q':
        test=false;
    }
  }

  return 0;
} // main()
