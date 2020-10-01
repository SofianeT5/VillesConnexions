#include <iomanip>
#include <iostream>
#include <string>
#include "Carte.h"

class Scenario{
 private:
  Carte carte;
  Personnage* personnages;
  long nbPers;

 public:

  Scenario();
  void initScenario();
  ~Scenario();
  Carte getCarte();
  Personnage getPersonnage(std::string name);
  long getNbPers();
};
