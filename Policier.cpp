#include <iostream>
#include <string>
#include <stdlib.h>
#include "Personnage.h"
#include "Policier.h"
#include "Gangster.h"
#include "Carte.h"
using namespace std;

Policier::Policier(string name , Lieu* l, Lieu** it, int taille, string t) : Personnage(name, l, it, taille, t)
{
  this->reputation=rand() % 11;
  this->parle("Je suis le policier " + this->getNom() + " et j'assure la sécurité de '" + this->lieu->getNom() + "'.");
}

/*
long Policier::interagit (Gangster& p)
{
  if (!(p.en_prison))
    { 
      dynamic_cast<Policier*>(this)->parle(p.getNom() + ", sortez les mains en l'air!");
      if (this->getRep() >= p.getRecompense())
	{
	  this->incrementePopularite();
	  p.effaceRecompense();
	  this->parle(p.getNom() + ", je vous arrête. Vous avez le droit de garder le silence.");
	  p.emprisonne();
	}
      else
	{
	  this->decrementePopularite();
	  p.augmenteRecompense();
	  p.parle("Tu crois vraiment pouvoir vaincre le gang " + p.gang + ".");
	}
    }
  else
    p.evade();
  return this->getRep();
}
*/

void Policier::interagit (Personnage& pe)
{
  if (pe.type == "GANGSTER")
  {
    Gangster* p = static_cast<Gangster*>(&pe);

    if (!(p->en_prison))
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
        p->parle("Tu crois vraiment pouvoir vaincre le gang " + p->gang + ".");
      }
    }
    else
      p->evade();
  }
  //return this->getRep();
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

long Policier::getRep()
{
  return this->reputation;
}

void Policier::setRep(long i)
{
  this->reputation=i;
}
