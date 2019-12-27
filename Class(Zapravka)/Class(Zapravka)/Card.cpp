#include "AZS.h"


Card::Card()
{
	name = "";
	price = 0;
	quant = 0;
	numb = 0;
}

Card::Card(string name, double price, double quant, double numb)
{
	this->name = name;
	this->price = price;
	this->quant = quant;
	this->numb = numb;
}

void Card::input(istream& in)
{
	in >> name >> price >> quant >> numb;
}

void Card::output(ostream& out)
{
	out << name << " " << price << " " << quant << " " << numb << endl;
}

double Card::getNumb() const
{
	return numb;
}
