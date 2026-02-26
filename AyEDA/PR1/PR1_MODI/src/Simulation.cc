#include "simulation.h"
#include <iostream>
#include "tape.h"
#include "ant.h"

Simulation::Simulation(std::istream& input) : celdas_{input}, hormiga_{input} {
  while(!input.eof()) {
    int coord_x{0}, coord_y{0};
    input >> coord_x >> coord_y;
    celdas_.modi_celda(coord_x, coord_y, 1);
  }
}

void Simulation::hormiga_de_Lanton(std::ostream& out) {
  int color_celda_actual{0}, contador{1};
  while(true) {
    int coord_x{hormiga_.posicion_actual().first}, coord_y{hormiga_.posicion_actual().second};
    if(coord_x < 0 || coord_x >= celdas_.size_x() || coord_y < 0 || coord_y >= celdas_.size_y()) {
      out << "La hormiga se ha caido" << std::endl;
      break;
    }

    // Guardamos el color de la celda actual antes de colocar a la hormiga en esta
    color_celda_actual = celdas_.info_celda(coord_x, coord_y);

    // Situar a la hormiga en la cinta
    celdas_.modi_celda(coord_x, coord_y, hormiga_.orientacion());

    //if(contador%10 == 0) {out << celdas_;}
    out << celdas_;


    // Cambiamos el color de la celda actual
    celdas_.modi_celda(coord_x,coord_y,hormiga_.cambio_color_celda(color_celda_actual));

    // Calculamos la direccion del siguiente movimiento y la nueva orientacion de la hormiga
    int proxima_orientacion = hormiga_.reglas_movimiento(color_celda_actual, coord_x, coord_y);
    // Como resultado generamos una nueva direccion, y un cambio de coordenadas acorde a la nueva direccion

    // Guardamos la nueva orientacion y posicion
    hormiga_.set_pos_ori(Coordenada{coord_x, coord_y} ,proxima_orientacion);

    //if(contador%10 == 0) {
    //  int decision{0};
    //  out << "Desea proseguir?(yes=1, no=0) ";
    //  std::cin >> decision;
    //  if(decision == 0) {
    //    break;
    //  }
    //}

    int decision{0};
    out << "Desea proseguir?(yes=1, no=0) ";
    std::cin >> decision;
    if(decision == 0) {
      break;
    }

    ++contador;
  }
  return;
}