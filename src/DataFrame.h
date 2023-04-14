#ifndef _LEA_DATAFRAME_
#define _LEA_DATAFRAME_

#include "CSV.h"
#include "Column.h"
#include "DataType.h"
#include "Null.h"
#include "Integer.h"
#include "String.h"
#include "Float.h"
#include "Parser.h"

#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <sstream>
#include <string>
#include <vector>

namespace LeaRN{

  class DataFrame {
  private:
    std::vector<Column> columns;

  public:
    void add_column();
    void addline();

    void describe();
    void head();
    void tail();

    int load_csv(const std::string &file_name, const char col_delimiter = ',');
  };
}

#endif
