#ifndef _LEA_FLOAT_H_
#define _LEA_FLOAT_H_

#include "DataType.h"
#include "Parser.h"

namespace LeaRN  {
  class Float : public DataType{
  private:
    double float_value;
  public:
    virtual ~Float(){}
    Float(std::string param);

  };
}
#endif

