#include "Integer.h"


using namespace LeaRN;

Integer::Integer(std::string param) : DataType(param) {
  this->integer_value = 0.0;
  if (Parser::get_type(param) == Parser::IS_LONG) {
    this->integer_value = std::stold(param);
  }
}

Integer *Integer::clone() const {
  return new DataType(*this);
  }
