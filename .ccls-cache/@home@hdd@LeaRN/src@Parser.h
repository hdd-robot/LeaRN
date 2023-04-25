#ifndef _LEA_PARSER_H_
#define _LEA_PARSER_H_
#include <string>
#include <cstring>
#include <boost/config/warning_disable.hpp>
#include <boost/foreach.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/spirit/home/support/context.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_fusion.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/spirit/include/phoenix_stl.hpp>
#include <boost/spirit/include/qi.hpp>
#include <boost/variant/recursive_variant.hpp>
#include <boost/algorithm/string.hpp>


namespace sp = boost::spirit;
namespace qi = boost::spirit::qi;

namespace LeaRN {
class Parser {

public:
  static const unsigned char IS_NULL;
  static const unsigned char IS_LONG;
  static const unsigned char IS_DOUBLE;
  static const unsigned char IS_STRING;

  static unsigned char get_type(std::string str);
};
} // namespace LeaRN
#endif
