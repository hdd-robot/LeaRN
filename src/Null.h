#ifndef _LEA_NULL_H_
#define _LEA_NULL_H_

#include <string>
#include "DataType.h"

namespace LeaRN {
  class Null : public DataType {
  private:

  public:
    virtual ~Null(){};
    Null(std::string param);
    long long int get_value ();

  };
}// namespace LeaRN
#endif
