#include <stdlib.h>
#include "Scenario.h"
#include "Policier.h"
#include "Gangster.h"
#include "Pigeon.h"

using namespace std;


Scenario::Scenario():nbPers(0)
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
    for (int i=0; i<this->nbPers; i++)
      {
        this->personnages[i]->interagir(this->personnages, this->nbPers);
        if (this->personnages[i]->getType() == GANGSTER)
          (static_cast<Gangster*>(this->personnages[i]))->deplace();
        else if (this->personnages[i]->getType() == POLICIER)
          (static_cast<Policier*>(this->personnages[i]))->deplace();
        else if (this->personnages[i]->getType() == PIGEON)
          (static_cast<Pigeon*>(this->personnages[i]))->deplace();
        else
          cout << "Erreur!" << endl;
      }
}


void Scenario::initScenario(string* noms_gangster, long nb_gangster, string* noms_policier, long nb_policier, string* noms_pigeon, long nb_pigeon) {
  this->initCarte();
  this->initItineraires();
  this->initPersonnages(noms_gangster, nb_gangster, noms_policier, nb_policier, noms_pigeon, nb_pigeon);
}


void Scenario::initPersonnages(string* noms_gangster, long nb_gangster, string* noms_policier, long nb_policier, string* noms_pigeon, long nb_pigeon) 
{
  long i;
  for (i = 0; i<nb_gangster ; i++)
  {
    int j = rand()%NB_ITINERAIRE;
    this->personnages[i] = new Gangster(noms_gangster[i], this->itineraires[j][0], this->itineraires[j], taille[j],GANGSTER,"Uchiha");
  }
  for (i = nb_gangster; i<nb_policier+nb_gangster; i++)
  {
    int j = rand()%NB_ITINERAIRE;
    this->personnages[i] = new Policier(noms_policier[i-nb_gangster], this->itineraires[j][0], this->itineraires[j], taille[j],POLICIER);
  }
  for (i = nb_gangster+nb_policier; i<nb_pigeon+nb_policier+nb_gangster ; i++)
  {
    int j = rand()%NB_ITINERAIRE;
    this->personnages[i] = new Pigeon(noms_pigeon[i-(nb_gangster+nb_policier)], this->itineraires[j][0], this->itineraires[j], taille[j],PIGEON);
  }
  this->nbPers=nb_gangster + nb_policier + nb_pigeon;

  //Free
  for(int k = 0; k < NB_ITINERAIRE ; k++)
  {
    free(this->itineraires[k]);
  }
  free(this->itineraires);
  free(this->taille);
}

void Scenario::initItineraires()
{
    //itineraire 3
    //Londres - Douvres - Calais - Paris - Le Havre - Portsmouth
    //

    const int  nombre = NB_ITINERAIRE;
    Lieu*** itineraires = (Lieu***)malloc(nombre * sizeof(Lieu**));
    int* taille = (int*)malloc(nombre * sizeof(int));
    
    taille[0] = 4;
    taille[1] = 4;
    taille[2] = 6;

    for (int i = 0 ; i < nombre ; i++)
    {
      itineraires[i] = (Lieu**)malloc(taille[i] * sizeof(Lieu*)); // itineraires 1
    }
    
    itineraires[0][0] = this->carte.getLieu("Brest");
    itineraires[0][1] = this->carte.getLieu("Bordeaux");
    itineraires[0][2] = this->carte.getLieu("Quimper");
    itineraires[0][3] = this->carte.getLieu("Rennes");

    itineraires[1][0] = this->carte.getLieu("Paris");
    itineraires[1][1] = this->carte.getLieu("Rennes");
    itineraires[1][2] = this->carte.getLieu("Quimper");
    itineraires[1][3] = this->carte.getLieu("Bordeaux");

    itineraires[2][0] = this->carte.getLieu("Londres");
    itineraires[2][1] = this->carte.getLieu("Douvres");
    itineraires[2][2] = this->carte.getLieu("Calais");
    itineraires[2][3] = this->carte.getLieu("Paris");
    itineraires[2][4] = this->carte.getLieu("LeHavre");
    itineraires[2][5] = this->carte.getLieu("Portsmouth");

    this->itineraires = itineraires;
    this->taille = taille;

}

void Scenario::initCarte()
{

  string Villes[N] = {"Bordeaux", "Brest", "Calais", "Douvres", "Edimbourg", "LeHavre","Londres", "Paris", "Plymouth", "Portsmouth", "Quimper", "Rennes"};

  Carte* c = new Carte();
  this->carte = *c;

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
