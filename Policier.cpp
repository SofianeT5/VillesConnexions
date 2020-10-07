#include <iostream>
#include <string>
#include <stdlib.h>
#include "Policier.h"

using namespace std;

Policier::Policier(string name , Lieu* l, Lieu** it, int taille, type_t t) : Personnage(name, l, it, taille, t)
{
  this->reputation=rand() % 11;
  this->parle("Je suis le policier " + this->getNom() + " et j'assure la sécurité de '" + this->lieu->getNom() + "'.");
}


void Policier::interagit (Personnage& pe)
{
  if (pe.getType() == GANGSTER)
  {
    Gangster* p = static_cast<Gangster*>(&pe);

    if (!(p->getEnPrison()))
    { 
      this->parle(p->getNom() + ", sortez les mains en l'air!");
      if (this->getRep() >= p->getRecompense())
      {
        this->incrementePopularite();
        p->effaceRecompense();
        this->parle(p->getNom() + ", je vous arrête. Vous avez le droit de garder le silence.");
        p->emprisonne();
      }
      else
      {
        this->decrementePopularite();
        p->augmenteRecompense();
        p->parle("Tu crois vraiment pouvoir vaincre le gang " + p->getGang() + ".");
      }
    }
    else
      p->evade();
  }
}

void Policier::incrementePopularite()
{
  //this->setRep(this->getRep()+1);
  this->reputation += 1;
}

void Policier::decrementePopularite()
{
  this->setRep(this->getRep()-1);
}

