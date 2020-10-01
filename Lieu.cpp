#include <iomanip>
#include <iostream>
#include <string>
#include <queue>
#include <set>
#include "Lieu.h"

using namespace std;

long Lieu::compteur = 0;


Lieu::Lieu(string n="nulle part")
{
  this->name=n;
  this->numero=compteur;
  this->bateau = new Lieu*[N];
  this->train = new Lieu*[N];
  this->nbBateau=0;
  this->nbTrain=0;

  for (int i = 0 ; i < N ; i++ ) {
    this->bateau[i] = NULL;
    this->train[i] = NULL;
  }

  Lieu::compteur++;
}

string Lieu::getNom()
{
  return this->name;
}

void Lieu::setNom(string n){
    this->name = n;
}

Lieu::~Lieu()
{
  cout << "Ville n°" << this->numero << " de " << this->getNom() << " détruite." << endl;
}

void Lieu::addConnexion(connectionType_t mt, Lieu* l)
{
  if (mt==BATEAU)
    {
      this->bateau[l->numero]=l;
      l->bateau[this->numero]=this;
      this->nbBateau++;
      l->nbBateau++;
    }
  if (mt==TRAIN)
    {
      this->train[l->numero]=l;
      l->train[this->numero]=this;
      this->nbTrain++;
      l->nbTrain++;
    }
  /*Peut etre si on a mt == ALL, on devrait l'ajouter aux deux tableaux*/
}

void Lieu::removeConnexion(connectionType_t mt, Lieu* l)
{
  if (mt==BATEAU && (this->bateau[l->numero]==l || l->bateau[this->numero]==this))
    {
      this->bateau[l->numero]=NULL;
      l->bateau[this->numero]=NULL;
      this->nbBateau--;
      l->nbBateau--;
    }
  else if (mt==TRAIN && (this->train[l->numero]==l || l->train[this->numero]==this))
    {
      this->train[l->numero]=NULL;
      l->train[this->numero]=NULL;
      this->nbTrain--;
      l->nbTrain--;
    }
  else
    cout << "Connexion inexistante!" << endl;
}

bool Lieu::estAccessible(connectionType_t mt, const Lieu& l)
{
  if (mt==NONE)
    return false;
  if (mt==BATEAU)
    return (this->bateau[l.numero]==&l);
  else if (mt==TRAIN)
    return (this->train[l.numero]==&l);
  else if (mt==ALL)
    return ((this->bateau[l.numero]==&l) || (this->train[l.numero]==&l));
  else
    return false; 
}

long Lieu::distance(connectionType_t mt,const Lieu& l)
{
    if (this == &l)
      return 0;

    std::queue <std::pair<Lieu*,long> > file;
    std::set<Lieu*> visited;


    file.push(std::make_pair(this,0));
    visited.insert(this);

    while(!file.empty()) 
    {
        
      Lieu* current = file.front().first;
      long distance = file.front().second;
      file.pop();

      if (mt == TRAIN)
      {
        for(int i = 0 ; i < N ; i++)
        {
          if ( current->train[i] == NULL || visited.find(current->train[i]) != visited.end())
            continue;
          if (current->estAccessible(TRAIN,*(current->train[i]))) 
          {
              if ( current->train[i] == &l)
                  return distance+1;
              file.push(std::make_pair(current->train[i],distance+1));
              visited.insert(current->train[i]);
          }
        }
      }

      else
      {
        for(int i = 0 ; i < N ; i++)
        {
          if ( current->bateau[i] == NULL || visited.find(current->bateau[i]) != visited.end())
            continue;
          if (current->estAccessible(TRAIN,*(current->bateau[i]))) 
          {
              if ( current->bateau[i] == &l)
                  return distance+1;
              file.push(std::make_pair(current->bateau[i],distance+1));
              visited.insert(current->bateau[i]);
          }
        }

      }

    }
    return -1;
}
