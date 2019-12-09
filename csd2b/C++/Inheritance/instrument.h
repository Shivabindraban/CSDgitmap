// In de .h files voeg je de classes toe
#ifndef _INS_H_
#define _INS_H_

using namespace std;
#include <string>

class Instrument
{
public:
  Instrument(string instrumentType, string freqRange); // constructor
  ~Instrument(); // destructor

  // method declarations (functies)
  void play(string sound, string frequency);


  // fields (variabelen aanmaken)

protected: // het is protected ipv private, zodat andere subclasses ervan kan lenen.
  string instrumentType;
  string freqRange;
  string sound;
  string frequency;
};

#endif
