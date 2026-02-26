#ifndef TAPE_H
#define TAPE_H

#include <iostream>
#include <vector>
#include <utility>
#include "colors.h"

typedef std::vector<std::vector<int>> Celdas;
enum paint {BLANCO, NEGRO, ROJO, VERDE, AMARILLO, AZUL, MAJENTA, CIAN, NARANJA, ROSA, AZULCL, VERDECL, GRIS};

class Tape {
 public:
  Tape(std::istream&);
  Tape() : cinta_bidimensional_{} , colores_{} {}
  
  int info_celda(const int&, const int&) const;
  void modi_celda(const int&, const int&, const int&);
  void write(std::ostream&) const;
  void write_celda(std::ostream&, const int&) const;
  
  bool out_range(const int& coord_x, const int& coord_y) const {return (coord_x < 0 || coord_y < 0 || coord_x >= size_x() || coord_y >= size_y());}
  
  std::size_t size_x() const {return cinta_bidimensional_.size();}
  std::size_t size_y() const {return cinta_bidimensional_[0].size();}
  int cantidad_colores() const {return colores_;}

 private:
  Celdas cinta_bidimensional_;
  int colores_;
  void set_dimensiones_(std::istream&);
};

std::ostream& operator<<(std::ostream&, const Tape&);

#endif