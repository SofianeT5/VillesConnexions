#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"
#include "Lieu.h"
using namespace std;

Personnage::Personnage(string n="Personne", Lieu *l=NULL, Lieu** itineraire=NULL, int taille=0, string type="AUCUN")
{
  this->name=n;
  this->itineraire = itineraire;
  this->lieu = this->itineraire[0];
  this->position = 0;
  this->tailleItineraire = taille;
  this->type=type;
  //this->parle("Bonjour, je suis " + n + " et je viens d'arriver en ville.");
}

void Personnage::setNom(string name)
{
  this->name=name;
}

string Personnage::getNom()
{
  return this->name;
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

    /*
    long b = this->lieu->distance(BATEAU,*l);
    long t = this->lieu->distance(TRAIN,*l);
    long n = 0;
    if (b<t && b!=-1)
      n=b;
    else
      n=t;
    if(n==-1)
      if(n == t)
        this->parle("Zut! Je me suis trompé de train, celui-ci ne va pas à " + const_cast<Lieu*>(l)->getNom() + ".");
      else
        this->parle("Zut! Je me suis trompé de bateau, celui-ci ne va pas à " + const_cast<Lieu*>(l)->getNom() + ".");
    else if(n==0)
      this->parle("Je reste sur place.");
    else
      {
        if(n == b)
          this->parle("Je vais à " + const_cast<Lieu*>(l)->getNom() + " en prenant " + to_string(n) + " bateau(x).");
        else
          this->parle("Je vais à " + const_cast<Lieu*>(l)->getNom() + " en prenant " + to_string(n) + " train(s).");
        this->lieu = const_cast<Lieu*>(l);
      }
    */
}


void Personnage::interagir(Personnage **p, long nb_personnes)
{
  for (long i=0; i<nb_personnes; i++)
  {
    if ( (this->lieu->getNom() == p[i]->lieu->getNom()) && this!=p[i])
      {
        //this->interagit(*(p[i]));
        if (this->type=="POLICIER" && p[i]->type=="GANGSTER")
          this->interagit(*(p[i]));
        if (this->type=="GANGSTER" && p[i]->type=="GANGSTER")
          this->interagit(*(p[i]));
        if (this->type=="GANGSTER" && p[i]->type=="PIGEON")
          this->interagit(*(p[i]));
      
      }
  }
}

void Personnage::interagit(Personnage& p){}

Personnage::~Personnage()
{
  this->parle("Il n'y a plus rien à faire ici pour moi, " + this->name + ". Adieu!");
}

