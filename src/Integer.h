#ifndef _LEA_INTEGER_H_
#define _LEA_INTEGER_H_

#include "DataType.h"
#include "Parser.h"

namespace LeaRN {
  class Integer : public DataType {
  private:
    long long int integer_value;

  public:
    virtual ~Integer(){};
    Integer(std::string param);
    //Integer(const Integer &integer):DataType(integer.value){this->integer_value = integer.integer_value;};
    long long int get_value () {return this->integer_value; }
    virtual Integer *clone() const { return new Integer(*this); }
  };
}// namespace LeaRN
#endif
