#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void numb_kr_1() {
	//21.10.2019.
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

void test_3() {
	int n;
	cin >> n;
	int * a = new int [n];
	int count = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		int sum = 0;
		int k = 1;
		while (sum < a[i]) {
			sum += k;
			k++;
		}
		if (sum == a[i]) {
			count++;
		}
	}
	cout << count;

}

void test_3a() {
	int n;
	cin >> n;
	int count = 0;
	for (int i = 1; i < n+1; i++) {
		int sum = 0;
		int k = 1;
		while (sum < i) {
			sum += k;
			k++;
		}
		if (sum == i) {
			count++;
		}
		cout << i << " ";
	}
	cout << endl << count << endl;

	



}

void test_2()
{
	double x, max;
	int n, k;
	cout << "Input the quantity of numbers: ";
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
	}
	max = x;
	k = 0;
	for (int i = 1; i <= n; i++) {
		cout << x << endl;
		if (x > max) {
			max = x;
		}
	}

	for (int i = 1; i <= n; i++) {
		cout << x << " " << max << endl;
		if (x == max) {
			k++;
		}
	}

	cout << "Maximal number is: " << max << endl;
	cout << "The quantity of maximal numbers are: " << k << endl;
}

void test_2a()
{
	double x, max;
	int n, k;
	cout << "Input the quantity of numbers: ";
	cin >> n;
	max = INT_MIN;
	k = 0;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x > max) {
			max = x;
			k = 0;
		}
		if (x == max)
		{
			k++;
		}
	}
	cout << "Maximal number is: " << max << endl;
	cout << "The quantity of maximal numbers are: " << k << endl;
}

void numb1() {
	//28.10.2019
}


int main() {
	//numb_1();
	//numb_2();
	//numb_kr_1();
	//test_3();
	//test_3a();
	//test_2a();
	numb1();

	system("pause");
	return 0;
}