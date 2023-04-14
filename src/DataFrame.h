#ifndef _LEA_DATAFRAME_
#define _LEA_DATAFRAME_


#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <sstream>
#include <istream>
#include <map>
#include "CSV.h"
#include "Column.h"

namespace LeaRN{
  class DataFrame{
  private:
    std::vector<Column> columns;


    void add_column();
    void addline();

    void head();
    void tail();

  public:
    int load_csv(const std::string &file_name, const char col_delimiter = ',');
  };
}


#endif
