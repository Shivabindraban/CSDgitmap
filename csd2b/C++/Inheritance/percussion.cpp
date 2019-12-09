#include "percussion.h"
using namespace std;
// [return valuetype] functionName(parameters)

Percussion::Percussion(string instrumentType, string freqRange) : Instrument(instrumentType, freqRange){
  this->instrumentType = instrumentType;
  cout << "Following percussion instrument instance constructed: " << instrumentType << " with frequency range " << freqRange << " in Hz\n";
}

Percussion::~Percussion(){
  cout << "Following percussion instrument instance destructed: " << instrumentType << "\n";
}
