#include "DataFrame.h"
#include <string>
#include <vector>


using namespace LeaRN;

const unsigned char DataFrame::ALL_SET   = 1;
const unsigned char DataFrame::LEARN_SET = 2;
const unsigned char DataFrame::TEST_SET  = 3;

void DataFrame::clear() {
  this->columns.clear();
  this->learn_set.clear();
  this->test_set.clear();

}

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

int DataFrame::get_row_number() {
  if (this->get_cols_number() == 0) {
    return 0;
  }
  return this->columns[0].total();
}

void DataFrame::split(DataFrame &leran, DataFrame &test, int percent, bool scramble) {
  if(this->get_row_number() == 0){
    throw std::logic_error("No lines in the dataframe");
    return;
  }

  std::vector<unsigned int>nums;
  int row_numebers = this->get_row_number();
  nums.resize(row_numebers);
  for (unsigned int i = 0; i < row_numebers ; i++) {
    nums[i]=i;
  }

  if (scramble == true){
    std::random_device rd;
    std::default_random_engine rng(rd());
    shuffle(nums.begin(), nums.end(), rng);
  }

  int test_size = (this->get_row_number() * percent) / 100;
  int learn_size = this->get_row_number() - test_size;


  leran.clear();
  test.clear();
  leran.columns.resize(this->get_cols_number());
  test.columns.resize(this->get_cols_number());

  // learn
  for (int i=0 ; i < learn_size ; i++){
    int k = 0;
    for(int j = 0; j<this->columns.size() ; j++){
      leran.columns[k++].add_value(this->columns[j].data[nums[i]]->clone());
    }
  }

  //test
  for (int i = learn_size; i < test_size + learn_size; i++) {
    int k = 0;
    for (int j = 0; j < this->columns.size(); j++) {
      test.columns[k++].add_value(this->columns[j].data[nums[i]]->clone());
    }
  }
}
