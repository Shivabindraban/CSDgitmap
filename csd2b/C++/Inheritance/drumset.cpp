#include "drumset.h"
using namespace std;
// [return valuetype] functionName(parameters)

Drumset::Drumset(string instrumentType) : Instrument(instrumentType){
  this->instrumentType = instrumentType;
  cout << "Following drum instrument instance constructed: " << instrumentType << "\n";
}

Drumset::~Drumset(){
  // cout << "Following percussion instrument instance destructed: " << instrumentType << "\n";
}

void Drumset::shortDecay(){
  cout << instrumentType << " will have a short decay\n";
}
