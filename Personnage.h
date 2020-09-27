#include <iomanip>
#include <iostream>
#include <string>

class Personnage{
 private:
  std::string name;
  std::string text;

 public:
  Personnage(std::string);
  ~Personnage();
  void parle(const std::string);
};
