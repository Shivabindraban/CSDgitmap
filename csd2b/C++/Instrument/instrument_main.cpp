// Deze file is voor de gebruiker, maar hier heb je ook de constructors nodig
#include "instrument_class.h"
#include <iostream>
using namespace std;

int main()
{
  Instrument kick(1);// Hier maakt de constructor een object aan met de beschikbare variable (field)
  // cout << "Sound assigned  of the oscillator =  " << kick.getFreq() << "\n";
  kick.play();
  Instrument snare(2);
  snare.play();
  Instrument synth(3);
  synth.play();
  // kick.setFreq(440);
  cout << "end of main";
  return 0;
}
