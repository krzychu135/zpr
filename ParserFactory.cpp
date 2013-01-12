#include "includes.h"

#include "Parser.h"
#include "ParserFactory.h"

ParserFactory & ParserFactory::get()
{
	static ParserFactory pfInstance;
	return pfInstance;
}

ParserFactory::ParserFactory()
{}
void ParserFactory::initParsers()
{
	parsers.push_back (new ParserSplice());
	parsers.push_back (new ParserFullEx());
}
void ParserFactory::registerParser (const Parser & parser)
{}
bool ParserFactory::tryToParse (std::string & text)
{
	BOOST_FOREACH (auto p, parsers)
	{
		boost::shared_ptr <std::vector<Sequence>> sequences (new std::vector<Sequence>);
		if (p->tryToParse (text))
		{
			p->getSequences (*sequences);
			if (sequences->size())
				allSequences.push_back (sequences);
			return true;
		}
	}
	return false;

}
ParserFactory::~ParserFactory()
{
	BOOST_FOREACH (auto p, parsers)
		delete p;
}