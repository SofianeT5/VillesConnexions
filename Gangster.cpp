#include <iostream>
#include <string>
#include <stdlib.h>
#include "Gangster.h"
#include "Pigeon.h"
#include "Carte.h"

using namespace std;

Gangster::Gangster(string name, Lieu* l, Lieu** it, int taille, string t, string gang) : Personnage(name, l, it, taille, t)
{
  this->gang=gang;
  this->recompense=rand() % 11;
  this->en_prison=false;
  this->parle("Je suis " + this->getNom() + ", membre du gang '" + this->gang + "'.");
}

/*
void Gangster::interagit(Gangster& p)
{
  if( (this->gang == p.gang) && (this->getRecompense() < p.getRecompense()) )
    this->parle("Mes respects, " + p.getNom() + "-dono.");
}
*/

void Gangster::interagit(Personnage& pe)
{
  if (pe.type == "PIGEON")
  {
    Pigeon* p = static_cast<Pigeon*>(&pe);

    if(rand()%2==0)
      this->parle("Hey, " + p->getNom() + ", ça te dirait de articiper à mon culte du jus d'ananas?");
    else
      this->parle("Hey, " + p->getNom() + ", viens voir ma mine de charbon, on y est confortable!");
    if(p->vol_count<2)
      p->interagit(*this);
    else
      p->oublierVol();
  }
  if(pe.type == "GANGSTER")
  {
    Gangster* p = static_cast<Gangster*>(&pe);
    if( (this->gang == p->gang) && (this->getRecompense() < p->getRecompense()) )
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

long Gangster::getRecompense()
{
  return this->recompense;
}


