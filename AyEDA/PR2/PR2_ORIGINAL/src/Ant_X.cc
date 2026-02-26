#include "Ant_X.h"

Ant_X::Ant_X(std::istream& input) : Ant{} , movimientos_dinamicos_{} {
  std::string movimientos_dinamicos;
  do {
    movimientos_dinamicos = "";
    input >> movimientos_dinamicos;
  } while(movimientos_dinamicos == ";");
  movimientos_dinamicos_ = movimientos_dinamicos;
  set_pos_ori(input);
}

void Ant_X::reglas_movimiento(const int& color_celda) {
  int curr_coord_x{posicion_actual().first}, curr_coord_y{posicion_actual().second};
  char orientacion_actual{orientacion()};
  char opcion_movimento = (movimientos_dinamicos_[color_celda]);

  if(opcion_movimento == 'D') {
    movimiento_D(orientacion_actual, curr_coord_x, curr_coord_y);
  } else if(opcion_movimento == 'I') {
    movimiento_I(orientacion_actual, curr_coord_x, curr_coord_y);
  }

  set_pos_ori(Coordenada{curr_coord_x,curr_coord_y}, orientacion_actual);
}

void Ant_X::movimiento_D(char& orientacion_actual, int& coord_x, int& coord_y) {
  switch (orientacion_actual) {
   case '<':
    orientacion_actual = '^';
    --coord_y;
    break;
   case '>':
    orientacion_actual = 'v';
    ++coord_y;
    break;
   case 'v':
    orientacion_actual = '<';
    --coord_x;
    break;
   case '^':
    orientacion_actual = '>';
    ++coord_x;
    break;
   default:
    orientacion_actual = 'X';
    break;
  }
}

void Ant_X::movimiento_I(char& orientacion_actual, int& coord_x, int& coord_y) {
  switch (orientacion_actual) {
   case '<':
    orientacion_actual = 'v';
    ++coord_y;
    break;
   case '>':
    orientacion_actual = '^';
    --coord_y;
    break;
   case 'v':
    orientacion_actual = '>';
    ++coord_x;
    break;
   case '^':
    orientacion_actual = '<';
    --coord_x;
    break;
   default:
    orientacion_actual = 'X';
    break;
  }
}
