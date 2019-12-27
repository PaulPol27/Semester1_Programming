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

void Tickets::output(ostream& out)
{
	out << name << " " << dest << " " << p << " " << endl;
}

void Tickets::print_all()
{
	cout << name << " " << dest << " " << p << " " << endl;
}


Luggage::Luggage()
{
	name = "";
	dest = "";
	p = 0;
	m = 0;
}

Luggage::Luggage(string name, string dest, double p, double m)
{
	this->name = name;
	this->dest = dest;
	this->p = p;
	this->m = m;
}

void Luggage::input(istream& in)
{
	in >> name >> dest >> p >> m;
}

void Luggage::output(ostream& out)
{
	out << name << " " << dest << " " << p << " " << m << " " << endl;
}

double Luggage::getM() const
{
	return m;
}

Bussiness::Bussiness()
{
	name = "";
	dest = "";
	p = 0;
	m = 0;
}

Bussiness::Bussiness(string name, string dest, double p, double m)
{
	this->name = name;
	this->dest = dest;
	this->p = p;
	this->m = m;
}

void Bussiness::input(istream& in)
{
	in >> name >> dest >> p >> m;
}

void Bussiness::output(ostream& out)
{
	out << name << " " << dest << " " << p << " " << m << " " << endl;
}
