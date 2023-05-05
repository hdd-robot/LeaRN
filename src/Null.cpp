#include "Null.h"
#include <cstddef>

using namespace LeaRN;


Null::Null(std::string param) : DataType(param) {
}

Null* Null::clone(){
  return new (*this);
}
