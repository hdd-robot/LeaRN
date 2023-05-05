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
    int column_type;
  public:
    static const unsigned char FEATURE;
    static const unsigned char LABEL;
    static const unsigned char UNKNOWN;

    int get_column_type(){return column_type;}
    void set_column_type(int col_type) { column_type = col_type; }

    std::vector<DataType *> data;  // a mettre en Privé 
    Column();
    Column(Column &&col) : Column(col){};
    Column(Column& col);
    virtual ~Column();
    void add_value(DataType * value);
    void set_name(std::string name) { this->name = name;}

    const std::string& get_name() { return this->name; }

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
