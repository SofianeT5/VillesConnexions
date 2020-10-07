#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"
#include "Lieu.h"
using namespace std;

Personnage::Personnage(string n="Personne", Lieu *l=NULL, Lieu** itineraire=NULL, int taille=0, type_t type=AUCUN): name(n), itineraire(itineraire), lieu(itineraire[0]), position(0), tailleItineraire(taille), type(type)
{
}

void Personnage::parle(const string text)
{
  cout << this->getNom() << ": " << text << endl;
}

void Personnage::deplace()
{
    string moyen = "";

    if (this->position == this->tailleItineraire )
    {
      this->position = 0;
    }
    moyen = (this->lieu->estAccessible(TRAIN,*(this->itineraire[this->position+1])))? "train" : "bateau" ;
    this->lieu = this->itineraire[this->position++];
    this->parle("Je vais à " + this->lieu->getNom() + " en prenant 1 "+ moyen +".");

}


void Personnage::interagir(Personnage **p, long nb_personnes)
{
  for (long i=0; i<nb_personnes; i++)
  {
    if ( (this->lieu->getNom() == p[i]->lieu->getNom()) && this!=p[i])
      {
        if (this->type==POLICIER && p[i]->getType()==GANGSTER)
          this->interagit(*(p[i]));
        if (this->type==GANGSTER && p[i]->getType()==GANGSTER)
          this->interagit(*(p[i]));
        if (this->type==GANGSTER && p[i]->getType()==PIGEON)
          this->interagit(*(p[i]));
      
      }
  }
}

void Personnage::interagit(Personnage& p){}

Personnage::~Personnage()
{
  this->parle("Il n'y a plus rien à faire ici pour moi, " + this->name + ". Adieu!");
}

