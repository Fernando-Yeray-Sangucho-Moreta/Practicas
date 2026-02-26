#include "tape.h"
#include <iostream>
#include <string>
#include <vector>

Tape::Tape(std::istream& input) : cinta_bidimensional_{} {
  set_dimensiones_(input);
}

void Tape::set_dimensiones_(std::istream& input) {
  int largo{0}, ancho{0};
  input >> largo >> ancho;
  cinta_bidimensional_.resize(largo);
  for(std::size_t i=0 ; i < cinta_bidimensional_.size() ; ++i) {
    cinta_bidimensional_[i].resize(ancho);
    std::fill(cinta_bidimensional_[i].begin(), cinta_bidimensional_[i].end(), 0);
  }
}

void Tape::write(std::ostream& out) const{
  const int kancho_cinta = cinta_bidimensional_[0].size(), klargo_cinta = cinta_bidimensional_.size();
  for(int j=0 ; j < kancho_cinta ; ++j) {
    for(int i=0 ; i < klargo_cinta ; ++i) {
      const int kvalor_en_cinta = cinta_bidimensional_[i][j];
      if(kvalor_en_cinta > 1) {
        char simbolo = kvalor_en_cinta;
        out << RED << BG_RED << simbolo << RESET;
      } else {
        if(kvalor_en_cinta == 0) {
          out << WHITE << BG_WHITE << kvalor_en_cinta << RESET;
        } else if(kvalor_en_cinta == 1) {
          out << BLACK << BG_BLACK << kvalor_en_cinta << RESET;
        }
      }
    }
    out << std::endl;
  }
}

int Tape::info_celda(const int& coord_x, const int& coord_y) const{
  return cinta_bidimensional_[coord_x][coord_y];
}

void Tape::modi_celda(const int& coord_x, const int& coord_y, const int& modificacion) {
  cinta_bidimensional_[coord_x][coord_y] = modificacion;
}

std::ostream& operator<<(std::ostream& out, const Tape& cinta_bi) {
  cinta_bi.write(out);
  return out;
}