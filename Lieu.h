#ifndef _LIEU_H
#define _LIEU_H

#include <iomanip>
#include <iostream>
#include <string>

#define N 12

enum connectionType_t{NONE, TRAIN, BATEAU, ALL};

class Lieu{
 private:
  Lieu** bateau;
  Lieu** train;
  std::string name;

 public:
  long numero;
  long nbBateau;
  long nbTrain;
  static long compteur;
  Lieu();
  Lieu(std::string);
  void setNom(std::string);
  std::string getNom();
  void addConnexion(connectionType_t, Lieu*);
  void removeConnexion(connectionType_t, Lieu*);
  bool estAccessible(connectionType_t, const Lieu&);
  long distance(connectionType_t, const Lieu&);
  ~Lieu();
};

#endif
