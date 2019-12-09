#include "instrument.h"
using namespace std;

class Percussion : public Instrument{
public:
  Percussion(string instrumentType, string freqRange); //Constructor
  ~Percussion();//Deconstructor

  void pluck(); //method
};
