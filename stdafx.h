// stdafx.h : include file for standard system include files,
// or project specific include files that are used frequently, but
// are changed infrequently
//
#define BOOST_SPIRIT_DEBUG_PRINT_SOME 80
#define BOOST_SPIRIT_DEBUG

#pragma once

#include <stdio.h>
#include <vector>
#include <string>
#include <iostream>
#include <cstdlib> //malloc
// TODO: reference additional headers your program requires here

#include "boost/foreach.hpp"
#include "boost/assign.hpp"
using namespace boost::assign;
#include "boost/shared_ptr.hpp"

#include <boost/iostreams/stream.hpp>
#include <boost/iostreams/stream_buffer.hpp>
#include <boost/iostreams/device/file.hpp>
namespace io = boost::iostreams;
//typedef io::stream_buffer<io::file_source> Tfile;

