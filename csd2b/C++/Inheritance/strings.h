#include "instrument.h"
using namespace std;

class Strings : public Instrument{
public:
  Strings(string instrumentType); //Constructor
  ~Strings();//Deconstructor

  void pluck();
};
