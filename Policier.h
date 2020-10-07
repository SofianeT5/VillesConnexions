#ifndef _POLICIER_H
#define _POLICIER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"
#include "Gangster.h"

class Policier : public Personnage{
 private:
  long reputation;
  
 public:
  Policier(std::string, Lieu*, Lieu**, int, type_t);
  void interagit (Personnage&);
  void incrementePopularite();
  void decrementePopularite();
  long getRep(){return this->reputation;}
  void setRep(long rep){this->reputation = rep;}
};

#endif
