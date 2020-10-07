#include <iostream>
#include <string>
#include <stdlib.h>
#include "Pigeon.h"

using namespace std;

Pigeon::Pigeon(string name , Lieu* l, Lieu** it, int taille, type_t t) : Personnage(name, l, it, taille, t)
{
  this->argent=rand() % 1001;
  this->vol_count=0;
  this->visite_count=0;
  this->parle("Je suis " + this->getNom() + " et je suis riche :)!");
}

void Pigeon::interagit(Personnage& p)
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


void Pigeon::deplace()
{
  this->Personnage::deplace();
  this->visite_count++;
}
