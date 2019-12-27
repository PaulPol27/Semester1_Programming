#pragma once
#include <iostream>
#include <fstream>
#include <string>
#include <cmath>
using namespace std;

//Abstractnuy class

class Figure {
protected:
	string colour;
public:
	virtual ~Figure(){}
	virtual void input(istream& in) = 0;
	virtual void output(ostream& out) = 0;
	virtual double square() = 0;
	virtual double perim() = 0;
	string getColour() {
		return colour;
	}
};

class Point {
private:
	double x;
	double y;
public:
	Point():x(0), y(0){}
	friend istream& operator>>(istream& in, Point& a) {
		in >> a.x >> a.y;
		return in;
	}
	friend ostream& operator<<(ostream& out, Point& a) {
		out << a.x << " " << a.y << endl;
		return out;
	}
	double dist(Point& b) {
		return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
	}
};

class Circle :public Figure {
private:
	Point c;
	double radius;
public:
	Circle(): radius(0){}
	void input(istream& in) {
		in >> colour >> c >> radius;
	}
	void output(ostream& out) {
		out << colour << " " << c << " " << radius << endl;
	}
	double square() {
		return 3.14 * radius * radius;
	}
	double perim() {
		return 2 * 3.14 * radius;
	}
};

class Poligon : public Figure {
private:
	Point* a;
	size_t size;
public:
	Poligon():a(NULL), size(0){}
	Poligon(size_t s): a(new Point [s]), size(s){}
	Poligon(const Poligon& b) {
		colour = b.colour;
		size = b.size;
		a = new Point[b.size];
		for (int i = 0; i < size; i++) {
			a[i] = b.a[i];
		}
	}
	~Poligon() {
		delete[]a;
	}
	Poligon& operator=(const Poligon& b) {
		if (this != &b) {
			delete[]a;
			colour = b.colour;
			size = b.size;
			a = new Point[b.size];
			for (int i = 0; i < size; i++) {
				a[i] = b.a[i];
			}
		}
		return*this;
	}
	void input(istream& in) {
		in >> colour;
		in >> size;
		a = new Point[size];
		for (int i = 0; i < size; i++) {
			in >> a[i];
		}
	}
	void output(ostream& out) {
		out << colour;
		for (int i = 0; i < size; i++) {
			out << a[i] <<" ";
		}
		out << endl;
	}
	double square() {
		double k, l, m, pm;
		double s = 0;
		for (int i = 1; i < size - 1; i++) {
			k = a[0].dist(a[i]);
			l = a[i].dist(a[i + 1]);
			m = a[i + 1].dist(a[0]);
			pm = (k + l + m) / 2;
			s += sqrt(pm * (pm - k) * (pm - l) * (pm - m));
		}
		return s;
	}
	double perim() {
		double p = 0;
		for (int i = 0; i < size - 1; i++) {
			p += a[i].dist(a[i + 1]);
		}
		p += a[0].dist(a[size - 1]);
		return p;
	}
};


void sort(Figure** mass, size_t n) {
	Figure* temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (mass[j]->square() > mass[j + 1]->square()) {
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
		}
	}
}

int search(Figure** a, size_t n, string myColour) {
	double max = 0;
	int pos = -1;
	for (int i = 0; i < n; i++) {
		if (a[i]->perim() > max && a[i]->getColour() == myColour) {
			max = a[i]->perim();
			pos = i;
		}
	}
	return pos;
}

//int main() {
//	int n;
//	ifstream in("input.txt");
//	in >> n;
//	Figure** a = new Figure * [n];
//	size_t type;
//	for (size_t i = 0; i < n; i++) {
//		in >> type;
//		switch (type) {
//		case 0:a[i] = new Circle;
//			break;
//		case 1:a[i] = new Poligon;
//		}
//		a[i]->input(in);
//	}
//	sort(a, n);
//	for (size_t i = 0; i < n; i++) {
//		a[i]->output(cout);
//		cout << a[i]->square() << endl;
//	}
//	string myColour;
//	in >> myColour;
//	int i = search(a, n, myColour);
//	if (i != -1) {
//		a[i]->output(cout);
//	}
//	else {
//		cout << "No figure" << endl;
//	}
//	for (size_t i = 0; i < n; i++) {
//		delete a[i];
//	}
//	delete[]a;
//	in.close();
//	system("pause");
//	return 0;
//
//}



