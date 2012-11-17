#include "stdafx.h"

#include "boost\noncopyable.hpp"

#include "Sequence.h"

class Sequence;

class Parser : public boost::noncopyable
{
public:
	virtual void loadFile (std::string & name) = 0;
	virtual void getSequences (std::vector<Sequence> & out) const = 0;
	virtual bool tryToParse (Tfile & file) {return false;};
};

class ParserSplice : public Parser //TODO: bardziej sensowna nazwa?
{
public:
	ParserSplice(){};
	void loadFile (std::string & name){};
	void getSequences (std::vector<Sequence> & out) const;
};

class ParserFullEx : public Parser //TODO: bardziej sensowna nazwa?
{
public:
	ParserFullEx(){};
	void loadFile (std::string & name){};
	void getSequences (std::vector<Sequence> & out) const;
};