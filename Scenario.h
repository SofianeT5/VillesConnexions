#ifndef _SCENARIO_H
#define _SCNEARIO_H

#include <iomanip>
#include <iostream>
#include <string>
#include "Carte.h"

class Scenario{
 private:
  Carte carte;
  Personnage** personnages;
  long nbPers;

 public:
  Scenario();
  ~Scenario();
  Carte getCarte();
  Personnage getPersonnage(std::string name);
  long getNbPers();
  void initPersonnages();
  void initCarte();
  void initScenario();
};

#endif
