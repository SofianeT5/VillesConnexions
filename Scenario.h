#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"

class Scenario{
 private:
  Carte carte;
  Personnage* personnages;

 public:
  long nbPers;
  Scenario();
  void initScenario();
  ~Scenario();
};
