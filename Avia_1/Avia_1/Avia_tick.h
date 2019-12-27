#pragma once
#pragma once
#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;

class Tickets {
protected:
	string name;
	string dest;
	double p;
public:
	Tickets();
	Tickets(string name, string dest, double p);
	virtual void input(istream& in);
	virtual void output();
	string getName()const;
	string getDest()const;
	double getPrice()const;
	void setPrice(int new_price);
};
