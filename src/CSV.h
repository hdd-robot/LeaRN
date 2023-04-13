#ifndef _LEA_CSV_
#define _LEA_CSV_

#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <list>
#include <sstream>
#include <istream>
#include <iomanip>

namespace LeaRN{
  class CSV{

  private:
    bool file_is_read = false;
    std::string filename;
    unsigned int col_numbers = 0;

    std::list<std::vector<std::string>*> lst_lines;

    std::vector<std::string>* csv_read_row(std::istream &in, char delimiter);
    std::vector<std::string>* csv_read_row(std::string &in, char delimiter);


  public:
    CSV();
    virtual ~CSV();
    void load_file(const std::string& filename, char col_delimiter);
    void print_data();
    std::vector<std::string> get_colmuns ();
    int get_colmuns_number ();
    std::vector<std::string>* get_next_row();
  };
}

#endif
