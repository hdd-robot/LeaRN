#ifndef _LEA_STRING_H_
#define _LEA_STRING_H_

#include <string>
#include "Parser.h"
#include "DataType.h"

namespace LeaRN {
  class String : public DataType {
  private:
    std::string string_value;
  public :
    virtual ~String() {}
    String(std::string param);
  };
} // namespace LeaRN
#endif
