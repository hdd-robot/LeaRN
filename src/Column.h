#ifndef _LEA_COLUMN_
#define _LEA_COLUMN_


#include <string>
#include <vector>
#include <map>
#include "DataType.h"
#include "Null.h"
#include "String.h"
#include "Integer.h"
#include "Float.h"



namespace LeaRN{
  class Column {

  private:
    unsigned int number;
    std::string name;
  public:
    std::vector<DataType *> data;  // a mettre en Privé 
    Column();
    virtual ~Column();
    void add_value(DataType * value);
    void set_name(std::string name) { this->name = name;}
    const std::string& get_name() { return this->name = name; }
    int total() {return this->data.size(); }
    std::map<std::string, unsigned int> total_by_type();
  };
}

#endif
