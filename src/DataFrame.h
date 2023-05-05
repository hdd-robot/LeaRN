/**
 * @file      DataFrame.h
 * @brief     Header of DataFrame
 * @date      Mon Apr 24 16:16:01 2023
 * @author    Halim Djerroud
 * @copyright GPL3
 *
 * This DataFrame
 */

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

#include <algorithm>
#include <fstream>
#include <iostream>
#include <istream>
#include <map>
#include <random>
#include <sstream>
#include <string>

namespace LeaRN{

  class DataFrame {
  private:
    std::vector<Column> columns;
    std::vector<unsigned int> learn_set;
    std::vector<unsigned int> test_set;
  public:
    DataFrame(){}
    void add_column();
    void addline();

    void describe();
    void head(int size = 10);
    void tail(int size = 10);

    
    int get_cols_number(){return columns.size();}
    int get_row_number();


    void split(DataFrame &leran, DataFrame &test, int percent = 25,
               bool scramble = true);

    int load_csv(const std::string &file_name, const char col_delimiter = ',');
  };
}

#endif
