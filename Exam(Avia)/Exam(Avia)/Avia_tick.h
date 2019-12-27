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
	virtual void output(ostream& out);
	void print_all();
	string getName()const;
	string getDest()const;
	double getPrice()const;
	void setPrice(int new_price);
};

class Luggage: public Tickets {
protected:
	double m;
public:
	Luggage();
	Luggage(string name, string dest, double p, double m);
	void input(istream& in);
	void output(ostream& out);
	double getM()const;
};

class Bussiness : public Luggage {
public:
	Bussiness();
	Bussiness(string name, string dest, double p, double m);
	void input(istream& in);
	void output(ostream& out);
};