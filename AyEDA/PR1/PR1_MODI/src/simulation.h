#ifndef SIMULATION_H
#define SIMULATION_H

#include "tape.h"
#include "ant.h"
#include <iostream>

//Solo para ubuntu, una forma de borrar la pantalla
//#define gotoxy(x,y)  printf("\33[%d;%dH",y,x)
//#define clrscr()     gotoxy(1,1); printf("\33[2J")

class Simulation {
 public:
  Simulation(std::istream&);
  void hormiga_de_Lanton(std::ostream&);
 private:
  Tape celdas_;
  Ant hormiga_;
};

#endif