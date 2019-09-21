#include <iostream>
#include <string> 
#include <cmath>
using namespace std;


void num2() {
	int k;
	double x;
	cin >> k;
	cin >> x;
	for (int i = 1; i <= k; i++) {
		x = i * x + 1.0 / i;
		cout << "k = " << i << " x = " << x << endl;
	}
}

void num4() {
	int n;
	int maxp, minp;
	double x, max, min;
	cin >> n;
	cin >> x;
	max = min = x;
	maxp = minp = 1;
	for (int i = 2; i <= n; i++) {
		cin >> x;
		if (x > max) {
			max = x;
			maxp = i;
		}
		if (x < min) {
			min = x;
			minp = i;
		}
	}
	cout << "max - min = " << max - min << endl;
	cout << "dist = " << abs(maxp - minp) << endl;
}

void num5() {
	int x, min;
	cin >> x;
	min = x;
	if (x == 0) {
		cout << "Error ";
	}
	else {
		min = x;
		do {
			cin >> x;
			if (x != 0 && x < min) {
				min = x;
			}
		} while (x != 0);
	}
	if (min != 0) {
		cout << " Min = " << min << endl;
	}
}

void num11() {
	int n, sum, k = 0;
	cin >> n;
	if (1 <= n && n <= 27) {
		for (int i = 1; i <= 9; i++) {
			for (int j = 0; j <= 9; j++) {
				for (int l = 0; l <= 9; l++) {
					if (i + j + l == n) {
						k++;
						cout << i << j << l << endl;
					}
				}
			}
		}
	}
	cout << " K = " << k << endl;
}

void num19() {
	int k = 0;
	int x;
	bool y;
	cin >> x;
	if (x > 0) {
		y = true;
	}
	if (x < 0) {
		y = false;
	}

	while (x != 0) {
		if (x > 0 && y == false) {
			y = true;
			k++;
		}
		if (x < 0 && y == true) {
			y = false;
			k++;
		}
		cin >> x;
	}
	cout << "K = " << k << endl;
}

void num8() {
	double x, sum = 0, d = 1;
	int k = 0;
	double eps;
	cin >> x >> eps;
	while (d >= eps) {
		sum += d;
		d *= x / (k + 1);
		k++;
	}
	cout << "Sum = " << sum << " e^x =  " << exp(x) << endl;
}

void num8b() {
	double x, sum = 0, d = 1;
	int k = 0;
	double eps;
	cin >> x >> eps;
	while (fabs(d) >= eps) {
		sum += d;
		d *= -(x * x / ((2 * k + 1) * (2 * k + 2)));
		k++;
	}
	cout << "Sum = " << sum << " cos(x)= " << cos(x) << endl;
}

void num6() {
	double x, sum = 0;
	int n;
	cin >> n;
	cin >> x;
	for (int i = 1; i <= n; i++) {
		sum += cos(x);
		x *= x;
	}
	cout << " Sum = " << sum << endl;
}

void num6a() {
	double y = 0;
	for (int i = 99; i >= 3; i -= 3) {
		y = sqrt(i + y);
	}
	cout << "y = " << y << endl;
}

int main() {
	num2();
	//num4();
	//num5();
	//num11();
	//num19();
	//num8();
	//num8b();
	//num6();
	//num6a();
	system("pause");
	return 0;
}