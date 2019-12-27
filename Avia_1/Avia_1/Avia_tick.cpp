#include "Avia_tick.h"
#include <iostream>
#include <fstream>

Tickets::Tickets()
{
	name = "";
	dest = "";
	p = 0;
}

Tickets::Tickets(string name, string dest, double p)
{
	this->name = name;
	this->dest = dest;
	this->p = p;
}

string Tickets::getName() const
{
	return name;
}

string Tickets::getDest() const
{
	return dest;
}

double Tickets::getPrice() const
{
	return p;
}

void Tickets::setPrice(int new_price)
{
	p = new_price;
}

void Tickets::input(istream& in)
{
	in >> name >> dest >> p;
}

void Tickets::output()
{
	cout << name << " " << dest << " " << p << " " << endl;
}
