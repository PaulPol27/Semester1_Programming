#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void numb_kr_1() {
	//protabulyuvatu funkziyu zadano formuloyu: duv v besidi; eps>0;  x º[a, b], h;
	//
	double a, b, h, eps, d;
	int k;
	double s = 0;
	cin >> a >> b >> h >> eps;
	for (double x = a; x <= b + h / 2; x += h) {
		d = x * x * x / (6 * 27);
		k = 1;
		while (fabs(d) >= eps) {
			s += d;
			d *= -x * x / ((2 * k + 2) * (2 * k + 3) * 9);
		}
		cout << x << " \t " << s << endl;
	}
}

void numb_1() {
	double a, b, h, eps, d;
	int k;
	double s = 0;
	cin >> a >> b >> h >> eps;
	for (double x = a; x <= b + h / 2; x += h) {
		d = x * x * x / (6 * 27);
		k = 0;
		while (fabs(d) >= eps) {
			s += d;
			d *= -x * x / ((2 * k + 2) * (2 * k + 3) * 9);
		}
		cout << x << " \t " << s << endl;
	}
}

int main() {
	//numb_1();
	//numb_2();
	numb_kr_1();
	system("pause");
	return 0;
}