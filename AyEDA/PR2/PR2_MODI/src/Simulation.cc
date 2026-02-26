#include "simulation.h"
#include <iostream>
#include <string>
#include "tape.h"
#include "ant.h"
#include "Ant_X.h"

Simulation::Simulation(std::istream& input) : celdas_{input}, hormigas_{} {
  instanciar_hormigas(input);
  celdas_coloridas(input);
}

void Simulation::instanciar_hormigas(std::istream& input) {
  int siguiente_char{0};
  do {
    hormigas_.push_back(std::make_unique<Ant_X>(input));
    siguiente_char = input.peek();
  } while(siguiente_char != '\n');
}

void Simulation::celdas_coloridas(std::istream& input) {
  while(!input.eof()) {
    int coord_x{-1}, coord_y{-1}, color{0};
    input >> coord_x >> coord_y >> color;
    celdas_.modi_celda(coord_x, coord_y, color);
  }
}

void Simulation::hormiga_de_Lanton(std::ostream& out1, std::ostream& out2) {
  int color_celda_actual{0}, hormigas_caidas{0};
  while(true) {
    write(std::cout);
    int coord_x, coord_y;
    hormigas_caidas = 0;
    for(std::size_t i=0 ; i < hormigas_.size() ; ++i) {
      coord_x = (hormigas_[i]->posicion_actual().first);
      coord_y = (hormigas_[i]->posicion_actual().second);
      if(celdas_.out_range(coord_x, coord_y)) {
        std::cout << "La hormiga  " << i << " se ha caido." << std::endl;
        ++hormigas_caidas;
        continue;
      }
      color_celda_actual = celdas_.info_celda(coord_x, coord_y);
      celdas_.modi_celda(coord_x, coord_y, hormigas_[i]->cambio_color(color_celda_actual, celdas_.cantidad_colores()));
      hormigas_[i]->reglas_movimiento(color_celda_actual);
    }
    if(hormigas_caidas == hormigas_.size()) {
      break;
    }

    std::string decision;
    std::cout << "Desea proseguir?(yes, no=0, guardar=2) ";
    std::getline(std::cin, decision);
    if(decision == "0") {
      break;
    } else if(decision == "2") {
      formal_write(out1);
    }
  }
  formal_write(out2);
  return;
}

void Simulation::write(std::ostream& out) const {
  for(int j=0 ; j < celdas_.size_y() ; ++j) {
    for(int i=0 ; i < celdas_.size_x() ; ++i) {
      int color_celda = celdas_.info_celda(i,j), presencia_hormiga;
      if(hay_hormiga(i, j, presencia_hormiga)) {
        colocar_hormiga(out, presencia_hormiga, color_celda);
        continue;
      } else {
        celdas_.write_celda(out, color_celda);
      }
    }
    out << std::endl;
  }
}

void Simulation::colocar_hormiga(std::ostream& out, const int& pos, const int& color_celda) const {
  hormigas_[pos]->color_hormiga(out, color_celda);
}

bool Simulation::hay_hormiga(const int& coord_x, const int& coord_y, int& precensia) const {
  for(int i=0; i < hormigas_.size(); ++i) {
    if((hormigas_[i]->posicion_actual().first == coord_x) && (hormigas_[i]->posicion_actual().second == coord_y)) {
      precensia = i;
      return true;
    }
  }
  return false;
}

void Simulation::formal_write(std::ostream& out) const {
  bool separador{false};
  out << celdas_.size_x() << " " << celdas_.size_y() << " " << celdas_.cantidad_colores() << '\n'; 
  for(std::size_t i=0; i < hormigas_.size(); ++i) {
    if(separador) {
      out << " ; ";
    }
    out << hormigas_[i]->movimientos_dinamicos() << " " << hormigas_[i]->posicion_actual().first << " " << hormigas_[i]->posicion_actual().second << " " << hormigas_[i]->orientacion();
    separador = true;
  }
  out << '\n';

  for(std::size_t j=0 ; j < celdas_.size_y() ; ++j) {
    for(std::size_t i=0 ; i < celdas_.size_x() ; ++i) {
      int color_celda = celdas_.info_celda(i,j);
      if(color_celda > 0) {
        out << i << " " << j << " " << color_celda << '\n';
      }
    }
  }
}