#ifndef _POLICIER_H
#define _POLICIER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"
#include "Gangster.h"
#include "Carte.h"

class Policier : public Personnage{
 private:
  long reputation;
  
 public:
  std::string type;
  Carte map;
  Lieu** itineraire;
  Policier(std::string, Lieu*, Lieu**, int, std::string);
  void interagit (Personnage&);
  void incrementePopularite();
  void decrementePopularite();
  long getRep();
  void setRep(long);
};

#endif
