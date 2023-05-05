#include "Float.h"


using namespace LeaRN;

Float::Float(std::string param): DataType(param){
  this->float_value = 0.0;
  if (Parser::get_type(param) == Parser::IS_DOUBLE) {
    this->float_value = std::stoll(param);
  }
}


