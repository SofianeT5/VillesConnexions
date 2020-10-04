#include <stdlib.h>
#include "Scenario.h"
#include "Policier.h"
#include "Gangster.h"
#include "Pigeon.h"
using namespace std;

Scenario::Scenario()
{
    this->personnages = (Personnage**) malloc(NB_PERSOS*sizeof(Personnage*)); 
}

void Scenario::scene()
{
  for (int j=0; j<200; j++)
    for (int i=0; i<NB_PERSOS; i++)
      {
	this->personnages[i]->interagir(personnages, this->nbPers);
	if (this->personnages[i]->type == "GANGSTER")
	  (static_cast<Gangster*>(this->personnages[i]))->deplace();
	else if (this->personnages[i]->type == "POLICIER")
	  (static_cast<Policier*>(this->personnages[i]))->deplace();
	else if (this->personnages[i]->type == "PIGEON")
	  (static_cast<Pigeon*>(this->personnages[i]))->deplace();
	else
	  cout << "Erreur!" << endl;
      }
}

void Scenario::initScenario() {
  this->initCarte();
  this->initPersonnages();
}


void Scenario::initPersonnages() {
  string noms[NB_PERSOS] = {"Tobi","Madara","Shisui","Minato","Itachi","Kakashi","Hashirama", "Pain", "Hiruzen"};
  int i;
  for (i = 0; i<2 ; i++)
    this->personnages[i] = new Gangster(noms[i], this->carte.villes[0], "GANGSTER", this->carte, "Uchiha");
  for (i = 2; i<6 ; i++)
    this->personnages[i] = new Policier(noms[i], this->carte.villes[0], "POLICIER", this->carte);
  for (i = 6; i<NB_PERSOS ; i++)
    this->personnages[i] = new Pigeon(noms[i], this->carte.villes[0], "PIGEON", this->carte);
  this->nbPers=NB_PERSOS;
}

void Scenario::initCarte()
{

  string Villes[N] = {"Bordeaux", "Brest", "Calais", "Douvres", "Edimbourg", "LeHavre","Londres", "Paris", "Plymouth", "Portsmouth", "Quimper", "Rennes"};

  Carte* map = new Carte();
  this->carte=(*map);

  for (int i = 0 ; i < N ; i++) 
    this->carte.addLieu(Villes[i]);
    
  this->carte.villes[0]->addConnexion(BATEAU,this->carte.villes[1]);
  this->carte.villes[0]->addConnexion(TRAIN,this->carte.villes[7]);
  this->carte.villes[0]->addConnexion(TRAIN,this->carte.villes[10]);
  this->carte.villes[1]->addConnexion(BATEAU,this->carte.villes[8]);
  this->carte.villes[1]->addConnexion(TRAIN,this->carte.villes[11]);
  this->carte.villes[2]->addConnexion(BATEAU,this->carte.villes[3]);
  this->carte.villes[2]->addConnexion(TRAIN,this->carte.villes[7]);
  this->carte.villes[3]->addConnexion(TRAIN,this->carte.villes[6]);
  this->carte.villes[4]->addConnexion(TRAIN,this->carte.villes[6]);
  this->carte.villes[5]->addConnexion(BATEAU,this->carte.villes[7]);
  this->carte.villes[5]->addConnexion(BATEAU,this->carte.villes[9]);
  this->carte.villes[6]->addConnexion(TRAIN,this->carte.villes[8]);
  this->carte.villes[6]->addConnexion(TRAIN,this->carte.villes[9]);
  this->carte.villes[7]->addConnexion(TRAIN,this->carte.villes[11]);
  this->carte.villes[10]->addConnexion(TRAIN,this->carte.villes[11]);
}
