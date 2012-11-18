#include "stdafx.h"

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
void ParserFactory::tryToParse (Tfile & file)
{}
ParserFactory::~ParserFactory()
{
	BOOST_FOREACH (auto p, parsers)
		delete p;
}