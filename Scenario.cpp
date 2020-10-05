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

void Scenario::simulation(std::string* noms_gangster, long nb_gangster, std::string* noms_policier, long nb_policier, std::string* noms_pigeon, long nb_pigeon, long nb_scene)
{
  this->initScenario(noms_gangster, nb_gangster, noms_policier, nb_policier, noms_pigeon, nb_pigeon);
  for (long i=0; i<nb_scene; i++)
    this->scene();
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

void Scenario::initScenario(string* noms_gangster, long nb_gangster, string* noms_policier, long nb_policier, string* noms_pigeon, long nb_pigeon) {
  this->initCarte();
  this->initPersonnages(noms_gangster, nb_gangster, noms_policier, nb_policier, noms_pigeon, nb_pigeon);
}

void Scenario::initPersonnages(string* noms_gangster, long nb_gangster, string* noms_policier, long nb_policier, string* noms_pigeon, long nb_pigeon) 
{
  long i;
  for (i = 0; i<nb_gangster ; i++)
    this->personnages[i] = new Gangster(noms_gangster[i], this->carte.villes[rand()%this->carte.nbVilles], "GANGSTER", this->carte, "Uchiha");
  for (i = 0; i<nb_policier ; i++)
    this->personnages[i] = new Policier(noms_policier[i], this->carte.villes[rand()%this->carte.nbVilles], "POLICIER", this->carte);
  for (i = 0; i<nb_pigeon ; i++)
    this->personnages[i] = new Pigeon(noms_pigeon[i], this->carte.villes[rand()%this->carte.nbVilles], "PIGEON", this->carte);
  this->nbPers=nb_gangster + nb_policier + nb_pigeon;
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
