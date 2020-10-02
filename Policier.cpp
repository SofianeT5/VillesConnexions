#include <iostream>
#include <string>
#include <stdlib.h>
#include "Policier.h"
using namespace std;

Policier::Policier(string name="personne")
{
  super(name);
  this->reputation=rand() % 11;
  this->parle("");
}
