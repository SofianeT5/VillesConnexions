#include <iomanip>
#include <iostream>
#include <string>
#include "Lieu.h"

class Personnage{
 private:
  std::string name;
  std::string text;
  Lieu* lieu;

 public:
  Personnage();
  Personnage(std::string);
  void parle(const std::string);
  void deplace(connectionType_t mt, const Lieu* l);
  ~Personnage();
};
