#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Personnage.h"
#include "Lieu.h"

int main()
{
  Personnage *m = new Personnage("Mohamed");
  delete m;
  Personnage *s = new Personnage("Sofiane");
  delete s;
  Lieu *l1 = new Lieu("Paris");
  Lieu *l2 = new Lieu("Lyon");
  Lieu *l3 = new Lieu("Marseille");
  delete l1;
  delete l2;
  delete l3;
  return 0;
}
