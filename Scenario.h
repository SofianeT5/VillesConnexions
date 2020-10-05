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

 public:
  Carte carte;
  Scenario();
  ~Scenario();
  Personnage getPersonnage(std::string name);
  long getNbPers();
  void initPersonnages(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon);
  void initCarte();
  void initScenario(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon);
  void scene();
  void simulation(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon, long nb_scene);
};

#endif
