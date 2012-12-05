#include "stdafx.h"
#include "Parser.h"

#include <boost/spirit/include/qi.hpp>
#include <boost/spirit/include/phoenix.hpp>
#include <boost/fusion/adapted.hpp>
#include <boost/fusion/include/io.hpp>

namespace qi = boost::spirit::qi;
namespace ascii = boost::spirit::ascii;
namespace spirit = boost::spirit;

using qi::double_;
using qi::uint_;
//using qi::val_;
using qi::lexeme;
using qi::_1;
using qi::phrase_parse;
using qi::eps;
using qi::omit;
using qi::eol;
using ascii::space;
using ascii::char_;
using ascii::space_type;
//using ascii::str;
using boost::phoenix::ref;

typedef std::pair<unsigned int, unsigned int> range;
typedef std::vector<range> vrange_t;

#define BOOST_SPIRIT_DEBUG_PRINT_SOME 80

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

template <typename Iterator>
struct parseFullExData : qi::grammar <Iterator, std::vector<FullExData>()>
{
	parseFullExData() : parseFullExData::base_type (output)
	{
		//std::cout << "Hello parser!\n";

		output %= fullExData;

		fullExData =
			omit [lexeme["Seq"]] >>
			omit [space] >>
			omit [uint_] >>
			omit [space] >>
			omit [lexeme["Len:"]] >>
			omit [-eol] >>
			omit [-eol] >>
			omit [uint_] >>
			omit [-uint_] >>
			omit [lexeme["UTR"]] >>
			omit [*eol] >>
			omit [lexeme["Intergenic"]] >>
			omit [*eol] >>
			//omit [!lexeme["Introns"]] >>
			"Introns" >>
			omit [-eol] >>
			//omit [!uint_] >> 
			pairSequence >>
			omit [-eol] >>
			//omit [!lexeme["Exons"]] >>
			"Exons" >>
			omit [-eol] >>
			//omit [!uint_] >>
			pairSequence >>
			omit [-eol] >>
			//omit [!lexeme["Data"]] >>
			"Data" >>
			omit [-eol] >>
			//omit [!actg] >>
			actg >>
			omit [-eol]
		;

		pairSequence =
			pair >>
			omit[space]
		;

		pair =
			uint_ >>
			space >>
			uint_ //two numbers separated by space
		;

		actg = *(char_("actgACTG"));

		BOOST_SPIRIT_DEBUG_NODE (fullExData);
		BOOST_SPIRIT_DEBUG_NODE (pairSequence);
		BOOST_SPIRIT_DEBUG_NODE (pair);
		BOOST_SPIRIT_DEBUG_NODE (actg);
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
	//return true; //test

	std::vector<FullExData> v;

	typedef std::string::const_iterator iterator_type;
	iterator_type iter = text.begin();
	iterator_type end = text.end();
	typedef parseFullExData<iterator_type> P;
	P parser;

	bool success = qi::parse (iter, end, parser, v);
	return success;
}
void ParserFullEx::getSequences(std::vector<Sequence> & out) const
{
	for (int i = 0; i < 10; ++i)
	{
		Sequence seq;
		TSamples samples;
		for (int j = 0; j < 9; ++j)
		{
			samples.push_back (j - 3 * i);
			for (int k = 0; k < 13; ++k)
			{
				samples.push_back ((i * j + k) % 7);
			}
		}
		seq.setSamples(samples);
		out.push_back (seq);
	}
}