#ifndef _LEA_DATA_TYPE_H_
#define _LEA_DATA_TYPE_H_
#include <string>


namespace LeaRN {
  class DataType {
  private:

  protected:
    std::string value;
  public:
    virtual ~DataType();

    DataType(std::string param);
    virtual std::string get_str_value(){return this->value;}
    
  };
}
#endif
