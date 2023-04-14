#include "CSV.h"

using namespace LeaRN;

CSV::CSV(){
  
}

CSV::~CSV() {
  // supprimer les éléments de la liste
}

std::vector<std::string>* CSV::csv_read_row(std::istream &in, char delimiter){
    std::stringstream ss;
    bool inquotes = false;
    std::vector<std::string>* row = new std::vector<std::string>();

    while(in.good()){
      char c = in.get();
      if (!inquotes && c=='"'){
        inquotes=true;
      }

      else if (inquotes && c=='"'){
        if ( in.peek() == '"'){
          ss << (char)in.get();
        }
        else{
          inquotes=false;
        }
      }
      else if (!inquotes && c==delimiter){
        row->push_back( ss.str() );
        ss.str("");
      }
      else if (!inquotes && (c=='\r' || c=='\n') ){
        if(in.peek()=='\n') { in.get(); }
        row->push_back( ss.str() );
        return row;
      }
      else{
        ss << c;
      }
    }
}


std::vector<std::string>* CSV::csv_read_row(std::string &line, char delimiter){
  std::stringstream ss(line);
  return csv_read_row(ss, delimiter);
}


void CSV::load_file(const std::string& filename, char col_delimiter){
  std::ifstream in(filename);
  if (in.fail()) {
    std::cerr << "File not found" << std::endl;
    return;
  }
  while(in.good()){
    this->lst_lines.push_back(this->csv_read_row(in, col_delimiter));
  }
  in.close();
  
}

void CSV::print_header(){
  for (std::string &str : *(this->header_row)) {
    std::cout << "|" << std::setw(12) << str.substr(0, 12);
  }
  std::cout << std::endl;
}

void CSV::print_data(){
  for(std::vector<std::string>* &row : this->lst_lines){
    for(int i=0, leng=row->size(); i<leng; i++){
      std::cout << "|" << std::setw(12) << row->at(i).substr(0,12)    ;
    }
    std::cout << std::endl;
  }
}

std::vector<std::string> CSV::get_colmuns (){
  //on suppose que la première ligne contient le titre des colonnes 
  std::vector<std::string>* &row = this->lst_lines.front();
}

std::vector <std::string> * CSV::get_header(){
  return this->header_row;
}

int CSV::get_colmuns_number (){
  return this->header_row->size();
}


std::vector<std::string>* CSV::get_next_row(){
  return nullptr;
}

