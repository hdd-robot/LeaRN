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

    // DataType(const DataType &dataType){ this->value = dataType.value;     };

    virtual std::string get_str_value(){return this->value;}

    virtual DataType *clone() const { return new DataType(*this); }
  };
}


#endif
