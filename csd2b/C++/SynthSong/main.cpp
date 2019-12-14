#include <iostream>
#include <thread>
#include "sine.h"

using namespace std;

int main(int argc, char **argv){
  Sine sine1;
  sine1.setFrequency(220);
  sine1.setAmplitude(0.5);

  return 0;
}
