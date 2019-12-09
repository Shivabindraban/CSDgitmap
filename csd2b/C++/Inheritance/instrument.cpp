#include "instrument.h"
using namespace std;
// [return valuetype] functionName(parameters)

Instrument::Instrument(string instrumentType){
  // cout << "\nInstrument - Constructor\n";
  // cout << "Following instrument instance created: " << instrumentType << "\n";
  this->instrumentType = instrumentType;
}

Instrument::~Instrument(){
  // cout << "\nInstrument - Destructor\n";
}

void Instrument::play(string sound, string frequency){
  cout << instrumentType << " plays " << sound << " at " << frequency << " Hz \n";
}

void Instrument::pitch(int freqRange){
  if (freqRange == 1)
  {
    cout << "The frequency range for  "<< instrumentType << " is in the low range (20 - 400 Hz) \n";
  }
  else if (freqRange == 2)
  {
    cout << "The frequency range for  "<< instrumentType << " is in the mid range (400 - 4000 Hz) \n";
  }
  else if (freqRange == 3)
  {
    cout << "The frequency range for  "<< instrumentType << " is in the mid range (4000 - 20000 Hz) \n";
  }
}
