#include <iostream>
#include <string>
#include <stdlib.h>
#include "Gangster.h"

using namespace std;

Gangster::Gangster(string name, Lieu* l, Lieu** it, int taille, type_t t, string gang) : Personnage(name, l, it, taille, t)
{
  this->gang=gang;
  this->recompense=rand() % 10;
  this->en_prison=false;
  this->parle("Je suis " + this->getNom() + ", membre du gang '" + this->gang + "'.");
}

void Gangster::interagit(Personnage& pe)
{
  if (pe.getType() == PIGEON)
  {
    Pigeon* p = static_cast<Pigeon*>(&pe);

    if(rand()%2==0)
      this->parle("Hey, " + p->getNom() + ", ça te dirait de articiper à mon culte du jus d'ananas?");
    else
      this->parle("Hey, " + p->getNom() + ", viens voir ma mine de charbon, on y est confortable!");
    if(p->getVolCount()<2)
      p->interagit(*this);
    else
      p->oublierVol();
  }
  if(pe.getType() == GANGSTER)
  {
    Gangster* p = static_cast<Gangster*>(&pe);
    if( (this->gang == p->getGang()) && (this->recompense < p->getRecompense()) )
      this->parle("Mes respects, " + p->getNom() + "-dono.");
    
  }
}

void Gangster::emprisonne()
{
  this->en_prison=true;
}

void Gangster::evade()
{
  if(this->temps>=2)
    {
      this->en_prison=false;
      this->recompense=rand()%11;
    }
  else
    this->temps++;
}

void Gangster::augmenteRecompense()
{
  this->recompense+=2;
}

void Gangster::effaceRecompense()
{
  this->recompense=0;
}


