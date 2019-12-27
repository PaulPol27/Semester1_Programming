#pragma once
#include <iostream>
#include <string>

using namespace std;

class Workers {
private:
	string name;
	string make;
	double price_det;
	double price_work;
	string sur;
	string inizial;
public:
	Workers();
	Workers(string name1, string make1, double price_det1, double price_work1, string sur1, string inizial1);
	string getName()const;
	string getMake()const;
	double getDetails()const;
	double getPricework()const;
	string getSur()const;
	string getIniz()const;
	friend istream& operator>>(istream& in, Workers& a);
	friend ostream& operator<<(ostream& out, Workers& a);
};
