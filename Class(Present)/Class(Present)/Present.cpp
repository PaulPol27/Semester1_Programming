#include "Present.h"
#include <iostream>
#include <fstream>


using namespace std;

Present::Present(){}

Present::~Present(){}

Present::Present(int date1, string sur1, string addres1, string name1, string type1, int price1) {
	date = date1;
	sur = sur1;
	addres = addres1;
	name = name1;
	type = type1;
	price = price1;
}

Present::Present(Present& a) {
	date = a.date;
	sur = a.sur;
	addres = a.addres;
	name = a.name;
	type = a.type;
	price = a.price;
}

void Present::input(istream& in) {
	in >> date >> sur >> addres >> name >> type >> price;
}

void Present::output(ostream& out) {
	out << date << " " << sur << " " << addres << " " << name << " " << type << " " << price << " ";
}

int Present::getDate() {
	return date;
}

string Present::getSur() {
	return sur;
}

string Present::getAdd() {
	return addres;
}

string Present::getName() {
	return name;
}

string Present::getType() {
	return type;
}

int Present::getPrice() {
	return price;
}

Present Present::operator=(Present& a) {
	if (this != &a) {
		date = a.date;
		sur = a.sur;
		addres = a.addres;
		name = a.name;
		type = a.type;
		price = a.price;
	}
	return*this;
}

void sort(Present* a, int n) {
	Present temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n-1; j++) {
			if (a[i].getSur() == a[j + 1].getSur()) {
				if (a[j].getType() > a[j + 1].getType()) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
			if (a[i].getAdd() == a[j + 1].getAdd()) {
				if (a[j].getSur() > a[j + 1].getSur()) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
			if (a[i].getDate() == a[j + 1].getDate()) {
				if (a[j].getAdd() > a[j + 1].getAdd()) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
			if (a[j].getDate() > a[j + 1].getDate()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void suma_price(Present* a, int n, ostream& out) {
	int s = 0;
	int k = 0;
	string* types = new string[n];
	double* values = new double[n];
	bool t = true;
	for (int i = 0; i < n; i++) {
		s = a[i].getPrice();
		for (int j = i + 1; j < n; j++) {
			if (a[i].getType() == a[j].getType()) {
				s += a[j].getPrice();
			}
		}
		for (int l = 0; l < k; l++) {
			if (types[l] == a[i].getType()) {
				t = false;
			}
		}
		if (t) {
			types[k] = a[i].getType();
			values[k] = s;
			k++;
		}

	}
	for (int i = 0; i < k; i++) {
		out << types[i]<< "--" << values[i] << endl;
	}
}

void max_pres(Present* a, int n, ostream& out) {
	int k = 0;
	string temp = "";
	for (int i = 0; i < n; i++) {
		temp = a[i].getName();
		for (int j = i + 1; j < n; j++) {
			if (a[i].getType() == a[j].getType()) {
				if (a[i].getName() == a[j].getName()) {
					k++;
				}
			}
		}
	}
	for (int i = 0; i < k; i++) {
		out << temp;
	}
}

void max_punkt(Present* a, int n, ostream& out) {
	string punkt = "";
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i].getAdd() == a[j].getAdd()) {
				punkt = a[i].getAdd();
			}
		}
	}
	out << punkt << endl;
}

int main() {
	const int n = 5;
	Present a[5];
	ifstream in1("order1.txt");
	a[0].input(in1);
	ifstream in2("order2.txt");
	a[1].input(in2);
	ifstream in3("order3.txt");
	a[2].input(in3);
	ifstream in4("order4.txt");
	a[3].input(in4);
	ifstream in5("order5.txt");
	a[4].input(in5);
	in1.close();
	in2.close();
	in3.close();
	in4.close();
	in5.close();
	ofstream out("result.txt");
	sort(a, n);
	for (int i = 0; i < n; i++) {
		a[i].output(out);
		out << endl;
	}
	out << endl;
	suma_price(a, n, out);
	out << endl;
	max_pres(a, n, out);
	out << endl;
	max_punkt(a, n, out);
	//system("pause");
	return 0;
}