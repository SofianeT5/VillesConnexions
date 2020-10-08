#ifndef _TEST_H
#define _TEST_H

#include <iostream>
#include <string>
#include "Carte.h"
#include "Policier.h"
#include "Gangster.h"
#include "Pigeon.h"
#include "Scenario.h"
#include "Personnage.h"

bool testGangster(Gangster& p);
bool testPersonnage(Personnage& p);
bool testCarte(Carte& c);
bool testPolicier(Policier& p);
bool testPigeon(Pigeon& p);
bool testLieu(Lieu& l);
bool testScenario(Scenario& s);
void error(std::string);

#endif
