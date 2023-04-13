#ifndef _LEA_COLUMN__
#define _LEA_COLUMN_
#include <string>
#include <vector>

#include "DataType.h"

namespace LeaRN{
  class Column {
  public:
    Column();
    virtual ~Column();
    void add_value(std::string value);

  private:
    unsigned int number;
    std::string name;
    std::vector<DataType *> data;
    
  };
}

#endif
