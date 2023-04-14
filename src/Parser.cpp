#include "Parser.h"
#include <boost/spirit/home/qi/numeric/real.hpp>

using namespace LeaRN;

const unsigned char Parser::IS_NULL   = 1;
const unsigned char Parser::IS_LONG   = 2;
const unsigned char Parser::IS_DOUBLE = 3;
const unsigned char Parser::IS_STRING = 4;

unsigned char Parser::get_type(std::string str) {
  if(str.length() == 0){
    return Parser::IS_NULL;
  }

  std::string str2 = boost::to_upper_copy<std::string>(str);
  str2.erase(std::remove_if(str2.begin(), str2.end(), ::isspace), str2.end());
  if(str2.compare("NULL") == 0){
    return Parser::IS_NULL;
  }

  auto l = str.begin();
  auto f = str.end();
  if (qi::parse(l, f, qi::int_) && (l == f)) {
    return Parser::IS_LONG;
  }
  if (qi::parse(l, f, qi::double_) && (l == f)) {
    return Parser::IS_DOUBLE;
  }

  return Parser::IS_STRING;
}
