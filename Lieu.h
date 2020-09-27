#include <iomanip>
#include <iostream>
#include <string>

enum connectionType_t{NONE, TRAIN, BATEAU, ALL};

class Lieu{
 private:
  std::string name;
  long nbBateau;
  Lieu* bateau[];
  long nbTrain;
  Lieu* train[];

 public:
  long numero;
  static long compteur;
  Lieu();
  Lieu(std::string);
  std::string getNom();
  void addConnexion(connectionType_t, Lieu*);
  void removeConnexion(connectionType_t, Lieu*);
  bool estAccessible(connectionType_t, const Lieu&);
  long distance(connectionType_t, const Lieu&);
  ~Lieu();
};
