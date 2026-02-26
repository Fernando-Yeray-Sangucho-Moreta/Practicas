#ifndef ANT_H
#define ANT_H

#include <utility>
#include <iostream>
#include <vector>
#include <string>

typedef std::pair<int,int> Coordenada;

class Ant {
 public:
  Ant(std::istream&);
  Ant() : posicion_actual_{} , orientacion_{} {}
  virtual ~Ant() {}

  virtual void reglas_movimiento(const int&) = 0;
  virtual std::string movimientos_dinamicos() const = 0;
  
  Coordenada posicion_actual() const {return posicion_actual_;}
  char orientacion() const {return orientacion_;}

  void write(std::ostream&) const;
  int cambio_color(const int&, const int&) const;
  void color_hormiga(std::ostream&, const int&) const;

 protected:
  void set_pos_ori(std::istream&);
  void set_pos_ori(const Coordenada& new_pos, const char& new_ori) {posicion_actual_ = new_pos; orientacion_ = new_ori;}

 private:
  Coordenada posicion_actual_;
  char orientacion_;
};

std::ostream& operator<<(std::ostream&, const Ant&);

#endif