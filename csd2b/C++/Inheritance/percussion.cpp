#include "percussion.h"
using namespace std;
// [return valuetype] functionName(parameters)

Percussion::Percussion(string instrumentType) : Instrument(instrumentType){
  this->instrumentType = instrumentType;
  cout << "Following percussion instrument instance constructed: " << instrumentType << "\n";
}

Percussion::~Percussion(){
  // cout << "Following percussion instrument instance destructed: " << instrumentType << "\n";
}

void Percussion::pitchGlide(){
  cout << "pitch gliding applied for " << instrumentType << "\n";
}
