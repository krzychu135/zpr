#include "stdafx.h"

#include "Sequence.h"

class Sequence;

class Parser
{
public:
	virtual void loadFile (std::string & name) = 0;
	virtual void getSequences (std::vector<Sequence> & out) = 0;
};

class ParserA : public Parser //TODO: bardziej sensowna nazwa?
{
	void loadFile (std::string & name){};
	void getSequences (std::vector<Sequence> & out) const;
};

class ParserB : public Parser //TODO: bardziej sensowna nazwa?
{
	void loadFile (std::string & name){};
	void getSequences (std::vector<Sequence> & out) const;
};