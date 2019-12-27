#pragma once
#include <iostream>
#include<fstream>
using namespace std;

class Mobile {
protected:
	double numb;
	string month;
	double sum;
public:
	Mobile();
	Mobile(double numb, string month, double sum);
	virtual void input(istream& in);
	virtual void output(ostream& out);
	double getNumb()const;
	string getMonth()const;
	double getSum()const;
	void setNumb(double n);
	void setMonth(string m);
	void setSum(double s);
};


class Add_time : public Mobile {
protected:
	double t;
public:
	Add_time();
	Add_time(double numb, string month, double sum, double t);
	virtual void input(istream& in);
	virtual void output(ostream& out);
	double getTime()const;
};

class Internet : public Add_time {
protected:
	double k;
public:
	Internet();
	Internet(double numb, string month, double sum, double t, double k);
	virtual void input(istream& in);
	virtual void output(ostream& out);
	double getGb()const;
};