#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Personnage.h"


Personnage::Personnage(string n)
{
  this->name=n;
  this->parle("Bonjour, je suis " + n + " et je viens d'arriver en ville.");
}

void Personnage::parle(const string text)
{
  cout << text << endl;
}

Personnage::~Personnage()
{
  this->parle("Il n'y a plus rien à faire ici pour moi, " + this->name + ". Adieu!");
}
