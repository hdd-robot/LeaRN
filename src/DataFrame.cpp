#include "DataFrame.h"


using namespace LeaRN;


int DataFrame::load_csv(const  std::string &file_name, const char col_delimiter){
  CSV csv;
  csv.load_file(file_name, col_delimiter);
  
  return 0;
}



void DataFrame::head(){
  
}

void DataFrame::tail(){

}

void DataFrame::add_column(){
  Column col;

}

void DataFrame::addline(){

}

