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
    //String(const String &string) :DataType(string.value){this->string_value = string.string_value;};
    
    String(std::string param);
    virtual String *clone() { return new String(*this); }
  };
} // namespace LeaRN
#endif
