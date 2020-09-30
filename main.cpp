#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Personnage.h"
#include "Carte.h"

int main()
{
  /* Personnage *m = new Personnage("Mohamed");
  delete m;
  Personnage *s = new Personnage("Sofiane");
  delete s;*/
  Carte* map = new Carte();
  Lieu* l1 = map->addLieu("Paris");
  Lieu* l2 = map->addLieu("Lyon");
  Lieu* l3 = map->addLieu("Marseille");
  map->addConnexion(TRAIN, l1, l2);
  map->addConnexion(BATEAU, l2, l3);
  map->addConnexion(TRAIN, l3, l1);
  map->removeConnexion(TRAIN, l3, l1);
  cout << l1->nbTrain << endl;
  /*
  Lieu *l1 = new Lieu("Paris");
  Lieu *l2 = new Lieu("Lyon");
  Lieu *l3 = new Lieu("Marseille");
  l1->addConnexion(TRAIN, l2);
  l2->addConnexion(BATEAU, l3);
  l3->addConnexion(TRAIN, l1);
  l3->removeConnexion(TRAIN, l1);
  cout << l1->nbTrain << endl;
  delete l1;
  delete l2;
  delete l3;
  */
  return 0;
}
