#include "AZS.h"

AZS::AZS() {
	name = "";
	price = 0;
	quant = 0;
}

AZS::AZS(string name, double price, double quant) {
	this->name = name;
	this->price = price;
	this->quant = quant;
}

void AZS::input(istream& in)
{
	in >> name >> price >> quant;
}

void AZS::output(ostream& out)
{
	out << name << " " << price << " " << quant << endl;
}

string AZS::getName() const
{
	return name;
}

double AZS::getPrice() const
{
	return price;
}

double AZS::getQuant() const
{
	return quant;
}

void AZS::setName(string n)
{
	name = n;
}

void AZS::setPrice(double p)
{
	price = p;
}

void AZS::setQuant(double q)
{
	quant = q;
}