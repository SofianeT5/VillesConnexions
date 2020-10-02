#ifndef _POLICIER_H
#define _POLICIER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"

class Policier : public Personnage{
 private:
  long reputation;

 public:
  typedef Personnage super;
  Policier();
  
};

#endif
