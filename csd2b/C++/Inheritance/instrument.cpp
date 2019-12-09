#include "instrument.h"
using namespace std;
// [return valuetype] functionName(parameters)

Instrument::Instrument(string instrumentType, string freqRange){
  cout << "\nInstrument - Constructor\n";
  // cout << "Following instrument instance created: " << instrumentType << "\n";
  this->instrumentType = instrumentType;
}

Instrument::~Instrument(){
  cout << "\nInstrument - Destructor\n";
}

void Instrument::play(string sound, string frequency){
  cout << instrumentType << " plays " << sound << " at " << frequency << " Hz \n";
}
