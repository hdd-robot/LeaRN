#include <iostream>

#include "DataFrame.h"

#include "Parser.h"

int main(int argc, char** argv){

  std::cout << "Hello" << std::endl;
  LeaRN::DataFrame df;
  df.load_csv("../data/housing.csv");
  //df.describe();
  int val;
  

  val = LeaRN::Parser::get_type("Null");
  std::cout << val << std::endl;


  return 0;
}
