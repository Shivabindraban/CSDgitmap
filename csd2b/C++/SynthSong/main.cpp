#include <iostream>
#include <thread>
#include "sine.h"

using namespace std;

int main(int argc, char **argv){
  Sine sine1;
  sine1.frequency(220);
  sine1.amplitude(0.5);

  return 0;
}
