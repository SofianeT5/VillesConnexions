#ifndef _GANGSTER_H
#define _GANGSTER_H

#include <iostream>
#include <iomanip>
#include <string>
#include "Personnage.h"

class Gangster : public Personnage{
 private:
  long recompense;

 public:
  Gangster();
};

#endif
