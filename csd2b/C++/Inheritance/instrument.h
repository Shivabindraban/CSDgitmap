#ifndef _INS_H_
#define _INS_H_
#include <iostream>
using namespace std;

class Instrument{
public:
  Instrument(string instrumentType); // constructor
  ~Instrument(); // destructor

  // method declarations (functies)
  void play(string sound, int frequency);
  void pitch(int freqRange);

  // fields (variabelen aanmaken)

protected: // het is protected ipv private, zodat andere subclasses ervan kan lenen.
  string instrumentType;
  int freqRange;
  string sound;
  int frequency;
};
#endif
