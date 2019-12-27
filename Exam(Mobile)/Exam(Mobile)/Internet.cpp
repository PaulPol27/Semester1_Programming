#include "Mobile.h"

Internet::Internet()
{
	numb = 0;
	month = "";
	sum = 0;
	t = 0;
	k = 0;
}

Internet::Internet(double numb, string month, double sum, double t, double k)
{
	this->numb = numb;
	this->month = month;
	this->sum = sum;
	this->t = t;
	this->k = k;
}

void Internet::input(istream& in)
{
	in >> numb >> month >> sum >> t >> k;
}

void Internet::output(ostream& out)
{
	out << numb << " " << month << " " << sum << " " << t << " " << k << endl;
}

double Internet::getGb() const
{
	return k;
}
