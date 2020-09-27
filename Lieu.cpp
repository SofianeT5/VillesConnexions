#include <iomanip>
#include <iostream>
#include <string>
using namespace std;
#include "Lieu.h"

long Lieu::compteur = 0;

Lieu::Lieu()
{
  this->name="nulle part";
}

Lieu::Lieu(string n)
{
  this->name=n;
  this->numero=compteur;
  Lieu::compteur++;
}

string Lieu::getNom()
{
  return this->name;
}

Lieu::~Lieu()
{
  cout << "Ville n°" << this->numero << " de " << this->getNom() << " détruite." << endl;
}

void Lieu::addConnexion(connectionType_t mt, Lieu* l)
{
  if (mt==BATEAU)
    this->bateau[l->numero]=l;
  if (mt==TRAIN)
    this->train[l->numero]=l;
}

void Lieu::removeConnexion(connectionType_t mt, Lieu* l)
{
  if (mt==BATEAU)
    this->bateau[l->numero]=NULL;
  if (mt==TRAIN)
    this->train[l->numero]=NULL;
}
