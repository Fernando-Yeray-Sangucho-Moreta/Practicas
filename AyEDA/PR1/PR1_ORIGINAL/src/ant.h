#ifndef ANT_H
#define ANT_H

#include <utility>
#include <iostream>
#include <vector>

typedef std::pair<int,int> Coordenada;
const std::vector<char> Orientaciones {'<', '>', '^', 'v'};

class Ant {
 public:
  Ant(std::istream&);
  Ant() : posicion_actual_{} , orientacion_{} {}

  int reglas_movimiento(const int&, int&, int&);
  Coordenada posicion_actual() {return posicion_actual_;}
  int orientacion() {return orientacion_;}
  void set_pos_ori(const Coordenada& new_pos, const int& new_ori) {posicion_actual_ = new_pos; orientacion_ = new_ori;}
  int cambio_color_celda(const int& celda) {return (celda==0?1:0);}
 private:
  Coordenada posicion_actual_;
  int orientacion_;
  void set_ant_ori_pos_ini_(std::istream&);
};

#endif