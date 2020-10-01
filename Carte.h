#include <iomanip>
#include <iostream>
#include <string>
#include "Personnage.h"

class Carte{
 private:
  Lieu** villes;

 public:
  long nbVilles;
  Carte();
  Lieu* addLieu(std::string);
  Lieu* getLieu(std::string);
  void addConnexion(connectionType_t, Lieu*, Lieu*);
  void removeConnexion(connectionType_t, Lieu*, Lieu*);
  void initCarte();
  ~Carte();
};
