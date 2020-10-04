#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pigeon.h"
#include "Gangster.h"
#include "Carte.h"
using namespace std;

Pigeon::Pigeon(string name , Lieu* l, string t, Carte c) : Personnage(name, l, t)
{
  this->map=c;
  this->argent=rand() % 1001;
  this->vol_count=0;
  this->visite_count=0;
  this->itineraire=genererItineraire(l, c);
  this->parle("Je suis " + this->getNom() + " et je suis riche :)!");
}

void Pigeon::interagit(Gangster& p)
{
  this->parle("Ok :)");
  this->subirVol(rand()%1001);
  this->vol_count++;
}

void Pigeon::subirVol(long i)
{
  this->setArgent(getArgent()-i);
}

void Pigeon::oublierVol()
{
  if(this->visite_count>=2)
    {
      this->vol_count=0;
      this->visite_count=0;
    }
}

long Pigeon::getArgent()
{
  return this->argent;
}

void Pigeon::setArgent(long i)
{
  this->argent=i;
}

void Pigeon::deplace()
{
  int i=0;
  while (this->itineraire[i]!=this->lieu)
    i++;
  if (i==TAILLE_ITINERAIRE-1)
    i=0;
  this->Personnage::deplace(ALL, this->itineraire[i+1]);
  this->visite_count++;
}

Lieu** Pigeon::genererItineraire(Lieu* l, Carte c)
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
