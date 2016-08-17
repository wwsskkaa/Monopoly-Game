#include "square.h"
#include <string>
using namespace std;
//class Board;

Square::Square(string name,bool own):name(name),ownableornot(own){}
Square::~Square(){}
/*void Square::setBoard(Board* b)
{
	gb=b;
}*/
string Square::getName()
{
	return name;
}
void Square::setName(const string n)
{
	name=n;
}
void Square::setOwnable(const int o)
{
	ownableornot=o;
}
bool Square::getOwnable()
{
	return ownableornot;
}

