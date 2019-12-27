#include "Credit.h"

VIP::VIP()
{
	sur = "";
	numb = 0;
	sum = 0;
	add_sum = 0;
	cred_sum = 0;
}

VIP::VIP(string sur, double numb, double sum, double add_sum, double cred_sum)
{
	this->sur = sur;
	this->numb = numb;
	this->sum = sum;
	this->cred_sum = cred_sum;
}

void VIP::input(istream& in)
{
	in >> sur >> numb >> sum >> add_sum;
}

void VIP::output(ostream& out)
{
	out << sur << " " << numb << " " << sum << " " << add_sum << " " << cred_sum << endl;
}

void VIP::print(ostream& out)
{
	out << sur << " " << numb << " " << cred_sum + add_sum + sum << endl;
}

double VIP::getCredsum() const
{
	return cred_sum;
}

void VIP::setCredit(double cr)
{
	cred_sum = cr;
}
