#include "tape.h"
#include <iostream>
#include <string>
#include <vector>
#include "colors.h"

Tape::Tape(std::istream& input) : cinta_bidimensional_{} , colores_{} {
  set_dimensiones_(input);
}

void Tape::set_dimensiones_(std::istream& input) {
  int largo{0}, ancho{0}, colores{0};
  input >> largo >> ancho >> colores;
  cinta_bidimensional_.resize(largo);
  for(std::size_t i=0 ; i < cinta_bidimensional_.size() ; ++i) {
    cinta_bidimensional_[i].resize(ancho);
    std::fill(cinta_bidimensional_[i].begin(), cinta_bidimensional_[i].end(), paint::BLANCO);
  }
  colores_ = colores;
}

int Tape::info_celda(const int& coord_x, const int& coord_y) const{
  return cinta_bidimensional_[coord_x][coord_y];
}

void Tape::modi_celda(const int& coord_x, const int& coord_y, const int& modificacion) {
  if(!out_range(coord_x, coord_y)) {
    cinta_bidimensional_[coord_x][coord_y] = modificacion;
  }
}

void Tape::write(std::ostream& out) const {
  for(int j=0 ; j < size_y() ; ++j) {
    for(int i=0 ; i < size_x() ; ++i) {
      out << info_celda(i,j);
    }
    out << std::endl;
  }
}

void Tape::write_celda(std::ostream& out, const int& color_celda) const {
  switch (color_celda) {
   case paint::BLANCO :
    out << WHITE << BG_WHITE << color_celda << RESET;
    break;
   case paint::NEGRO :
    out << GRAY << BG_BLACK << color_celda << RESET;
    break;
   case paint::ROJO :
    out << BLACK << BG_RED << color_celda << RESET;
    break;
   case paint::VERDE :
    out << RED << BG_GREEN << color_celda << RESET;
    break;
   case paint::AMARILLO :
    out << GREEN << BG_YELLOW << color_celda << RESET;
    break;
   case paint::AZUL :
    out << YELLOW << BG_BLUE << color_celda << RESET;
    break;
   case paint::MAJENTA :
    out << BLUE << BG_MAGENTA << color_celda << RESET;
    break;
   case paint::CIAN :
    out << MAGENTA << BG_CYAN << color_celda << RESET;
    break;
   case paint::NARANJA :
    out << CYAN << BG_ORANGE << color_celda << RESET;
    break;
   case paint::ROSA :
    out << ORANGE << BG_ROSE << color_celda << RESET;
    break;
   case paint::AZULCL :
    out << ROSE << BG_LBLUE << color_celda << RESET;
    break;
   case paint::VERDECL :
    out << LBLUE << BG_LGREEN << color_celda << RESET;
    break;
   case paint::GRIS :
    out << LGREEN << BG_GRAY << color_celda << RESET;
    break;
   default :
    out << "?";
    break;
  }
}

std::ostream& operator<<(std::ostream& out, const Tape& cinta) {
  cinta.write(out);
  return out;
}
