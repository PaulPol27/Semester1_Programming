#include "Credit.h"

Gold::Gold()
{
	sur = "";
	numb = 0;
	sum = 0;
	add_sum = 0;
}

Gold::Gold(string sur, double numb, double sum, double add_sum)
{
	this->sur = sur;
	this->numb = numb;
	this->sum = sum;
}

void Gold::input(istream& in)
{
	in >> sur >> numb >> sum >> add_sum;
}

void Gold::output(ostream& out)
{
	out << sur << " " << numb << " " << sum << " " << add_sum << endl;
}

double Gold::getAddsum() const
{
	return add_sum;
}
