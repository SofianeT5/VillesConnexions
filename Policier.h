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
  Lieu** genererItineraire(Lieu*, Carte);
  Policier(std::string, Lieu*, std::string, Carte);
  virtual long interagit (Gangster&);
  void deplace();
  void incrementePopularite();
  void decrementePopularite();
  long getRep();
  void setRep(long);
};

#endif
