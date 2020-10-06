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
  int position;
  Personnage();
  Personnage(std::string, Lieu*, Lieu**, int, std::string);
  void parle(const std::string);
  void deplace();
  void interagir(Personnage**, long);
  virtual void interagit (Personnage&);
  void setNom(std::string name);
  std::string getNom();
  ~Personnage();
};

#endif
