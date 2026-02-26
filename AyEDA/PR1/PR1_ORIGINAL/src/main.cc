#include "simulation.h"
#include <iostream>
#include <fstream>

int main(int argc, char* argv[]) {
  std::ifstream input_file;
  input_file.open(argv[1]);
  std::ofstream output_file_1;
  output_file_1.open(argv[2]);
  std::ofstream output_file_2;
  output_file_2.open(argv[3]);

  Simulation hormiga_de_Langton{input_file};
  hormiga_de_Langton.hormiga_de_Lanton(output_file_1, output_file_2);

  input_file.close();
  output_file_1.close();
  output_file_2.close();

  return 0;
}