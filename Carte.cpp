#include <iomanip>
#include <iostream>
#include <string>
#include <stdlib.h>
#include "Carte.h"
using namespace std;

Carte::Carte()
{
    this->villes =(Lieu**) malloc(N*sizeof(Lieu*));
}

Carte::~Carte()
{
  cout << "Carte détruite." << endl;
}

Lieu* Carte::addLieu(string name)
{
  Lieu* l = new Lieu(name);
  this->villes[l->numero]=l;
  return l;
}

Lieu* Carte::getLieu(string name)
{
  for (int i=0; i<N; i++)
    if(this->villes[i]->getNom()==name)
      return this->villes[i];
  return NULL;
}

void Carte::addConnexion(connectionType_t mt, Lieu* l1, Lieu* l2)
{
  l1->Lieu::addConnexion(mt, l2);
}

void Carte::removeConnexion(connectionType_t mt, Lieu* l1, Lieu* l2)
{
  l1->Lieu::removeConnexion(mt, l2);
}

