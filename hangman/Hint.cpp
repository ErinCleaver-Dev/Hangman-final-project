#include "Hint.h"
#include <iostream>
#include <string>

using namespace std;

// A switch sttement for giving hints
string Hint::giveHint(int& iHint) {
	string sHint = "";
	switch (iHint)
	{
	case 0:
		sHint = "A place for a break.";
		break;
	case 1:
		sHint =  "A very common red fruit.";
		break;
	case 2:
		sHint = "Right on the mark.";
		break;
	case 3:
		sHint = "Double ________";
		break;
	case 4:
		sHint = "Highly improbable.";
		break;
	case 5:
		sHint = "Pull the ____";
		break;
	case 6:
		sHint = "They live in a colony.";
		break;
	case 7:
		sHint = "Put the peices together.";
		break;
	case 8:
		sHint = "A sweet and delicious fruit.";
		break;
	case 9:
		sHint = "A fruit known for its small sweet and sour taste.";
		break;
	case 10:
		sHint = "The Darkside has them.";
		break;
	case 11:
		sHint = "A tropical fruit of sweetness.";
		break;
	default:
		sHint = "Boo";
		break;
	}
	return sHint;
	
}