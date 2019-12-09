#include <iostream>
#include "inheritance.h"
using namespace std;
// [return valuetype] functionName(parameters)


Instrument::Instrument(string instrumentName)
{
  cout << "\nInstrument - Constructor\n";
  this->instrumentName = instrumentName;
  cout << "Following instrument instance created: " << instrumentName << "\n";


}
Instrument::~Instrument()
{
  cout << "\nInstrument - Destructor\n";
}

void Instrument::play()
{
  cout << sound << endl;
}
