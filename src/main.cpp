#include <iostream>

#include "DataFrame.h"


int main(int argc, char** argv){

  std::cout << "Hello" << std::endl;
  LeaRN::DataFrame df;
  df.load_csv("../data/housing.csv");
  return 0;
}
