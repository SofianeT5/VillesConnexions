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
  void initPersonnages();
  void initCarte();
  void initScenario();
  void scene();
};

#endif
