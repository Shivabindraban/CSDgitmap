#include "percussion.h"
#include "strings.h"
// #include <iostream>
using namespace std;

int main(){
  Percussion percussion1("BassKick");
  Percussion percussion2("Snare");
  Percussion percussion3("Tabla");
  Percussion percussion4("Tom");
  Percussion percussion5("Shakers");
  Strings string1("Guitar");
  Strings string2("violin");
  Strings string3("ViolinPluck");

  percussion1.pitch(1);
  percussion1.play("boom", "50");
  percussion2.play("kets", "400");
  percussion3.pitchGlide();
  percussion3.play("doeang", "200");
  percussion4.shortDecay();
  percussion4.play("doeng", "250");
  percussion5.pitch(3);
  percussion5.play("tsh", "9000");

  string1.pitch(2);
  string1.play("ting", "50");
  string2.play("ieh", "600");
  string3.pluck();
  string3.play("ploek", "300");

  return 0;
}
