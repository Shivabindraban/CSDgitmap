#include "percussion.h"
#include "strings.h"
// #include <iostream>
using namespace std;

int main(){
  Percussion percussion1("BassKick", "20-20000");
  Percussion percussion2("Snare", "200-500");
  Strings string1("Guitar", "200-2000");
  Strings string2("violin", "400-4000");
  Strings string3("ViolinPluck, 200-500");

  percussion1.play("boom", "50");
  percussion2.play("kets". "400");
  string1.play("ting", "50");
  string2.play("ieh", "600");
  string3.play("ploek", "300");
  string3.pluck();
  return 0;
}
