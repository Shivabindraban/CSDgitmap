#include <iostream>
#include "instrument_class.h"
using namespace std;
// [return valuetype] functionName(parameters)

//van de Oscillator class, wordt hieronder Oscillator() constructor en destructor gedefined
Instrument::Instrument(int instrumentNumber)
{
  cout << "\nInstrument - Constructor\n";
  // this->instrumentNumber = instrumentNumber;
  if (instrumentNumber == 1)
  {
    klank = "BassKick";
  }
  else if (instrumentNumber == 2)
  {
    klank = "Snare";
  }
  else if (instrumentNumber > 2)
  {
    klank = "Not assigned";
  }
  // cout == console out
} // dit kan ook in de constructor
Instrument::~Instrument()
{
  cout << "\nInstrument - Destructor\n";
}

int Instrument::play()
{
  cout << klank << endl;
  return 0;
}
// void Oscillator::setFreq(float freq)
// {
//   if(freq< 0 || freq > 22050)
//   {
//   cout << "ERROR - unable to set frequency\n";
//   return;
//   }
//   this->freq = freq;
// }
// float Oscillator::getFreq()
// {
//   return freq;
// }
