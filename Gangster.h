#ifndef _GANGSTER_H
#define _GANGSTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"
#include "Pigeon.h"
#include "Carte.h"

class Pigeon;

class Gangster : public Personnage{
 private:
  long recompense;

 public:
  std::string type;
  std::string gang;
  bool en_prison;
  long temps;
  Carte map;
  Lieu** itineraire;
  Gangster(std::string, Lieu*, Lieu**, int, std::string,std::string);
  //virtual void interagit(Gangster&);
  void interagit(Personnage&);
  void emprisonne();
  void evade();
  void augmenteRecompense();
  void effaceRecompense();
  long getRecompense();
};

#endif
