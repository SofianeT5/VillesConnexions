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
  this->bateau = new Lieu*[0];
  this->train = new Lieu*[0];
  this->nbBateau=0;
  this->nbTrain=0;

  Lieu::compteur++;
}

Lieu::~Lieu()
{
  cout << "Ville n°" << this->numero << " de " << this->getNom() << " détruite." << endl;
}

void Lieu::addConnexion(connectionType_t mt, Lieu* l)
{
  if (mt==BATEAU)
    {
      int i = 0;
      Lieu** tmp = new Lieu*[this->nbBateau+1];
      for (i = 0; i < this->nbBateau ; i++)
      {
        tmp[i] = this->bateau[i];
      }
      tmp[i]=l;
      delete[] this->bateau;
      this->bateau = tmp;
      this->nbBateau++;
    }
  if (mt==TRAIN)
    {
      int i = 0;
      Lieu** tmp = new Lieu*[this->nbTrain+1];
      for (i = 0; i < this->nbTrain ; i++)
      {
        tmp[i] = this->train[i];
      }
      tmp[i]=l;
      delete[] this->train;
      this->train = tmp;
      this->nbTrain++;

    }
}

void Lieu::removeConnexion(connectionType_t mt, Lieu* l)
{

  int j;
  if (mt==BATEAU || mt == ALL)
    {
      j = 0;
      if (this->estAccessible(mt,*l))
      {
        Lieu** tmp = new Lieu*[this->nbBateau - 1];
        for (int i=0;i < nbBateau ; i++)
        {
            if(this->bateau[i] != l)
            {
                tmp[i-j] = this->bateau[i];
            }
            else
            {
              j++;
            }
        }
        delete[] this->bateau;
        this->nbBateau--;
        this->bateau = tmp;
      }
      
    }
  if (mt==TRAIN || mt == ALL)
    {
      j = 0 ;

      if (this->estAccessible(mt,*l))
      {
        Lieu** tmp = new Lieu*[this->nbTrain- 1];
        for (int i=0;i < nbTrain ; i++)
        {
            if(this->train[i] != l)
            {
                tmp[i-j] = this->train[i];
            }
            else
            {
              j++;
            }
        }
        delete[] this->train;
        this->nbTrain--;
        this->train = tmp;
      }
    }
   if (mt == NONE)
   {
        cout << "Connexion in�xistante" << endl;

   }
}

bool Lieu::estAccessible(connectionType_t mt, const Lieu& l)
{
  if (mt==NONE)
    return false;
  if (mt == TRAIN || mt == ALL)
  {
    for (int i = 0; i < nbTrain ; i++)
    {
      if (this->train[i] == &l) 
        return true;
    }
  }
  if (mt == BATEAU || mt == ALL)
  {
    for (int i = 0; i < nbBateau; i++)
    {
      if (this->bateau[i] == &l) 
        return true;
    }
  }
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
        for(int i = 0 ; i < current->nbTrain ; i++)
        {
          if (visited.find(current->train[i]) != visited.end())
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

      else if ( mt == BATEAU)
      {
        for(int i = 0 ; i < current->nbBateau ; i++)
        {
          if (visited.find(current->bateau[i]) != visited.end())
            continue;
          if (current->estAccessible(BATEAU,*(current->bateau[i]))) 
          {
              if ( current->bateau[i] == &l)
                return distance+1;
              file.push(std::make_pair(current->bateau[i],distance+1));
              visited.insert(current->bateau[i]);
          }
        }

      }
    else
    {
        return -1;
    }
  }
    return -1;
}
