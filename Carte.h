#ifndef _CARTE_H
#define _CARTE_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"

class Carte{
 private:
  Lieu** villes;
  long nbVilles;

 public:
  Carte();
  Lieu* addLieu(std::string);
  Lieu* getLieu(std::string);
  void addConnexion(connectionType_t, Lieu*, Lieu*);
  void removeConnexion(connectionType_t, Lieu*, Lieu*);
  Lieu** getVilles(){return this->villes;}
  void setVilles(Lieu** v){this->villes = v;}
  long getNbVilles(){return this->nbVilles;}
  void setNbVilles(long n){this->nbVilles = n;}
  ~Carte();
};

#endif
