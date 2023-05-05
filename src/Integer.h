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
    long long int get_value () {return this->integer_value; }
    Integer* clone() const;
  };
}// namespace LeaRN
#endif
