#pragma once
// 12:33
#include <iostream>
#include <fstream>
using namespace std;

class Credit {
protected:
	string sur;
	double numb;
	double sum;
public:
	Credit();
	Credit(string sur, double numb, double sum);
	virtual void input(istream& in);
	virtual void output(ostream& out);
	string getSur()const;
	double getNumb()const;
	double getSum()const;
	void setSur(string s);
	void setNumb(double n);
	void setSum(double su);

};

class Gold : public Credit {
protected:
	double add_sum;
public:
	Gold();
	Gold(string sur, double numb, double sum, double add_sum);
	void input(istream& in);
	void output(ostream& out);
	double getAddsum()const;
};

class VIP : public Gold {
private:
	double cred_sum;
public:
	VIP();
	VIP(string sur, double numb, double sum, double add_sum, double cred_sum);
	void input(istream& in);
	void output(ostream& out);
	void print(ostream& out);
	double getCredsum()const;
	void setCredit(double cr);
};
