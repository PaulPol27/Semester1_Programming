#include "Mobile.h"

Mobile::Mobile()
{
	numb = 0;
	month = "";
	sum = 0;
}

Mobile::Mobile(double numb, string month, double sum)
{
	this->numb = numb;
	this->month = month;
	this->sum = sum;
}

void Mobile::input(istream& in)
{
	in >> numb >> month >> sum;
}

void Mobile::output(ostream& out)
{
	out << numb << " " << month << " " << sum << endl;
}

double Mobile::getNumb() const
{
	return numb;
}

string Mobile::getMonth() const
{
	return month;
}

double Mobile::getSum() const
{
	return sum;
}

void Mobile::setNumb(double n)
{
	numb = n;
}

void Mobile::setMonth(string m)
{
	month = m;
}

void Mobile::setSum(double s)
{
	sum = s;
}

