#ifndef _PIGEON_H
#define _PIGEON_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Gangster.h"
#include "Carte.h"


class Pigeon : public Personnage{
 private:
  long argent;
  long vol_count;
  long visite_count;
  
 public:
  Pigeon(std::string, Lieu*, Lieu**, int, type_t);
  Carte map;
  void interagit(Personnage&);
  void deplace();
  void subirVol(long i);
  void oublierVol();
  long getArgent(){return this->argent;}
  void setArgent(long ar){this->argent = ar;}
  void setVolCount(long v){this->vol_count = v;}
  long getVolCount(){return this->vol_count;}
  void setVisitCount(long v){this->visite_count = v;}
  long getVisitCount(){return this->visite_count;}
};

#endif
