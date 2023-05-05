#include "DataType.h"
 
using namespace LeaRN;

DataType::DataType(std::string param) : value(param){
  
}

DataType::~DataType() {}

DataType *DataType::clone() const{
  return new DataType(*this);
}
