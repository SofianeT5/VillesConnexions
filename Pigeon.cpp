#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pigeon.h"
#include "Gangster.h"
#include "Carte.h"
using namespace std;

Pigeon::Pigeon(string name , Lieu* l, Lieu** it, int taille, string t) : Personnage(name, l, it, taille, t)
{
  this->argent=rand() % 1001;
  this->vol_count=0;
  this->visite_count=0;
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
  if (i==this->tailleItineraire-1)
    i=0;
  this->Personnage::deplace(ALL, this->itineraire[i+1]);
  this->visite_count++;
}
