#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"

using namespace std;


Personnage::Personnage()
{
    this->name="Personne";
}
Personnage::Personnage(string n)
{
  this->name=n;
  this->parle("Bonjour, je suis " + n + " et je viens d'arriver en ville.");
}

void Personnage::parle(const string text)
{
  cout << text << endl;
}

/*
void Personnage::deplace(string destination, const Lieu* l)
{
  if (this->lieu->Lieu::distance(destination, &l)==-1)
    
}
*/

Personnage::~Personnage()
{
  this->parle("Il n'y a plus rien à faire ici pour moi, " + this->name + ". Adieu!");
}
