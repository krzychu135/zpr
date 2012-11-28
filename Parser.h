#include "stdafx.h"

#include "boost/noncopyable.hpp"

#include "Sequence.h"

class Sequence;


class Parser : public boost::noncopyable
{
public:
	virtual void getSequences (std::vector<Sequence> & out) const = 0;
	virtual bool tryToParse (std::string & text) {return false;};
};

class ParserSplice : public Parser //TODO: bardziej sensowna nazwa?
{
public:
	ParserSplice(){};
	virtual bool tryToParse (std::string & text) {return false;};
	void getSequences (std::vector<Sequence> & out) const;
};

class ParserFullEx : public Parser //TODO: bardziej sensowna nazwa?
{
public:
	ParserFullEx(){};
	virtual bool tryToParse (std::string & text);
	void getSequences (std::vector<Sequence> & out) const;
};
