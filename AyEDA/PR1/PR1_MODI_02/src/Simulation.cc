#include "simulation.h"
#include <iostream>
#include <thread> // Necesario para sleep_for
#include <chrono> // Necesario para las unidades de tiempo
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
  while(contador < 11000) {
    int coord_x{hormiga_.posicion_actual().first}, coord_y{hormiga_.posicion_actual().second};
    if(coord_x >= celdas_.size_Xaxis() && coord_y >= celdas_.size_Yaxis() && coord_x < 0 && coord_y < 0) {
      out << "La hormiga se ha caido!" << std::endl;
      break;
    }

    // Guardamos el color de la celda actual antes de colocar a la hormiga en esta
    color_celda_actual = celdas_.info_celda(coord_x, coord_y);

    // Situar a la hormiga en la cinta
    celdas_.modi_celda(coord_x, coord_y, hormiga_.orientacion());

    if(contador%500 == 0) {out << celdas_;}
    //std::this_thread::sleep_for(std::chrono::seconds(1));
    //out << celdas_;

    // Cambiamos el color de la celda actual
    celdas_.modi_celda(coord_x,coord_y,hormiga_.cambio_color_celda(color_celda_actual));

    // Calculamos la direccion del siguiente movimiento y la nueva orientacion de la hormiga
    int proxima_orientacion = hormiga_.reglas_movimiento(color_celda_actual, coord_x, coord_y);
    // Como resultado generamos una nueva direccion, y un cambio de coordenadas acorde a la nueva direccion

    // Guardamos la nueva orientacion y posicion
    hormiga_.set_pos_ori(Coordenada{coord_x, coord_y} ,proxima_orientacion);

    if(contador%500 == 0) {
      char decision{' '};
      out << "Desea proseguir?(yes, no) ";
      std::cin >> decision;
      if(decision == 'n') {
        break;
      }
    }
    ++contador;
  }
  out << celdas_;
  return;
}