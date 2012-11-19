#include "stdafx.h"
#include "Parser.h"

#include "boost\spirit\include\classic.hpp"
#include "boost\spirit\include\qi.hpp"
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/fusion/adapted/std_pair.hpp> //makes std::pair compatible with qi random acces sequence
#include <boost/fusion/include/std_pair.hpp>
#include <boost/fusion/include/io.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

using qi::double_;
using qi::uint_;
//using qi::val_;
using boost::spirit::qi::_1;
using qi::phrase_parse;
using ascii::space;
using ascii::space_type;
using boost::phoenix::ref;

typedef std::pair<unsigned int, unsigned int> range;

template <typename Iterator>
struct parseRange : qi::grammar <Iterator, range(), space_type>
{
	parseRange() : parseRanger::base_type (pair)
	{
		pair %=
			uint_ >>
			space_type >>
			uint_ //two numbers separated by space
		;
	}

	qi::rule<Iterator, range(), space_type> pair; //pairs are delimited by another space
};

void ParserSplice::getSequences(std::vector<Sequence> & out) const
{
}
void ParserFullEx::getSequences(std::vector<Sequence> & out) const
{
}