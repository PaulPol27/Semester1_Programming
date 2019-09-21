#include <iostream>
#include <string> 
#include <cmath>
using namespace std;


void progresia() {
	int a_1, a_2, n;
	cout << "Input a_1, a_2:";
	cin >> a_1 >> a_2;
	if (a_1 < a_2) {
		cout << "Input n:";
		cin >> n;
	}
	else {
		cout << "Input n:";
		cin >> n;
	}
	int d = a_2 - a_1;
	int a_n = a_1 + (n - 1) * d;
	int S_n = n * (a_1 + a_n) / 2;
	cout << "a_n = " << a_n << " S_n = " << S_n << endl;
}

void numbers() {

	int number;
	cout << "Input number: ";
	cin >> number;
	while (number < 100 || number > 999) {
		cout << "Input number: ";
		cin >> number;
	}
	string n = to_string(number);
	cout << "Reverse: " << n[2] << n[1] << n[0] << endl;
	//system("pause");

}

void square() {
	double x, y;
	const int R = 1;
	cout << "Input x, y: ";
	cin >> x >> y;
	if (x > -1 && x < 1 && y < 1 && y > -1) {
		if (x * x + y * y >= R * R) {
			cout << "Dot (" << x << ", " << y << ") exists" << endl;
		}
		else {

			cout << "Dot (" << x << ", " << y << ") does not exists" << endl;
		}
	}
	else {
		cout << "Dot (x; y) does not exist" << endl;
	}

}

void circle() {
	double x, y;
	const int R = 1;
	while (true) {
		cout << "Input x, y: ";
		cin >> x >> y;
		if (x >= 0 && x <= 1 && y >= 0 && y <= 1) {
			if (x * x + y * y <= R * R) {
				cout << "Dot (" << x << ", " << y << ") exists";
			}
			else {
				cout << "Dot (" << x << ", " << y << ") does not exists ";
			}
		}
		else {
			cout << " Dot (" << x << ", " << y << ") does not exists ";
		}
		cout << endl;
	}
}

void nomer1() {
	double x, y;
	cout << "Input x: ";
	cin >> x;
	if (x > 0) {
		y = 2 * sin(x);
		cout << "y = " << y << endl;
	}
	if (x <= 0) {
		y = 6 - x;
		cout << "y = " << y << endl;
	}
}

void nomer2() {
	int x, y;
	cout << "Input x: ";
	cin >> x;
	if (x < -2 || x > 2) {
		y = 2 * x;
		cout << " y = " << y << endl;
	}
	if (x >= -2 && x <= 2) {
		y = (-3) * x;
		cout << "y = " << y << endl;
	}
}

void nomer3() {
	double x, y;
	cout << "Input x: ";
	cin >> x;
	if (x <= 0) {
		y = (-x);
		cout << "y = " << y << endl;
	}
	if (x > 0 && x < 2) {
		y = x * x;
		cout << "y = " << y << endl;
	}
	if (x >= 2) {
		y = 4;
		cout << "y = " << y << endl;
	}
}

void nomer4() {
	double x, y;
	cout << " Input x: ";
	cin >> x;
	if (x < 0) {
		y = 0;
		cout << "y = " << y << endl;
	}
	if ((int)x % 2 == 0) {
		y = 1;
		cout << " y = " << y << endl;
	}
	if ((int)x % 2 == 1) {
		y = (-1);
		cout << " y = " << y << endl;
	}
}

void nomer5() {
	int x;
	double y;
	cout << "Input x: ";
	cin >> x;
	switch (x) {
	case 1:
		y = cos(x);
		cout << "y = " << y << endl;
		break;
	case 2:
		y = sin(x);
		cout << "y = " << y << endl;
		break;
	case 3:
		y = tan(x);
		cout << " y = " << y << endl;
		break;
	default:
		y = 100;
		cout << "wrong input (choose between 1, 2 or 3)" << endl;
	}
}

void triangle() {
	double x_1, y_1;
	double x_2, y_2;
	double x_3, y_3;
	cout << "Input (x_1, y_1), (x_2, y_2), (x_3, y_3): ";
	cin >> x_1 >> y_1 >> x_2 >> y_2 >> x_3 >> y_3;
	double A, B, C;
	A = sqrt((x_2 - x_1) * (x_2 - x_1) + (y_2 - y_1) * (y_2 - y_1));
	B = sqrt((x_3 - x_2) * (x_3 - x_2) + (y_3 - y_2) * (y_3 - y_2));
	C = sqrt((x_1 - x_3) * (x_1 - x_3) + (y_1 - y_3) * (y_1 - y_3));
	if (A + B <= C || B + C <= A || A + C <= B) {
		cout << "Triangle does not exist " << endl;
	}
	else {
		double P, S;
		P = A + B + C;
		S = sqrt(P / 2 * (P / 2 - A) * (P / 2 - B) * (P / 2 - C));
		cout << "P = " << P << " S = " << S << endl;
	}
}

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
			if(x != 0 && x < min) {
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
		y = sqrt(i + y) ;
	}
	cout << "y = " << y << endl;
}

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
	//progresia();
	//numbers();
	//square();
	//circle();
	//nomer1();
	//nomer2();
	//nomer3();
	//nomer4();
	//nomer5();
	 //triangle();
	//gg();
	//num2();
	//num4();
	//num5();
	//num11();
	//num19();
	//num8();
	//num8b();
	//num6();
	//num6a();
	//dzsin();
	//dzsinsinx();
	//luckynumber();
	//luckynumber2();
	perfectnumber();
	system("pause");
	return 0;
}