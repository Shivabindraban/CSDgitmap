#include "strings.h"
using namespace std;
// [return valuetype] functionName(parameters)


Strings::Strings(string instrumentType) : Instrument(instrumentType){
  this->instrumentType = instrumentType;
  cout << "Following String instrument instance constructed: " << instrumentType << "\n";
}

Strings::~Strings(){
  // cout << "Following String instrument instance destructed: " << instrumentType << "\n";
}

void Strings::pluck(){
  cout << "plucking applied for " << instrumentType << "\n";
}
