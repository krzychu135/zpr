#include "includes.h"

#include "boost/noncopyable.hpp"

class Parser;

class ParserFactory : public boost::noncopyable
///Manages various Parsers, trying to match them to input strings
{
///Implemented as Singleton
public:
	///singleton safe getter
	static ParserFactory & get();

	///all known parsers are instantiated and added to parsers collection
	void initParsers();
	///add new parser to the list of used parsers
	void registerParser (const Parser & parser);
///try to extract sequences from given text, returning tru if input was parsed successfully and false otherwise
	bool tryToParse (std::string & text);
	std::vector <boost::shared_ptr<std::vector <Sequence>>> allSequences;
private:
	std::vector<Parser*> parsers;

	ParserFactory();
	~ParserFactory();
};
