#ifndef _LEA_COLUMN_
#define _LEA_COLUMN_

#include <string>
#include <vector>
#include "DataType.h"

namespace LeaRN{
  class Column {

  private:
    unsigned int number;
    std::string name;
    std::vector<DataType *> data;

  public:
    Column();
    virtual ~Column();
    void add_value(std::string value);
    void set_name(std::string name) { this->name = name;}
    const std::string& get_name() { return this->name = name; }
    int total() {return this->data.size(); }

  };
}

#endif
