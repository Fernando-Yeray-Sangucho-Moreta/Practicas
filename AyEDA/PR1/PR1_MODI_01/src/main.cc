#include "simulation.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  std::ifstream input_file;
  input_file.open(argv[1]);

  Simulation hormiga_de_Langton{input_file};
  hormiga_de_Langton.hormiga_de_Lanton(std::cout);

  return 0;
}