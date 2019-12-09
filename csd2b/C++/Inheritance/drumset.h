#include "instrument.h"
using namespace std;

class Drumset : public Instrument{
public:
  Drumset(string instrumentType); //Constructor
  ~Drumset();//Deconstructor

  void shortDecay();
};
