#ifndef _LEA_COLUMN__
#define _LEA_COLUMN_
#include <string>
#include <map>
#include "DataType.h"

namespace LeaRN{
  class Column {
  public:
    Column();
  private:
    unsigned int number;
    std::string name;
    std::map<unsigned long, DataType> data;
  };
}

#endif
