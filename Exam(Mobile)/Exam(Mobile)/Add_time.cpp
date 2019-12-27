#include "Mobile.h"

Add_time::Add_time()
{
	numb = 0;
	month = "";
	sum = 0;
	t = 0;
}

Add_time::Add_time(double numb, string month, double sum, double t)
{
	this->numb = numb;
	this->month = month;
	this->sum = sum;
	this->t = t;
}

void Add_time::input(istream& in)
{
	in >> numb >> month >> sum >> t;
}

void Add_time::output(ostream& out)
{
	out << numb << " " << month << " " << sum << " " << t << endl;
}

double Add_time::getTime() const
{
	return t;
}
