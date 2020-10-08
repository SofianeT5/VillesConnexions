#ifndef _GANGSTER_H
#define _GANGSTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"
#include "Pigeon.h"

enum gang_t {AKATSUKI, KONOHA, SHINOBI, SAMURAI, last_element};

class Gangster : public Personnage{
 private:
  long recompense;
  gang_t gang;
  bool en_prison;
  long temps;

 public:
  Gangster(std::string, Lieu*, Lieu**, int, type_t, gang_t);
  void interagit(Personnage&);
  void emprisonne();
  void evade();
  void deplace();
  void augmenteRecompense();
  void effaceRecompense();
  long getRecompense(){return this->recompense;}
  void setRecompense(long r){this->recompense = r;}
  gang_t getGang(){return this->gang;}
  void setGang(gang_t g){this->gang = g;}
  bool getEnPrison(){return this->en_prison;}
  void setEnPrison(bool b){this->en_prison=b;}
  long getTemps(){return this->temps;}
  void setTemps(long t){this->temps = t;}
  std::string gangToString();
  bool testGangster(Gangster& p);
};

#endif
