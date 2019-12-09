#include "instrument.h"
using namespace std;

class Percussion : public Instrument{
public:
  Percussion(string instrumentType); //Constructor
  ~Percussion();//Deconstructor

  void pitchGlide(); //method
  void shortDecay();
};
