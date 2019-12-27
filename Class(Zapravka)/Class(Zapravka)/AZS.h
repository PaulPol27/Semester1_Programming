#pragma once
#include <iostream>
#include <fstream>
using namespace std;

class AZS {
protected:
	string name;
	double price;
	double quant;
public:
	AZS();
	AZS(string name, double price, double quant);
	virtual void input(istream& in);
	virtual void output(ostream& out);
	string getName()const;
	double getPrice()const;
	double getQuant()const;
	void setName(string n);
	void setPrice(double p);
	void setQuant(double q);
};

class Card : public AZS {
protected:
	double numb;
public:
	Card();
	Card(string name, double price, double quant, double numb);
	void input(istream& in);
	void output(ostream& out);
	double getNumb()const;
};