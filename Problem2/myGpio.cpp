/*
myGpio.cpp
This program is the impementaion of myGpio.h's class contract
this program is made to handle input and output pins on the beagle bone black

made by Shawn Farnham on 11-6-2024
*/

#include <iostream>
#include <fstream>
#include "myGpio.h"

using namespace std;

//enum GPIO_DIRECTION{IN, OUT};
//enum GPIO_VALUE{LOW, HIGH};
//constructer
myGpio::myGpio(int number){
  this->number = number;
  path = "/sys/class/gpio/gpio" + to_string(number) + "/";
}

int myGpio::getNumber(){
  return number;
}

void myGpio::setDirection(GPIO_DIRECTION dir){
  if(dir == 0){
    write(path, "direction", "in");
  }
  if(dir == 1){
     write(path, "direction", "out");
  }
}

GPIO_DIRECTION myGpio::getDirection(){
  string temp = read(path, "direction");
  if (temp == "in"){ 
    return IN;
  }
 // if (temp == "out"){
  else
   return OUT; 
}

void myGpio::setValue(GPIO_VALUE val){
  if (val == 0){
    write(path, "value", 0);
  }
  else
    write(path, "value", 1);
}

GPIO_VALUE myGpio::getValue(){
  string temp = read(path, "value");
  if (temp == "0"){
    return LOW;
  }
  return HIGH;
}

void myGpio::toggleOutput(){
  string temp = read(path, "value");
  if (temp == "0"){
    write(path, "value", 1);
  }
  else
    write(path, "value", 0);
}
//deconstructer
myGpio::~myGpio(){
}

int myGpio::write(string path, string filename, string value){
  fstream fs;
  fs.open((path + filename).c_str(), fstream::out);
  fs << value;
  fs.close();
  return 0;
}

int myGpio::write(string path, string filename, int value){
  fstream fs;
  fs.open((path + filename).c_str(), fstream::out);
  fs << to_string(value);
  fs.close();
  return 0;
}

string myGpio::read(string path, string filename){
  fstream fs;
  fs.open((path + filename).c_str(), fstream::in);
  string temp;
  getline(fs, temp, '\n');
  fs.close();
  return temp;
}


