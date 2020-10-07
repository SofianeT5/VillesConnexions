#ifndef _PERSONNAGE_H
#define _PERSONNAGE_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Lieu.h"

enum type_t {AUCUN, POLICIER, GANGSTER, PIGEON};

class Personnage{
 protected:
  std::string name;
  std::string text;
  type_t type;
  Lieu* lieu;
  Lieu** itineraire;
  int tailleItineraire;
  int position;

 public:
  Personnage();
  Personnage(std::string, Lieu*, Lieu**, int,type_t);
  void parle(const std::string);
  void deplace();
  void interagir(Personnage**, long);
  virtual void interagit (Personnage&);
  void setNom(std::string name){this->name = name;}
  std::string getNom(){return this->name;}
  void setType(type_t type){this->type = type;}
  type_t getType(){return this->type;}
  void setLieu(Lieu* lieu){this->lieu = lieu;}
  Lieu* getLieu(){return this->lieu;}
  void setItineraire(Lieu** it){this->itineraire = it;}
  Lieu** getItineraire(){return this->itineraire;}
  void setTailleItineraire(int t){this->tailleItineraire = t;}
  int getTailleItineraire(){return this->tailleItineraire;}
  void setPosition(int p){this->position = p;}
  int getPosition(){return this->position;}

  
  ~Personnage();
};

#endif
