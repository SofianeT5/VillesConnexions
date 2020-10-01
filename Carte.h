#ifndef _CARTE_H
#define _CARTE_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"

class Carte{
 private:

 public:
  Lieu** villes;
  long nbVilles;
  Carte();
  Lieu* addLieu(std::string);
  Lieu* getLieu(std::string);
  void addConnexion(connectionType_t, Lieu*, Lieu*);
  void removeConnexion(connectionType_t, Lieu*, Lieu*);
  ~Carte();
};

#endif
