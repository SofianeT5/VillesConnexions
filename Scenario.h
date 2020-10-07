#ifndef _SCENARIO_H
#define _SCNEARIO_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Carte.h"

class Scenario{
 private:
  Personnage** personnages;
  long nbPers;
  int* taille;
  Carte carte;
  Lieu*** itineraires;

 public:
  Scenario(int);
  ~Scenario();
  Personnage getPersonnage(std::string name);
  void initPersonnages(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon);
  void initCarte();
  void initScenario(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon);
  void scene();
  void simulation(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon, long nb_scene);
  void initItineraires();


  long getNbPers(){return this->nbPers;}
  Lieu*** getItineraires(){return this->itineraires;}
  int* getTaille(){return this->taille;}
};

#endif
