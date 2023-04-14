#include "DataFrame.h"

#include <Null.h>
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
    for(std::string str_col : row){
      unsigned char type = Parser::get_type(str_col);
      DataType *data_value;
      if (type == Parser::IS_NULL) {
        data_value = new Null();
        /// to be continue 
      }

      if(type == Parser::IS_LONG){

      }
      if (type == Parser::IS_DOUBLE) {

      }
      if (type == Parser::IS_STRING) {

      }
    }

  }

  return 0;
}

void DataFrame::describe(){
  
  for(Column col : this->columns){
    std::cout << "Column name : " << col.get_name() << std::endl;
    std::cout << "\t- total : " << col.total() << std::endl;
  }

}

void DataFrame::head(){
  
}

void DataFrame::tail(){

}

void DataFrame::add_column(){
  

}

void DataFrame::addline(){

}

