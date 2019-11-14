#include <iostream>
#include <cmath>
#include <string>
using namespace std;
// numb2(1)
//void input1(double* a, int n) {
//	for (int i = 0; i < n; i++) {
//		cin >> a[i];
//	}
//}
//
//double min(double* a, int n) {
//	int minim = INT_MAX;
//	for (int i = 0; i < n; i++) {
//		if (a[i] < minim) {
//			minim = a[i];
//		}
//	}
//	return minim;
//}
//
//double max(double* a, int n) {
//	int maxim = INT_MIN;
//	for (int i = 0; i < n; i++) {
//		if (a[i] > maxim) {
//			maxim = a[i];
//		}
//	}
//	return maxim;
//}
//
//int main() {
//	int n;
//	cin >> n;
//	double* a, * b, * c, t, min1, min2, max1, max2;
//	a = new double[n];
//	b = new double[n];
//	c = new double[n];
//	input(a, n);
//	input(b, n);
//	input(c, n);
//	if (min(a, n) < max(b, n)) {
//		t = (min(b, n) / max(a, n)) + (max(c, n) / (min(b, n) + min(c, n)));
//	}
//	else {
//		max(b, n) + max(c, n) + min(c, n);
//	}
//	cout << "t = " << t << endl;
//	system("pause");
//	return 0;
//}


////numb3(1)
//
//
//int m;// if there is rectangle matrix then int m, n;
//
//void input2(double* a[], int m) {
//	for (int i = 0; i < m; i++) {
//		for (int j = 0; j < m; j++) {
//			cin >> a[i][j];
//		}
//	}
//}
//
//double slid(double* a[], int m) {
//	int sum1 = 0;
//	for (int i = 0; i < m; i++) {
//		sum1 += a[i][i];
//	}
//	sum1 -= a[m / 2][m / 2];
//	int sum2 = 0;
//	for (int j = m - 1; j > 0; j--) {
//		sum2 += a[m - 1 - j][j];
//	}
//	int z = sum1 + sum2;
//	return z;
//}
//
//int main() {
//	int m;
//	cin >> m;
//	double** a = new double* [m];
//	double** b = new double* [m];
//	for (int i = 0; i < m; i++) {
//		a[i] = new double[m];
//	}
//	for (int i = 0; i < m; i++) {
//		b[i] = new double[m];
//	}
//	input(a, m);
//	input(b, m);
//	if (slid(a, m) > slid(b, m)) {
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < m; j++) {
//				cout << b[i][j] << " ";
//			}
//		}
//	}
//	if (slid(a, m) < slid(b, m)) {
//		for (int i = 0; i < m; i++) {
//			for (int j = 0; j < m; j++) {
//				cout << a[i][j] << " ";
//			}
//		}
//	}
//	system("pause");
//	return 0;
//}

// numb1(2)

void input(double* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

double aruf(double* a, int n) {
	int sum = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			k++;
			sum += a[i];
		}
	}
	if (k != 0) {
		sum /= k;
		return sum;
	}
	else
	return 0;
}

void output(double* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}


double* pr(double* a, double* b, double* c, int n) {
	double a1 = aruf(a, n), b1 = aruf(b, n), c1 = aruf(c, n);
	if (a1 < b1 && b1 < c1) {
		return c;
	}
	if (a1 < b1 && c1 < b1) {
		return b;
	}
	if (b1 < a1 && c1 < a1) {
		return a;
	}
}
int main() {
	int n;
	cin >> n;
	double* a, * b, * c;
	a = new double[n];
	b = new double[n];
	c = new double[n];
	input(a, n);
	input(b, n);
	input(c, n);
	output(pr(a, b, c, n), n);
	system("pause");
	return 0;
}







