#include "Credit.h"

Credit::Credit()
{
	sur = "";
	numb = 0;
	sum = 0;
}

Credit::Credit(string sur, double numb, double sum)
{
	this->sur = sur;
	this->numb = numb;
	this->sum = sum;
}

void Credit::input(istream& in)
{
	in >> sur >> numb >> sum;
}

void Credit::output(ostream& out)
{
	out << sur << " " << numb << " " << sum << " " << endl;
}

string Credit::getSur() const
{
	return sur;
}

double Credit::getNumb() const
{
	return numb;
}

double Credit::getSum() const
{
	return sum;
}

void Credit::setSur(string s)
{
	sur = s;
}

void Credit::setNumb(double n)
{
	numb = n;
}

void Credit::setSum(double su)
{
	sum = su;
}
