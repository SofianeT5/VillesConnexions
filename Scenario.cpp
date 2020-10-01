#include "Scenario.h"

using namespace std;


Scenario::Scenario()
{
    
    this->personnages = (Personnage*) malloc(9*sizeof(Personnage)); 
}

void Scenario::initScenario() {
  this->initCarte();
  this->initPersonnages();
}


void Scenario::initPersonnages() {
  string noms[9] = {"Tobi","Deidara","Pain","Minato","Itachi","Kakashi","Hashirama","Madara","Shisui"};

  for (int i = 0; i < 9 ; i++){
    this->personnages[i].setNom(noms[i]);
    this->personnages[i].lieu = this->carte.villes[i];
  }

}

void Scenario::initCarte()
{

  string Villes[N] = {"bordeaux", "brest", "calais", "douvres", "edimbourg", "lehavre","londres", "paris", "plymouth", "portsmouth", "quimper", "rennes"};

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
