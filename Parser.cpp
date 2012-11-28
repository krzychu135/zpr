#include "stdafx.h"
#include "Parser.h"

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix_core.hpp>
#include <boost/spirit/include/phoenix_operator.hpp>
#include <boost/fusion/adapted/std_pair.hpp> //makes std::pair compatible with qi random acces sequence
#include <boost/fusion/include/std_pair.hpp>
#include <boost/fusion/include/adapt_struct.hpp>
#include <boost/fusion/include/io.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;

using qi::double_;
using qi::uint_;
//using qi::val_;
using qi::lexeme;
using qi::_1;
using qi::phrase_parse;
using qi::eps;
using qi::omit;
using ascii::space;
using ascii::char_;
using ascii::space_type;
//using ascii::str;
using boost::phoenix::ref;

typedef std::pair<unsigned int, unsigned int> range;
typedef std::vector<range> vrange_t;

struct FullExData
{
	vrange_t introns;
	vrange_t exons;
	std::string data;
};

BOOST_FUSION_ADAPT_STRUCT(
	FullExData,
	(vrange_t, introns)
	(vrange_t, exons)
	(std::string, data)
)

struct ACTG : qi::symbols<char, unsigned>
{
	ACTG()
	{
		add
			("A" , 1)
			("C" , 2)
			("T" , 3)
			("G" , 4)
		;
	}
} actg;

template <typename Iterator>
struct parseFullExData : qi::grammar <Iterator, std::vector<FullExData>()>
{
	parseFullExData() : parseFullExData::base_type (output)
	{
		output %= fullExData;

		fullExData =
			"Introns" >>
			pairSequence >>
			"Exons" >>
			pairSequence >>
			"Data" >>
			actg
		;

		pair =
			uint_ >>
			space >>
			uint_ //two numbers separated by space
		;

		pairSequence =
			pair >>
			omit[space]
		;

		actg = *(char_("actgACTG"));
	}

	qi::rule<Iterator, range()> pair;
	qi::rule<Iterator, std::vector<range>()> pairSequence; //pairs are delimited by another space
	qi::rule<Iterator, std::string()> actg;
	qi::rule<Iterator, FullExData()> fullExData;
	qi::rule<Iterator, std::vector<FullExData>()> output; 
};

void ParserSplice::getSequences(std::vector<Sequence> & out) const
{
}

bool ParserFullEx::tryToParse (std::string & text)
{
	std::vector<FullExData> v;

    typedef std::string::const_iterator iterator_type;
	//typedef std::string::iterator iterator_type;
	iterator_type iter = text.begin();
	iterator_type end = text.end();
    typedef parseFullExData<iterator_type> P;
    P parser;

	bool success = qi::phrase_parse (iter, end, parser, space, v);
	int size = v.size();
	return success;
}
void ParserFullEx::getSequences(std::vector<Sequence> & out) const
{
}