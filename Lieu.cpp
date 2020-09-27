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

bool Lieu::estAccessible(connectionType_t mt, const Lieu& l)
{
  if (mt==NONE)
    return false;
  if (mt==BATEAU)
    return (this->bateau[l.numero]==&l);
  if (mt==TRAIN)
    return (this->train[l.numero]==&l);
  if (mt==ALL)
    return ((this->bateau[l.numero]==&l) || (this->train[l.numero]==&l));
}
/*
long distance(connectionType_t mt, const Lieu& l)
{
  if (this->numero==l.numero)
    return 0;
  else if (this.estAccessible (mt, l))
    return 1;
  else
    {
      long dist[N]={ 0 };
      int visited[N]={ 0 };
      queue <string> file;
      file.push(l1);
      dist[index(l1)]=0;
      visited[index(l1)]=1;
      while (!file.empty())
	{
	  l1=file.front();
	  file.pop();
	  for (int i=0; i<N; i++)
	    if(estAccessible(mt, l1, Villes[i]) && visited[i]==0)
	      {
		  file.push(Villes[i]);
		  dist[i] = dist[index(l1)] + 1;
		  visited[i]=1;
	      }
	}
      if (dist[index(l2)]==0)
	return -1;
      else
	return dist[index(l2)];
    }
}
*/
