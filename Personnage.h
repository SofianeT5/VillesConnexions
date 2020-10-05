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

 public:
  std::string type;
  Lieu* lieu;
  Lieu** itineraire;
  int tailleItineraire;
  Personnage();
  Personnage(std::string, Lieu*, Lieu**, int, std::string);
  void parle(const std::string);
  void deplace(connectionType_t mt, const Lieu* l);
  void interagir(Personnage**, int);
  virtual void interagit (Personnage&);
  void setNom(std::string name);
  std::string getNom();
  ~Personnage();
};

#endif
