#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Carte.h"
using namespace std;

Carte::Carte()
{
    this->villes = new Lieu*[0];
    this->nbVilles = 0 ;
}

Carte::~Carte()
{
  for (int i = 0 ; i < this->nbVilles ; i++)
    delete this->villes[i];
  delete [] this->villes;
}

Lieu* Carte::addLieu(string name)
{
  Lieu* l = new Lieu(name);
  Lieu** tmp = new Lieu*[this->nbVilles+1];

  // copy
  int i;

  for (i = 0 ; i < this->nbVilles ; i++)
  {
    tmp[i] = this->villes[i];
  }

  tmp[i] = l;

  delete[] this->villes;
  this->villes = tmp;

  this->nbVilles++;
  return l;
}

Lieu* Carte::getLieu(string name)
{
  for (int i=0; i< this->nbVilles; i++)
    if(this->villes[i]->getNom()==name)
      return this->villes[i];
  return NULL;
}

void Carte::addConnexion(connectionType_t mt, Lieu* l1, Lieu* l2)
{
  l1->Lieu::addConnexion(mt, l2);
  l2->Lieu::addConnexion(mt, l1);
}

void Carte::removeConnexion(connectionType_t mt, Lieu* l1, Lieu* l2)
{
  l1->Lieu::removeConnexion(mt, l2);
  l2->Lieu::removeConnexion(mt, l1);
}

