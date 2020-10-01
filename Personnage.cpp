#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"
#include "Lieu.h"
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

void Personnage::setNom(string name)
{
  this->name=name;
}

void Personnage::parle(const string text)
{
  cout << this->name << ": " << text << endl;
}

void Personnage::deplace(connectionType_t mt, const Lieu* l)
{
  long n = this->lieu->distance(mt,*l);
  if(n==-1)
    if(mt == TRAIN)
      this->parle("Zut! Je me suis trompé de train, celui-ci ne va pas à " + const_cast<Lieu*>(l)->getNom() + ".");
    else
      this->parle("Zut! Je me suis trompé de bateau, celui-ci ne va pas à " + const_cast<Lieu*>(l)->getNom() + ".");
  else if(n==0)
    this->parle("Je reste sur place.");
  else
    {
      if(mt == BATEAU)
        this->parle("Je vais à " + const_cast<Lieu*>(l)->getNom() + " en prenant " + to_string(n) + " bateaux.");
      else
        this->parle("Je vais à " + const_cast<Lieu*>(l)->getNom() + " en prenant " + to_string(n) + " trains.");
      this->lieu = const_cast<Lieu*>(l);
    }
}

Personnage::~Personnage()
{
  this->parle("Il n'y a plus rien à faire ici pour moi, " + this->name + ". Adieu!");
}

