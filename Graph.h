#include "stdafx.h"

#include "Sequence.h"

class Sequence;

class GraphWindow
{
	std::vector<Sequence> sequences;
	const Sequence * currentlyDisplayed;
public:
	GraphWindow (std::vector<Sequence> & vec) : sequences(vec){};
	void displaySequence (const Sequence * s) {};
};