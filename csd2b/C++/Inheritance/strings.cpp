#include "strings.h"
using namespace std;
// [return valuetype] functionName(parameters)


Strings::Strings(string instrumentType, string freqRange) : Instrument(instrumentType, freqRange){
  this->instrumentType = instrumentType;
  cout << "Following String instrument instance constructed: " << instrumentType << " with frequency range " << freqRange << " in Hz\n";
}

Strings::~Strings(){
  cout << "Following String instrument instance destructed: " << instrumentType << "\n";
}

void String::pluck(){
  cout << "plucking applied for " << instrumentType << "\n";
}
