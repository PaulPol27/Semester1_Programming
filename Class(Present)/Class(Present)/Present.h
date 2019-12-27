#pragma once
#ifndef PRESENT_H
#define PRESENT_H
#endif

#include <iostream>
#include <fstream>
#include <string>

using namespace std;

class Present {
private:
	int date;
	string sur;
	string addres;
	string name;
	string type;
	int price;
public:
	Present();
	~Present();
	Present(int date1, string sur1, string addres1, string name1, string type1, int price1);
	Present(Present& a);
	void input(istream& in);
	void output(ostream& out);
	int getDate();
	string getSur();
	string getAdd();
	string getName();
	string getType();
	int getPrice();
	Present operator=(Present& a);
};
