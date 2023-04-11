#include "DataFrame.h"


using namespace LeaRN;

int DataFrame::load_csv(const std::string &file_name, const char col_delimiter){
  std::fstream fin;
  fin.open(file_name, std::ios::in);
  std::vector<std::string> row;
  std::string line, word, temp;
  while (fin >> temp) {
    row.clear();
    std::getline(fin, line);
    std::cout << "|" << line << "|" << " - " ;
    std::stringstream s(line);
    
    while (getline(s, word, col_delimiter)) {
      row.push_back(word);
    }

    for(std::string str : row){
      std::cout << "|" << str << "|" << " - " ;
    }
    std::cout << std::endl ;
    return 0;
  }


  return 1;
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

