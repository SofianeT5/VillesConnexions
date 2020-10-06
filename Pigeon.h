#ifndef _PIGEON_H
#define _PIGEON_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"
#include "Gangster.h"
#include "Carte.h"

//class Gangster;

class Pigeon : public Personnage{
 private:
  long argent;
  
 public:
  std::string type;
  long vol_count;
  long visite_count;
  Carte map;
  Lieu** itineraire;
  Pigeon(std::string, Lieu*, Lieu**, int, std::string);
  void interagit(Personnage&);
  void deplace();
  void subirVol(long i);
  void oublierVol();
  long getArgent();
  void setArgent(long);
};

#endif
