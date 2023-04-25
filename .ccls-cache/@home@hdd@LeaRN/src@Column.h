/**
 * @file      Column.h
 * @brief     Header of
 * @date      Mon Apr 24 16:10:46 2023
 * @author    Halim Djerroud
 * @copyright GPL-3
 * 
 * This COLUMN
 */

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

    /**
     * @brief count number of lines
     * @details count number of lines
     * @return total number of lines in this column
     */
    int total() {return this->data.size(); }
    std::map<std::string, unsigned int> total_by_type();
  };
}

#endif
