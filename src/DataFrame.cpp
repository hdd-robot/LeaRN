#include "DataFrame.h"
#include <string>
#include <vector>


using namespace LeaRN;


int DataFrame::load_csv(const  std::string &file_name, const char col_delimiter){
  CSV csv;
  csv.load_file(file_name, col_delimiter);

  int nb_cols = csv.get_colmuns_number();

  this->columns.resize(nb_cols);

  const std::vector<std::string> header = csv.get_header();

  for(int i=0 ;  i < nb_cols ; i++){
    this->columns[i].set_name(header[i]);
  }

  while(!csv.empty_list()){
    std::vector<std::string> row = csv.get_next_row();
    int i = 0;
    for(std::string str_col : row){
      unsigned char type = Parser::get_type(str_col);
      DataType *data_value = nullptr;
      if (type == Parser::IS_NULL) {
        data_value = new Null(str_col);
      }

      if(type == Parser::IS_LONG){
        data_value = new Integer(str_col);
      }

      if (type == Parser::IS_DOUBLE) {
        data_value = new Float(str_col);
      }

      if (type == Parser::IS_STRING) {
        data_value = new String(str_col);
      }

      this->columns[i].add_value(data_value);
      i++;
    }

  }

  return 0;
}

void DataFrame::describe(){
  
  for(Column col : this->columns){
    std::cout << "Column name : " << col.get_name() << std::endl;
    std::cout << "\t- total : " << col.total() << std::endl;
    std::map<std::string, unsigned int> by_type = col.total_by_type();
    for(auto e : by_type){
      std::cout << "\t- " << e.first << " : " << e.second << std::endl;
    }
  }

}

void DataFrame::head(int size){
  unsigned int i = 0;
  while(i<size){
    for (Column col : this->columns) {
      std::cout << "|" << std::setw(12)
                << col.data[i]->get_str_value().substr(0, 12);
    }
    std::cout << std::endl;
    i++;
  }

}

void DataFrame::tail(int size) {
  if(this->columns.size() == 0){ return;}
  unsigned int nb_lignes = this->columns[0].data.size();
  std::cout << nb_lignes << std::endl;
  unsigned int i = nb_lignes - size;
  while (i < nb_lignes) {
    for (Column col : this->columns) {
      std::cout << "|" << std::setw(12)
                << col.data[i]->get_str_value().substr(0, 12);
    }
    std::cout << std::endl;
    i++;
  }
}

void DataFrame::add_column() {}

void DataFrame::addline() {}
