#include "ant.h"

Ant::Ant(std::istream& input) : posicion_actual_{}, orientacion_{} {
  set_ant_ori_pos_ini_(input);
}

void Ant::set_ant_ori_pos_ini_(std::istream& input) {
  int coord_x{0}, coord_y{0}, sentido{0};
  input >> coord_x >> coord_y >> sentido;
  posicion_actual_ = Coordenada{coord_x, coord_y};
  orientacion_ = Orientaciones[sentido];
}



int Ant::reglas_movimiento(const int& color_celda, int& curr_coord_x, int& curr_coord_y) {
  int proximo_sentido_hormiga{0};
  // Blanca : Negra, 90 I, +1
  // Negra : Blanca, 90 D, +1
  if(color_celda == 0) {
    switch (orientacion_) {
     case '<'://NO
      proximo_sentido_hormiga = 'v'; // SO
      curr_coord_x = posicion_actual_.first-1;
      curr_coord_y = posicion_actual_.second+1;
      break;
     case '>'://SE
      proximo_sentido_hormiga = '^'; //NE
      curr_coord_x = posicion_actual_.first+1;
      curr_coord_y = posicion_actual_.second-1;
      break;
     case 'v'://SO
      proximo_sentido_hormiga = '>'; // SE
      curr_coord_x = posicion_actual_.first+1;
      curr_coord_y = posicion_actual_.second+1;
      break;
     case '^'://NE
      proximo_sentido_hormiga = '<'; //NO
      curr_coord_x = posicion_actual_.first-1;
      curr_coord_y = posicion_actual_.second-1;
      break;
     default:
      proximo_sentido_hormiga = 'X';
      curr_coord_x = posicion_actual_.first;
      curr_coord_y = posicion_actual_.second;
      break;
    }
  } else {
    switch (orientacion_) {
     case '<':
      proximo_sentido_hormiga = '^';
      curr_coord_x = posicion_actual_.first+1;
      curr_coord_y = posicion_actual_.second-1;
      break;
     case '>':
      proximo_sentido_hormiga = 'v';
      curr_coord_x = posicion_actual_.first-1;
      curr_coord_y = posicion_actual_.second+1;
      break;
     case 'v':
      proximo_sentido_hormiga = '<';
      curr_coord_x = posicion_actual_.first-1;
      curr_coord_y = posicion_actual_.second-1;
      break;
     case '^':
      proximo_sentido_hormiga = '>';
      curr_coord_x = posicion_actual_.first+1;
      curr_coord_y = posicion_actual_.second+1;
      break;
     default:
      proximo_sentido_hormiga = 'X';
      curr_coord_x = posicion_actual_.first;
      curr_coord_y = posicion_actual_.second;
      break;
    }
  }
  return proximo_sentido_hormiga;
}