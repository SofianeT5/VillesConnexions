#include <iomanip>
#include <iostream>
#include <string>
//#include "Lieu.h"

class Personnage{
 private:
  std::string name;
  std::string text;
  //Lieu* lieu;

 public:
  Personnage(std::string);
  void parle(const std::string);
  //void deplace(std::string, const Lieu* l);
  ~Personnage();
};
