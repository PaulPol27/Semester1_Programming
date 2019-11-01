#include <iostream>
#include <cmath>
using namespace std;

	// type_result name(type1 param1, type2 param2){ body...}
	//1) po znachennyu : void swap(int a(x), int b(y)){ int t = a; a = b; b = t;} int x = 5, y = 5; swap (x, y); cout << x << " " << y; // result is : 5 7;
	//2) cherez vkazivnuk : void swap(int* a(x), int* b(y)) { int* t = a; a = b; b = t;} int x = 5; int y = 7; swap (&x, &y); cout << x << y; // result is : 7 5;
	//3) cherez posulannya : void swap(int &a(=x), int &b(= y)){ int t = a; a = b; b = t;} int x = 5; int y = 7; swap (x, y); cout << x << y; // result is : 7 5;
	// dano n chusel, perevirutu skilku z nuch ye chuslamu Fibonachi;
bool isFibo(int x) {
	if (x <= 0) {
		return false;
	}
	if (x == 1) {
		return true;
	}
	int x1, x2, xn;
	x1 = x2 = 1;
	while ((xn = x1 + x2) < x) {
		x1 = x2;
		x2 = xn;
	}
	if (xn == x) {
		return true;
	}
	else {
		return false;
	}
}


//int main() {
//	int n, a, k = 0;
//	cin >> n;
//	for (int i = 0; i < n; i++) {
//		cin >> a;
//		if (isFibo(a)) {
//			k++;
//		}
//	}
//	cout << k << endl;
//	system("pause");
//	return 0;
}


	//dano n tochok na ploshuni, vuznachutu ploshu i perumetr. // poshatok //
	double dist(double x1, double y1, double x2, double y2) {
		return sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2));
	}
	double square(double a, double b, double c) {
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}

	int main() {
		int n;
		cin >> n;
		double* x = new double[n];
		double* y = new double[n];
		for (int i = 0; i < n; i++) {
			cin >> x[i] >> y[i];
		}
		double s = 0, p = 0, a, b, c;
		for (int i = 1; i < n - 1; i++) {
			a = dist(x[0], y[0], x[i], y[i]);
			b = dist(x[i], y[i], x[i + 1], y[i + 1]);
			c = dist(x[0], y[0], x[i + 1], y[i + 1]);
			s += square(a, b, c);
		}
		for (int i = 0; i < n - 1; i++) {
			p += dist(x[i], y[i], x[n - 1], y[n - 1]);
			cout << s << p << endl;
			delete[]x;
			delete[]y;
			return 0;
		}
	}

	//kinez//

//dano tru rizni masuvu riznoyi rozmirnosti, obshuslutu znachennya vurazu t = { min(b(i)) / max(a(i)) + max(c(i)) / min(b(i) + c(i)), yaksho min (a(... // poshatok//

void input(double* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}


double max(double* a, int n) {
	double max_el = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max_el) {
			max_el = a[i];
		}
	}
	return max_el;
}


double min(double* a, int n) {
	double min_el = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] < min_el) {
			min_el = a[i];
		}
	}
	return min_el;
}

void add(double* a, double* b, double* res, int n) {
	for (int i = 0; i < n; i++) {
		res[i] = a[i] + b[i];
	}
}

//int main() {
//	int n; 
//	cin >> n;
//	double* a, * b, * c, * r1, * r2, t;
//	a = new double[n];
//	b = new double[n];
//	c = new double[n];
//	r1 = new double[n];
//	r2 = new double[n];
//	input(a, n);
//	input(b, n);
//	input(c, n);
//	if (min(a, n) < max(b, n)) {
//		t = min(b, n) / max(a, n);
//		add(b, c, r1, n);
//		t += max(c, n) / min(r1, n);
//	}
//	else {
//		add(a, c, r2, n);
//		t = max(r1, n) + min(r2, n);
//	}
//	cout << "t = " << t << endl;
//	delete[]a;
//	delete[]b;
//	delete[]c;
//	delete[]r1;
//	delete[]r2;
//	return 0;
//}

//kinez

// dano vector, posortuvatu yogo metodom bulbashku // poshatok//

void sort(double* a, int n) {
	double temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

//kinez// jfprint sfdjndvsidsjjjdsj


// duvutusya v problem solving 5 // pochatok //
void unique(double* a, int& n) { // treba posulannya bo rozmir masuvu zmenshutsya
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i] != a[j]) {
				break;
			}
			else {
				for (int k = j; k < n - 1; k++) {
					a[k] = a[k + 1];
				}
				n--;
				j--;
			}
		}
	}
}
void print(double* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << endl;
}


//int main() {
//	int n; 
//	cin >> n;
//	double* a = new double[n];
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//	sort(a, n);
//	print(a, n);
//	unique(a, n);
//	print(a, n);
//	delete[]a;
//	return 0;
//}

// kinez//

// vkazivnuk na funcziyu

double atan_2(double x) {
	return atan(x) * atan(x);
}
double sinE(double x) {
	return sin(exp(10 * x));
}
double integral(double a, double b, int n, double (*f) (double)) {
	double s = 0, h = (b - a) / n;
	for (int i = 1; i <= n - 1; i++) {
		s += f(a + i * h);
	}
	s += (f(a) / 2 + f(b) / 2);
	s *= h;
	return s;
}

//int main() {
//	double a, b, c, d, integr, int n;
//	cin >> a >> b >> c >> d >> n;
//	double(*pf)(double);
//	pf = atan_2;
//	integr = integral(a, b, n, pf);
//	pf = sinE;
//	integr += integral(c, d, n, pf);
//	cout << integral << endl;
//	return 0;
//}

// kinez //
