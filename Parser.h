#include "includes.h"

#include "boost/noncopyable.hpp"

#include "Sequence.h"

typedef std::pair<unsigned, unsigned> range;
typedef std::vector<range> vrange_t;

class Sequence;
struct SpliceChunk;
struct FullExData;

class Parser : public boost::noncopyable
///Transforms input text to output data sequences
{
public:
	///tries to parse text to internal structures of parser
	virtual bool tryToParse (std::string & text) {return false;};
	///generates actual Sequences ready to analyze from internal structures
	virtual void getSequences (std::vector<Sequence> & out) const = 0;
};

class ParserSplice : public Parser
{
	std::vector<boost::shared_ptr<SpliceChunk> > dataChunks;
public:
	ParserSplice(){};
	virtual bool tryToParse (std::string & text);
	void getSequences (std::vector<Sequence> & out) const;
};

struct FullExData
///internal data structure used by ParserFullEx
{
	vrange_t introns;
	vrange_t exons;
	std::string data;
};

class ParserFullEx : public Parser
{
	std::vector<FullExData> data;
public:
	ParserFullEx(){};
	virtual bool tryToParse (std::string & text);
	void getSequences (std::vector<Sequence> & out) const;
};
