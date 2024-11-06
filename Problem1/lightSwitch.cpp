/*
simpleLight.cpp
This program is designed to be a simpe button operated light. it assumes
that the light is wired to pin9_12 and the button is on pin8_16, and that both
pins are configured to inputpullup and output respectivly. 
when the button is pressed the light turns on else it is of. this program runs
until the user cancels it with control C
Made by Shawn Farnham on 11-4-24
*/

#include <iostream>
#include <fstream>

using namespace std;

#define LED_PATH "/sys/class/gpio/gpio60/"
#define BUTTON_PATH "/sys/class/gpio/gpio46/"

void writeLED(string filename, string value){
  fstream fs;
  string path(LED_PATH);
  fs.open((path + filename).c_str(), fstream::out);
  fs << value;
  fs.close();
}


string readButton(string filename){
  fstream fs;
  string path(BUTTON_PATH);
  fs.open((path + filename).c_str(), fstream::in);
  string temp;
  getline(fs, temp, '\n');
  fs.close();
  return temp;
}

int main(){
  writeLED("direction","out");
  while(1){ 
    //cout << readButton("value") << endl;
    if(readButton("value")=="0"){
      writeLED("value","1"); 
    }
    else{
    writeLED("value","0");
    } 
  }
  return 0;
}
