#include "Auto.h"

istream& operator>>(istream& in, Workers& a)
{
	in >> a.name >> a.make >> a.price_det >> a.price_work >> a.sur >> a.inizial;
	return in;
}

ostream& operator<<(ostream& out, Workers& a)
{
	out << a.name << " " << a.make << " " << a.price_det << " " << a.price_work << " " << a.sur << " " << a.inizial << endl;
}

string Workers::getName() const
{
	return name;
}

string Workers::getMake() const
{
	return make;
}

double Workers::getDetails() const
{
	return price_det;
}

double Workers::getPricework() const
{
	return price_work;
}

string Workers::getSur() const
{
	return sur;
}

string Workers::getIniz() const
{
	return inizial;
}
