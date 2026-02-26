#ifndef SIMULATION_H
#define SIMULATION_H

#include "tape.h"
#include "Ant_X.h"
#include <iostream>
#include <vector>
#include <memory>

//Solo para ubuntu, una forma de borrar la pantalla
//#define gotoxy(x,y)  printf("\33[%d;%dH",y,x)
//#define clrscr()     gotoxy(1,1); printf("\33[2J")

class Simulation {
 public:
  Simulation(std::istream&);

  void hormiga_de_Lanton(std::ostream&, std::ostream&);
  void write(std::ostream&) const;
  void formal_write(std::ostream&) const;
  void celdas_coloridas(std::istream&);
  void instanciar_hormigas(std::istream&);
  bool hay_hormiga(const int&, const int&, int&) const;
  void colocar_hormiga(std::ostream&, const int&, const int&) const;

 private:
  Tape celdas_;
  std::vector<std::unique_ptr<Ant>> hormigas_;
};

#endif