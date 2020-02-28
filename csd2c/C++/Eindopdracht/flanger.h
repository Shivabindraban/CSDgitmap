#ifndef _FLANGER_H_
#define _FLANGER_H_

#include <iostream>
#include "math.h"
using namespace std;

class flanger {
public:
 flanger();
 ~flanger();

 float getSample(float input);

};
#endif
