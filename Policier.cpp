#include <iostream>
#include <string>
#include <stdlib.h>
#include "Personnage.h"
#include "Policier.h"
#include "Gangster.h"
#include "Carte.h"
using namespace std;

Policier::Policier(string name , Lieu* l, string t, Carte c) : Personnage(name, l, t)
{
  this->map=c;
  this->reputation=rand() % 11;
  this->itineraire=genererItineraire(l, c);
  this->parle("Je suis le policier " + this->getNom() + " et j'assure la sécurité de '" + this->lieu->getNom() + "'.");
}

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

void Policier::deplace()
{
  int i=0;
  while (this->itineraire[i]!=this->lieu)
    i++;
  if (i==TAILLE_ITINERAIRE-1)
    i=0;
  this->Personnage::deplace(ALL, this->itineraire[i+1]);
}

Lieu** Policier::genererItineraire(Lieu* l, Carte c)
{
  Lieu** itineraire=(Lieu**)malloc(TAILLE_ITINERAIRE*sizeof(Lieu*));
  itineraire[0]=l;
  Lieu* tmp = l;
  long i=1, j=0;
  while(i<TAILLE_ITINERAIRE)
    {
      j=rand()%(c.nbVilles);
      if(i<TAILLE_ITINERAIRE-1 && (tmp->distance(BATEAU, *(c.villes[j]))>0 || tmp->distance(TRAIN, *(c.villes[j]))>0) && tmp!=c.villes[j])
	{
	  itineraire[i]=c.villes[j];
	  tmp=c.villes[j];
	  i++;
	}
      else if (i==TAILLE_ITINERAIRE-1 && (tmp->distance(BATEAU, *(c.villes[j]))>0 || tmp->distance(TRAIN, *(c.villes[j]))>0) && ((c.villes[j])->distance(BATEAU, *itineraire[0])>0 || (c.villes[j])->distance(TRAIN, *itineraire[0])>0) && tmp!=c.villes[j] )
	{
	  itineraire[i]=c.villes[j];
	  tmp=c.villes[j];
	  i++;
	}
      else
	continue;
    }
  return itineraire;
}

void Policier::incrementePopularite()
{
  this->setRep(this->getRep()+1);
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
