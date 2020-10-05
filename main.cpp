#include <iomanip>
#include <iostream>
#include <string>
#include "Scenario.h"
#include <time.h>

using namespace std;

int main()
{
  /*
  Lieu *l1 = new Lieu("Paris");
  Lieu *l2 = new Lieu("Lyon");
  Lieu *l3 = new Lieu("Marseille");
  l1->addConnexion(TRAIN, l2);
  l2->addConnexion(TRAIN, l3);
  long distance = l1->distance(TRAIN,*(l2)) ;
  cout << "distance : " << distance << endl;
  delete l1;
  delete l2;
  delete l3;
  */
  srand(time(NULL));
  Scenario* s = new Scenario();
  s->initScenario();
  s->scene();
 
  return 0;
}
