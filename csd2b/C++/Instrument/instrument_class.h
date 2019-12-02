// In de .h files voeg je de classes toe
using namespace std;
#include <string>

class Instrument
{
public:
  Instrument(int instrumentNumber); // constructor
  ~Instrument(); // destructor
  int play();

  // method declarations (functies)
  // fields (variabelen aanmaken)
private:
  string klank;
};
