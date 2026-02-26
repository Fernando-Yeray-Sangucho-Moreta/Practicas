#ifndef ANT_X
#define ANT_X

#include "ant.h"
#include <iostream>
#include <string>

class Ant_X : public Ant {
 public:
  Ant_X(std::istream&);
  Ant_X() : Ant{}, movimientos_dinamicos_{} {}
  ~Ant_X() {}

  void reglas_movimiento(const int&);
  std::string movimientos_dinamicos() const {return movimientos_dinamicos_;}
  void movimiento_D(char&, int&, int&);
  void movimiento_I(char& ,int&, int&);
  
 private:
  std::string movimientos_dinamicos_;
};

#endif