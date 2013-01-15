

#include "includes.h"

#ifndef EXCEPTIONS_H_
#define EXCEPTIONS_H_

class namedException : public std::exception
///simple class which stores message about possible type/reason of exception
{
public:
	std::string message;
    namedException (std::string  text) {message = text;};
    ~namedException() throw() {};

};

class fileException : public namedException
{
public:
    fileException (std::string  text) : namedException (text) {};
};

class parserException : public namedException
{
public:
    parserException (std::string  text) : namedException (text) {};
};

class memoryException : public namedException
{
public:
    memoryException (std::string  text) : namedException (text) {};
};
class nullPointerException: public memoryException
{
public:
    nullPointerException(std::string text): memoryException(text){};
};

class guiException : public namedException
{
public:
    guiException (std::string text) : namedException(text) {}
};

//std::ostream & operator << (std::ostream & os, const namedException & e) 
//{
//	os << e.message;
//	return os;
//}

#endif //EXCEPTIONS_H_
