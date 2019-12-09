#include "percussion.h"
#include "strings.h"
#include "drumset.h"
// #include <iostream>
using namespace std;

int main(){
  //Construct
  Drumset drum1("BassKick");
  Drumset drum2("Snare");
  Drumset drum3("Tom");
  Drumset drum4("Fault BassKick");
  Percussion percussion1("Tabla");
  Percussion percussion2("Shakers");
  Strings string1("Guitar");
  Strings string2("violin");
  Strings string3("ViolinPluck");


  // Play
  drum1.pitch(1);
  drum1.play("boom", 50);
  drum2.play("kets", 400);
  drum3.shortDecay();
  drum3.play("doeng", 250);
  drum4.pitch(1);
  drum4.play("boom", 8000);
  percussion1.pitchGlide();
  percussion1.play("doeang", 200);
  percussion2.pitch(3);
  percussion2.play("tsh", 9000);
  string1.pitch(2);
  string1.play("ting", 50);
  string2.play("ieh", 600);
  string3.pluck();
  string3.play("ploek", 300);

  return 0;
}
