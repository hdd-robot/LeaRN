#include "Column.h"



using namespace LeaRN;

Column::Column(){
  
}

Column::Column(Column &col){
  
  std::vector<DataType *>::iterator data_it ;
  for (data_it = this->data.begin(); data_it < this->data.end(); data_it++) {
    
  }
}

Column::~Column() {}

void Column::add_value(DataType *  value){
  this->data.push_back(value);
}

std::map<std::string, unsigned int> Column::total_by_type() {
  std::map<std::string, unsigned int> desc;

  desc["null"] = 0;
  desc["string"] = 0;
  desc["int"] = 0;
  desc["float"] = 0;

  for(unsigned int i = 0 ; i < data.size() ; i++){

    if (dynamic_cast<Null *>(data[i]) != nullptr) {
      desc["null"]++;
    }

    if (dynamic_cast<String *>(data[i]) != nullptr) {
      desc["string"]++;
    }
    if (dynamic_cast<Integer *>(data[i]) != nullptr) {
      desc["int"]++;
    }
    if (dynamic_cast<Float *>(data[i]) != nullptr) {
      desc["float"]++;
    }
  }
  return desc;
}
