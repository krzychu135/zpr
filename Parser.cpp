#include "stdafx.h"
#include "Parser.h"

#include "boost\spirit\include\classic.hpp"
#include "boost\spirit\include\qi.hpp"
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

using qi::double_;
using boost::spirit::qi::_1;
using qi::phrase_parse;
using ascii::space;
using boost::phoenix::ref;

typedef std::pair<double, double> range;

template <typename Iterator>
bool parseRange (Iterator first, Iterator last, range& limits)
{
	double first, second;
    bool r = phrase_parse(first, last,

        (
			double_[ref(first) = _1] >>
			space >>
			double_[ref(second) = _1] //two numbers separated by space
        ),
        space); //pairs are delimited by another space

    if (!r || first != last) // fail if we did not get a full match
        return false;
    limits = range(first, second);
    return r;
}

void ParserSplice::getSequences(std::vector<Sequence> & out) const
{
}
void ParserFullEx::getSequences(std::vector<Sequence> & out) const
{
}