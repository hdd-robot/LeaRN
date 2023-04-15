#include "String.h"

using namespace LeaRN;

String::String(std::string param) : DataType(param) {
  this->string_value = "";
  if (Parser::get_type(param) == Parser::IS_STRING) {
    this->string_value = param;
  }
}
