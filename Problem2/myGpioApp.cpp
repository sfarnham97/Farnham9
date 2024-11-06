/*
myGpioApp.cpp
This is a program made to excersize the myGpio.h and myGpio.cpp
class, which is used to handle pins on the beagle bone black
it also solves all the parts of problem 2 part 3 on HW9

made by Shawn Farnham on 11-6-24
*/

#include <iostream>
#include <fstream>
#include <unistd.h>
#include "myGpio.h"

int main(){
  //setting up pin 9_12, as output for part a
  myGpio objectA(60);
  objectA.setDirection(OUT);
  //seting up pin 8.16 as input for part b
  myGpio objectB(46);
  objectB.setDirection(IN);
  //setting 9_12 to high, then waiting 3 seconds and setting it low for c
  objectA.setValue(HIGH);
  cout << "pin 9.12 value: " << objectA.getValue() << endl;
  sleep(3);
  objectA.setValue(LOW);
  cout << "pin 9.12 value: " << objectA.getValue() << endl;
  //reading and printing value of 8.16 for part d
  cout << "pin 8.16 value: " << objectB.getValue() << endl;

  return 0;
}
