#include <iostream>
#include <string>
#include <stdlib.h>
#include "Gangster.h"
#include "Pigeon.h"
#include "Carte.h"
using namespace std;

Gangster::Gangster(string name, Lieu* l, string t, Carte c, string gang) : Personnage(name, l, t)
{
  this->map=c;
  this->gang=gang;
  this->recompense=rand() % 11;
  this->en_prison=false;
  this->itineraire=genererItineraire(l, c);
  this->parle("Je suis " + this->getNom() + ", membre du gang '" + this->gang + "'.");
}

void Gangster::interagit(Gangster& p)
{
  if( (this->gang == p.gang) && (this->getRecompense() < p.getRecompense()) )
    this->parle("Mes respects, " + p.getNom() + "-dono.");
}

void Gangster::interagit(Pigeon& p)
{
  if(rand()%2==0)
    this->parle("Hey, " + p.getNom() + ", ça te dirait de participer à mon culte du jus d'ananas?");
  else
    this->parle("Hey, " + p.getNom() + ", viens voir ma mine de charbon, on y est confortable!");
  if(p.vol_count<2)
    p.Pigeon::interagit(*this);
  else
    p.oublierVol();
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

void Gangster::deplace()
{
  int i=0;
  while (this->itineraire[i]!=this->lieu)
    i++;
  if (i==TAILLE_ITINERAIRE-1)
    i=0;
  this->Personnage::deplace(ALL, this->itineraire[i+1]);
}

Lieu** Gangster::genererItineraire(Lieu* l, Carte c)
{
  queue<Lieu*> file;
  int* level = new int[c.nbVilles];
  for (int i = 0; i < c.nbVilles ; i++)
  {
    level[c.villes[i]] = -1;
  }

  level[l] = 0;
  file.push(l);

  while(!file.empty())
  {
    Lieu* current = file.front();
    for(int i = 0 ; i < current->nbTrain ; i++)
    {
        
    }

  }



}
/*

Lieu** Gangster::genererItineraire(Lieu* l, Carte c)
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
*/
