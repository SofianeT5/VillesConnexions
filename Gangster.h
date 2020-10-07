#ifndef _GANGSTER_H
#define _GANGSTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"
#include "Pigeon.h"
#include "Carte.h"


class Gangster : public Personnage{
 private:
  long recompense;
  std::string gang;
  bool en_prison;
  long temps;

 public:
  Gangster(std::string, Lieu*, Lieu**, int, type_t,std::string);
  Carte map;
  void interagit(Personnage&);
  void emprisonne();
  void evade();
  void deplace();
  void augmenteRecompense();
  void effaceRecompense();
  long getRecompense(){return this->recompense;}
  void setRecompense(long r){this->recompense = r;}
  std::string getGang(){return this->gang;}
  void setGang(std::string g){this->gang = g;}
  bool getEnPrison(){return this->en_prison;}
  void setEnPrison(bool b){this->en_prison=b;}
  long getTemps(){return this->temps;}
  void setTemps(long t){this->temps = t;}
  bool testGangster(Gangster& p);
};

#endif
