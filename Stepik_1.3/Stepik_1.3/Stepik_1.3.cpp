#include <iostream>
#include <cmath>
using namespace std;

void numb_1() {
	// ser arufmetuchne;
	int n, k = 0;
	double s = 0, x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		if (x >= 0) {
			s += x;
			k++;
		}
	}
	if (k > 0) {
		s /= k;
	}
	cout << s;
}

void numb_2() {
	// PROSTE CHUSLO;
	int x;
	bool t = true;
	cin >> x;
	if (x <= 1) {
		t = false;
	}
	else {
		for (int i = 2; i <= sqrt(x); i++) {
			if (x % i == 0) {
				t = false;
				break;
			}
		}
	}
	if (t) {
		cout << "Number is prime! " << endl;
	}
	else {
		cout << "Number is NOT prime! " << endl;
	}
}

void numb_3() {
	// sumetruchne;
	int x, y = 0, temp;
	cin >> x;
	temp = x; 
	y += temp % 10;
	temp /= 10;
	while (temp > 0) {
		y += y * 10 + temp % 10;
		temp /= 10;
	}
	if (x == y) {
		cout << " Polindrom";
	}
	else {
		cout << "Ne polindrom";
	}
}

int main() {
	//numb_1();
	//numb_2();
	numb_3();
	system("pause");
	return 0;
}

