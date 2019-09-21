#include <iostream>
#include <string> 
#include <cmath>
using namespace std;


void dzsin() {
	double x, n, sum = 0;
	cin >> x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += sin(x);
		x *= x;
	}
	cout << "Sum = " << sum << endl;
}

void dzsinsinx() {
	double x, sum = 0;
	int n;
	cin >> x;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		sum += sin(x);
		x = sin(x);
	}
	cout << "Sum = " << sum << endl;
}

void luckynumber() {
	int x;
	cout << "Input x: ";
	cin >> x;
	if (x < 100000 || x > 999999) {
		cout << "Wrong number :( " << endl;
	}
	else {
	string n = to_string(x);
	if (n[0] + n[1] + n[2] == n[3] + n[4] + n[5]) {
		cout << "The number " << n[0] << n[1] << n[2] << n[3] << n[4] << n[5] <<" is lucky :) " << endl;
	}
	}
}

void luckynumber2() {
	int x, sum1 = 0, sum2 = 0;
	cout << "Input 6-symbols integer number: ";
	cin >> x;
	for (int i = 0; i < 3; i++) {
		sum1 = sum1 + x % 10;
		x = x / 10;
	}
	x = x % 1000;
	for (int i = 0; i < 3; i++) {
		sum2 = sum2 + x % 10;
		x = x / 10;
	}
	if (sum1 == sum2) {
		cout << "The number is happy " << endl;
	}
	else {
		cout << "The number is not happy " << endl;
	}
}

void perfectnumber() {
	int  a, b ;
	cout << "Input a: ";
	cin >> a;
	cout << "Input b: ";
	cin >> b;
	for (int j = a; j <= b; j++) {
		int sum = 0;
		if (j > 0) {
			for (int i = 1; i < j; i++) {
				if (j % i == 0) {
					sum = sum + i;
				}
			}
			if (sum == j) {
				cout << j << " - perfect number" << endl;
			}
		}
		//sum = 0;
	}
}



int main() {
	//dzsin();
	//dzsinsinx();
	//luckynumber();
	//luckynumber2();
	perfectnumber();
	system("pause");
	return 0;
}