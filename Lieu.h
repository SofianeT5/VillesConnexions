#ifndef _LIEU_H
#define _LIEU_H

#include <iomanip>
#include <iostream>
#include <string>


enum connectionType_t{NONE, TRAIN, BATEAU, ALL};

class Lieu{
 private:
  Lieu** bateau;
  Lieu** train;
  std::string name;
  long numero;
  long nbBateau;
  long nbTrain;
  static long compteur;

 public:
  Lieu();
  Lieu(std::string);
  void addConnexion(connectionType_t, Lieu*);
  void removeConnexion(connectionType_t, Lieu*);
  bool estAccessible(connectionType_t, const Lieu&);
  long distance(connectionType_t, const Lieu&);
  ~Lieu();

  void setNom(std::string n){this->name = n;}
  std::string getNom(){return this->name;}
  Lieu** getBateau(){return this->bateau;}
  Lieu** getTrain(){return this->train;}
  long getNbBateau(){return this->nbBateau;}
  long getNbTrain(){return this->nbTrain;}
  void setNbBateau(long n){this->nbBateau=n;}
  void setNbTrain(long n){this->nbTrain=n;}
  

};

#endif
