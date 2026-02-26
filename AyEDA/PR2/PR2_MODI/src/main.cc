#include "simulation.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  std::ifstream input_file;
  std::ofstream output_file_1, output_file_2;

  input_file.open(argv[1]);
  output_file_1.open(argv[2]);
  output_file_2.open(argv[3]);

  Simulation hormiga_de_Langton_generalizada{input_file};
  hormiga_de_Langton_generalizada.hormiga_de_Lanton(output_file_1, output_file_2);

  input_file.close();
  output_file_1.close();
  output_file_2.close();

  return 0;
}