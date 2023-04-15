#ifndef _LEA_STRING_H_
#define _LEA_STRING_H_

#include <string>

#include "DataType.h"

namespace LeaRN {
  class String : public DataType {
  private:

  public:
    std::string get_value();
  };
} // namespace LeaRN
#endif
