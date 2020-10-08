#include <iomanip>
#include <iostream>
#include <string>
#include "Scenario.h"
#include <stdlib.h>
#include <time.h>
using namespace std;


int main()
{
  srand(time(NULL));

  string noms_gangster[]={"Kabutooo","Orochimaru","Tobi", "Madara"};
  string noms_policier[]={"Konohamaru","Shisui", "Minato", "Itachi", "Kakashi"};
  string noms_pigeon[]={"KillerBee","Sasuke","Hashirama", "Pain", "Hiruzen"};

  int nb_gangster=sizeof(noms_gangster)/sizeof(string), nb_policier=sizeof(noms_policier)/sizeof(string), nb_pigeon=sizeof(noms_pigeon)/sizeof(string);
  Scenario* s = new Scenario(nb_gangster,nb_policier,nb_pigeon,noms_gangster,noms_policier,noms_pigeon);
  s->simulation(noms_gangster, nb_gangster, noms_policier, nb_policier, noms_pigeon, nb_pigeon, 5);
  delete s;
  return 0;
}

