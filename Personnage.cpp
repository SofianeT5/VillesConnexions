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
  cout <<setw(10) << this->getNom() << left << ": " << text << endl;
}

void Personnage::deplace()
{
    string moyen = "";
    int destination;
    if (this->position >= (this->tailleItineraire)-1 )
    {
      destination = 0;
    }else
    {
      destination = this->position+1;
    }
    moyen = (this->lieu->estAccessible(TRAIN,*(this->itineraire[destination])))? "train" : "bateau" ;
    this->lieu = this->itineraire[destination];
    this->parle("Je vais à " +this->lieu->getNom() + " en prenant 1 "+ moyen +".");
    this->position = destination;

}


void Personnage::interagir(Personnage **p, long nb_personnes)
{
  for (long i=0; i<nb_personnes; i++)
  {
    if ( (this->lieu->getNom() == p[i]->getLieu()->getNom()) && this!=p[i])
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


bool Personnage::testPersonnage(Personnage& p)
{
  // On teste si sa position ne depasse pas la taille de son itineraire
  if (this->getPosition() >= this->getTailleItineraire())
    return false;

  Lieu** itineraire = this->getItineraire();
  int taille = this->getTailleItineraire();

  this->setLieu(itineraire[0]);
  this->setPosition(0);

  // On teste si son itineraire ne contient aucun pointeur sur Lieu NULL et que la fonction deplace marche bien comme il se doit
  for (int i = 0 ; i < taille; i++)
  {
    if (itineraire[i] == NULL || this->getLieu() != itineraire[this->getPosition()])
      return false;
    this->deplace();
  }
  return true;
}
