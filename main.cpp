#include <iomanip>
#include <iostream>
#include <string>
#include "Scenario.h"
#include <time.h>

using namespace std;

int main()
{
  srand(time(NULL));
  Scenario* s = new Scenario();
  s->initScenario();
  s->scene();
  return 0;
}
