/* this is the header file for the class myGpio.h
This class is designed to handle GPIO actions on the beagle bone black

made by Shawn Farnham on 11-6-2024
*/

#ifndef MYGPIO_H
#define MYGPIO_H

enum GPIO_DIRECTION{IN, OUT};
enum GPIO_VALUE{LOW, HIGH};

using namespace std;

class myGpio {
private:
  int number;
  string name, path;
  int write(string path, string filename, string value);
  int write(string path, string filename, int value);
  string read(string path, string filename);
  ofstream stream;
public:
  myGpio(int number); //constructor
  int getNumber();
  void setDirection(GPIO_DIRECTION dir);
  GPIO_DIRECTION getDirection();
  void setValue(GPIO_VALUE val);
  GPIO_VALUE getValue();
  void toggleOutput();
  ~myGpio(); //destructor
 };

#endif
