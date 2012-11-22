#include "stdafx.h"

#include "boost\noncopyable.hpp"

class Parser;

class ParserFactory : public boost::noncopyable
///Singleton
{
public:
	static ParserFactory & get();

	void initParsers();
	void registerParser (const Parser & parser);
	void tryToParse (std::string & text); //TODO: file
private:
	std::vector<Parser*> parsers;

	ParserFactory();
	~ParserFactory();
};