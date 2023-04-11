#ifndef _LEA_DATAFRAME_
#define _LEA_DATAFRAME_

#include <fstream>
#include <sstream>
#include <iostream>
#include <string>
#include <map>
#include <vector>
#include "Column.h"

namespace LeaRN{
  class DataFrame{
  private:
    std::map <unsigned int, Column> columns;


    void add_column();
    void addline();

    void head();
    void tail();

  public:
    int load_csv(const std::string &file_name, const char col_delimiter = ',');
  };
}


#endif
