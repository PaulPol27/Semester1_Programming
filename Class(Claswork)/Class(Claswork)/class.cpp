#include <iostream>
#include <cmath>
#include <string>
using namespace std;

//class Point {
//private:
//	double x, y;
//public:
//	Point() { //konstruktor bez parametriv;
//		x = y = 0; //Point a;
//	}
//	Point(double x1, double y1 = 0) { // parametr za zamovchuvannyam;
//		x = x1; //this -> x = x;
//		y = y1; //this -> y = y;    (Point b(5), c(7, 9);)
//	}
//	Point(const Point& a) { //konstructor copiyuvannya;
//		x = a.x;
//		y = a.y;//Point (d(b)) abo ( e = c ); //copy;
//	}
//	~Point() {//destructor(vudalyaye pamyat)
//		cout << "destroy object" << endl;
//	}
//	void input() {
//		cin >> x >> y; //this -> x >> this -> y 
//	}
//	void output() {
//		cout << "(" << x << " , " << y << ")" << endl;
//	}
//	double distance(Point b) {
//		return sqrt(pow(x - b.x, 2) + pow(y - b.y, 2));
//	}
//	void move(double d1, double d2) {
//		x += d1;//zminulu koordunatu (x) i (y);
//		y += d2;
//	}
//	double getX() { // otumatu znachennya x
//		return x;
//	}
//	double getY() { // otrumatu znachennya y
//		return y;
//	}
//	void setX(double x1) {
//		x = x1;// vstanovlyuyemo nove znachennya x;
//	}
//	void setY(double y1) {
//		y = y1; // vstanovlyuyemo nove znachennya y;
//	}
//};
//
//// znaytu tochku, miz yakumu vidstan maxumalna;
//void input(Point* p, int n) {
//	for (int i = 0; i < n; i++) {
//		p[i].input();
//	}
//}
//
//int main() {
//	int n;
//	cin >> n;
//	Point* p = new Point[n];
//	Point p1, p2; // tochku vidstan miz yakumu maxumalna;
//	double max = 0, l;// (l) ze potochna vidstan;
//	input(p, n);
//	for (int i = 0; i < n - 1; i++) {
//		for (int j = i + 1; j < n; j++) {
//			l = p[i].distance(p[j]);
//			if (l > max) {
//				max = l;
//				p1 = p[i];
//				p2 = p[j];
//			}
//		}
//	}
//	cout << "max = " << max << endl;
//	p1.output();
//	p2.output();
//	delete[]p;
//	system("pause");
//	return 0;
//}

// stvorutu tup student z takumu polyamu(imya, facultet, serednya uspishnist)
// dano masuv studentiv( (1.) posortuvatu studentiv za prizvushem (2) vuvestu studentiv vkazanogo facultetu (3) znaytu studentiv z maksumalnoyu uspichnistu);
//(konstuctor bez parametriv, vvid vuvid, sortuvannya po imeni(get surname), vuvestu studentiv z max uspishnistyu(get success))

class Student {
private:
	string sur;
	string f;
	double suc;
public:
	Student() {
		sur = "";
		f = "";
		suc = 0;
	}
	void input() {
		cin >> sur >> f >> suc;
	}
	void output() {
		cout << sur << " " << f << " " << suc << " " << endl;
	}
	string getSur() {
		return sur;
	}
	string getF() {
		return f;
	}
	double getSuc() {
		return suc;
	}
};

void sort1(Student* a, int n) {
	Student temp;
	cout << "Surname sort: ";
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j].getSur() > a[j + 1].getSur()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	cout << endl;
}

void sort2(Student* a, int n) {
	Student temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j].getF() > a[j + 1].getF()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}
void maxmark(Student* a, int n) {
	Student temp;
	cout << "The maximal mark has a student: ";
	int max = INT_MIN;
	for (int i = 0; i < n; i++) {
		if (a[i].getSuc() > max) {
			max = a[i].getSuc();
		}
	}
	cout << endl;
}

int main() {
	int n;
	cin >> n;
	Student* s = new Student[n];
	for (int i = 0; i < n; i++) {
		s[i].input();
	}
	sort1(s, n);
	for (int i = 0; i < n; i++) {
		s[i].output();
	}
	sort2(s, n);
	for (int i = 0; i < n; i++) {
		s[i].output();
	}
	maxmark(s, n);
	for (int i = 0; i < n; i++) {
		s[i].output();
	}
	system("pause");
	return 0;
}
