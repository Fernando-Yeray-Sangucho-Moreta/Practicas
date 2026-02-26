#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include <utility>
#include "ant.h"
#include "colors.h"

typedef std::vector<std::vector<int>> Celdas;

class Tape {
 public:
  Tape(std::istream&);
  Tape() : cinta_bidimensional_{} {}
  
  int info_celda(const int&, const int&) const;
  void modi_celda(const int&, const int&, const int&);
  void write(std::ostream&) const;
 private:
  Celdas cinta_bidimensional_;
  void set_dimensiones_(std::istream&);
};

std::ostream& operator<<(std::ostream&, const Tape&);
#endif