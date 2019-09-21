#include <iostream>
#include <string> 
#include <cmath>
using namespace std;

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

int main() {
	nomer1();
	//nomer2();
	//nomer3();
	//nomer4();
	//nomer5();
	//triangle();
	system("pause");
	return 0;
}