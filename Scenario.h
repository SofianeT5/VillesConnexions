#ifndef _SCENARIO_H
#define _SCNEARIO_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Carte.h"

#define NB_ITINERAIRE 3

class Scenario{
 private:
  Personnage** personnages;
  int nbPers;
  int* taille;
  Carte carte;
  Lieu*** itineraires;
  int nbPolicier;
  int nbGangster;
  int nbPigeon;
  std::string* nomsGangster;
  std::string* nomsPolicier;
  std::string* nomsPigeon;


 public:
  Scenario(int,int,int,std::string*,std::string*,std::string*);
  ~Scenario();
  Personnage getPersonnage(std::string name);
  void initPersonnages(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon);
  void initCarte();
  void initScenario(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon);
  void scene();
  void simulation(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon, long nb_scene);
  void initItineraires();
  void destroyPersonnages();
  void resetPersonnages();


  long getNbPers(){return this->nbPers;}
  Lieu*** getItineraires(){return this->itineraires;}
  int* getTaille(){return this->taille;}
};

#endif
