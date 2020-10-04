#include <stdlib.h>
#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"
#include "Policier.h"
#include "Gangster.h"
#include "Pigeon.h"
#include "Lieu.h"
using namespace std;

Personnage::Personnage(string n="Personne", Lieu *l=NULL, string type="AUCUN")
{
  this->name=n;
  this->lieu=l;
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

void Personnage::deplace(connectionType_t mt, const Lieu* l)
{
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
}

void Personnage::interagir(Personnage **p, int nb_personnes)
{
  for (int i=0; i<nb_personnes; i++)
    if ( (this->lieu->getNom() == p[i]->lieu->getNom()) && (this!=p[i]) )
      {
	if (this->type=="POLICIER" && p[i]->type=="GANGSTER")
	  static_cast<Policier*>(this)->Policier::interagit(static_cast<Gangster&>(*(p[i])));
	if (this->type=="GANGSTER" && p[i]->type=="GANGSTER")
	  static_cast<Gangster*>(this)->Gangster::interagit(static_cast<Gangster&>(*(p[i])));
	if (this->type=="GANGSTER" && p[i]->type=="PIGEON")
	  static_cast<Gangster*>(this)->Gangster::interagit(static_cast<Pigeon&>(*(p[i])));
      }
}

void Personnage::interagit(Personnage& p){}

Personnage::~Personnage()
{
  this->parle("Il n'y a plus rien à faire ici pour moi, " + this->name + ". Adieu!");
}

