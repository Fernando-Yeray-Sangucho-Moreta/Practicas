#include "ant.h"
#include "colors.h"
#include "tape.h"

Ant::Ant(std::istream& input) : posicion_actual_{}, orientacion_{} {
  set_pos_ori(input);
}

int Ant::cambio_color(const int& color_celda, const int& max_colores) const {
  if(color_celda == (max_colores-1)) {return 0;}
  return (color_celda+1);
}

void Ant::set_pos_ori(std::istream& input) {
  int coord_x{0}, coord_y{0};
  char sentido;
  input >> coord_x >> coord_y >> sentido;
  posicion_actual_ = Coordenada{coord_x, coord_y};
  orientacion_ = sentido;
}

void Ant::write(std::ostream& out) const {
  out << orientacion_;
}

void Ant::color_hormiga(std::ostream& out, const int& color_celda) const {
  switch (color_celda) {
   case paint::BLANCO :
    out << LGREEN << BG_WHITE << orientacion_ << RESET;
    break;
   case paint::NEGRO :
    out << GRAY << BG_BLACK << orientacion_ << RESET;
    break;
   case paint::ROJO :
    out << WHITE << BG_RED << orientacion_ << RESET;
    break;
   case paint::VERDE :
    out << BLACK << BG_GREEN << orientacion_ << RESET;
    break;
   case paint::AMARILLO :
    out << RED << BG_YELLOW << orientacion_ << RESET;
    break;
   case paint::AZUL :
    out << GREEN << BG_BLUE << orientacion_ << RESET;
    break;
   case paint::MAJENTA :
    out << YELLOW << BG_MAGENTA << orientacion_ << RESET;
    break;
   case paint::CIAN :
    out << BLUE << BG_CYAN << orientacion_ << RESET;
    break;
   case paint::NARANJA :
    out << MAGENTA << BG_ORANGE << orientacion_ << RESET;
    break;
   case paint::ROSA :
    out << CYAN << BG_ROSE << orientacion_ << RESET;
    break;
   case paint::AZULCL :
    out << ORANGE << BG_LBLUE << orientacion_ << RESET;
    break;
   case paint::VERDECL :
    out << ROSE << BG_LGREEN << orientacion_ << RESET;
    break;
   case paint::GRIS :
    out << LBLUE << BG_GRAY << orientacion_ << RESET;
    break;
   default :
    out << "?";
    break;
  }
}

std::ostream& operator<<(std::ostream& out, const Ant& hormiga) {
  hormiga.write(out);
  return out;
}