#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H

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
  void setNom(std::string name);
  ~Personnage();
};

#endif
