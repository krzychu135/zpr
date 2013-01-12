#include "includes.h"
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

BOOST_FUSION_ADAPT_STRUCT(
	FullExData,
	(vrange_t, introns)
	(vrange_t, exons)
	(std::string, data)
)

template <typename Iterator>
struct parseFullExData : qi::grammar <Iterator, std::vector<FullExData>()>
///main grammar for ParserFullEx class
{
	parseFullExData() : parseFullExData::base_type (output)
	{
		output %= +fullExData;

		fullExData =
			omit [lexeme[">Seq"]] >>
			omit [space] >>
			omit [uint_] >>
			omit [space] >>
			omit [lexeme["Len:"]] >>
			omit [eol] >>

			omit [uint_] >>
			omit [eol] >>

			omit [uint_] >>
			omit [lexeme["UTR"]] >>
			omit [*eol] >>

			omit [lexeme["Intergenic"]] >>
			omit [*eol] >>
			omit ["Introns"] >>
			omit [eol] >>

			pairSequence >>
			omit [eol] >>

			omit ["Exons"] >>
			omit [eol] >>

			pairSequence >>
			omit [eol] >>

			omit [uint_] >>
			omit [lexeme["UTR"]] >>
			omit [*eol] >>

			omit ["Data"] >>
			omit [eol] >>

			actg >>
			omit [-eol] //possibly end of file
		;

		pairSequence %= +pair
		;

		pair = //two numbers separated by space
			//starts with space
			omit [space] >>
			uint_ >>
			omit [space] >>
			uint_
		;

		actg = *(char_("actgACTG"));

		//BOOST_SPIRIT_DEBUG_NODE (fullExData);
		//BOOST_SPIRIT_DEBUG_NODE (pairSequence);
		//BOOST_SPIRIT_DEBUG_NODE (pair);
		//BOOST_SPIRIT_DEBUG_NODE (actg);
	}

	qi::rule<Iterator, range()> pair;
	qi::rule<Iterator, vrange_t()> pairSequence; //pairs are delimited by another space
	qi::rule<Iterator, std::string()> actg;
	qi::rule<Iterator, FullExData()> fullExData;
	qi::rule<Iterator, std::vector<FullExData>()> output; 
};

bool ParserFullEx::tryToParse (std::string & text)
{
    //return true; //test
	//return false;

	typedef std::string::const_iterator iterator_type;
	iterator_type iter = text.begin();
	iterator_type end = text.end();
	typedef parseFullExData<iterator_type> P;
	P parser;

	bool success = qi::parse (iter, end, parser, data);
	return success;

}
void ParserFullEx::getSequences(std::vector<Sequence> & out) const
{
	Sequence seq;

	BOOST_FOREACH (auto fullExData, data)
	{
		BOOST_FOREACH (auto intron, fullExData.introns)
		{
			TSamples samples (fullExData.data.begin() + intron.first, fullExData.data.begin() + intron.second); //copy range
			seq.setSamples (samples);
			out.push_back (seq);
		}
		BOOST_FOREACH (auto exon, fullExData.exons)
		{
			TSamples samples (fullExData.data.begin() + exon.first, fullExData.data.begin() + exon.second); //copy range
			seq.setSamples (samples);
			out.push_back (seq);
		}
    }
}

struct SpliceData
///helper data struct fro Splice parser
{
	unsigned active; //0 - pomijamy
	std::string sequence;
};

BOOST_FUSION_ADAPT_STRUCT(
	SpliceData,
	(unsigned, active)
	(std::string, sequence)
)

struct SpliceChunk
///helper data struct fro Splice parser
{
	size_t position;
	std::vector<SpliceData> data;
};

template <typename Iterator>
struct parseSpliceData : qi::grammar <Iterator, std::vector<SpliceData>()>
///main grammar for ParserSplice class
{
	parseSpliceData() : parseSpliceData::base_type (output)
	{
		output %= +spliceData;

		spliceData =
			uint_ >>
			omit [eol] >>
			actg >>
			omit [eol]
		;

		actg = *(char_("actgACTG"));

		//BOOST_SPIRIT_DEBUG_NODE (spliceData);
		//BOOST_SPIRIT_DEBUG_NODE (actg);
	}

	qi::rule<Iterator, std::string()> actg;
	qi::rule<Iterator, SpliceData()> spliceData;
    qi::rule<Iterator, std::vector<SpliceData>()> output;
};

template <typename Iterator>
struct parseUnsigned : qi::grammar <Iterator, unsigned()>
///helper parser that outputs unsigned integer
{
	parseUnsigned() : parseUnsigned::base_type (output)
	{
		output %= uint_;
	}

    qi::rule<Iterator, unsigned()> output;
};

bool ParserSplice::tryToParse (std::string & text)
{
    //return true; //test
	//return false;

	auto chunk = new SpliceChunk;

	typedef std::string::const_iterator iterator_type;
	iterator_type iter = text.begin();
	size_t newLine = text.find('\n');
	iterator_type end = text.begin() + newLine; //first char after the number
	typedef parseSpliceData<iterator_type> P1;
	P1 spliceParser;
	typedef parseUnsigned<iterator_type> P2;
	P2 unsignedParser;

	bool r = qi::parse(iter, end, unsignedParser, chunk->position);
	//BOOST_SPIRIT_DEBUG_NODE (spliceParser);
	iterator_type afterNumberPos = text.begin() + newLine + 1;
	end = text.end(); //to avoid g++ compilation issues
    bool success = qi::parse (afterNumberPos, end, spliceParser, chunk->data);
    if (success)
		dataChunks.push_back (boost::shared_ptr<SpliceChunk>(chunk));
    return success;
}

void ParserSplice::getSequences(std::vector<Sequence> & out) const
{
	BOOST_FOREACH (auto chunk, dataChunks)
	{
		BOOST_FOREACH (auto data, chunk->data)
		{
			if (!data.active)
				continue; //do not use sequences with data = 0
			Sequence seq;
			TSamples introns;
			assert (data.sequence.size() >= chunk->position);

			for (int i = 0; i < chunk->position; ++i)
			{
				introns.push_back (data.sequence[i]);
			}
			seq.setSamples (introns);
			out.push_back(seq);

			TSamples exons;
			for (int i = chunk->position; i < data.sequence.size(); ++i)
			{
				exons.push_back (data.sequence[i]);
			}
			seq.setSamples (exons);
			out.push_back(seq);
		}
    }
}
