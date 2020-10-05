#include <iomanip>
#include <iostream>
#include <string>
#include "Scenario.h"
#include <time.h>
using namespace std;

#define NB_GANGSTER 2
#define NB_POLICIER 4
#define NB_PIGEON 3

int main()
{
  srand(time(NULL));

  long nb_gangster=NB_GANGSTER, nb_policier=NB_POLICIER, nb_pigeon=NB_PIGEON;
  string noms_gangster[NB_GANGSTER]={"Tobi", "Madara"};
  string noms_policier[NB_POLICIER]={"Shisui", "Minato", "Itachi", "Kakashi"};
  string noms_pigeon[NB_PIGEON]={"Hashirama", "Pain", "Hiruzen"};

  Scenario* s = new Scenario();
  s->simulation(noms_gangster, nb_gangster, noms_policier, nb_policier, noms_pigeon, nb_pigeon, 5);
  return 0;
}

