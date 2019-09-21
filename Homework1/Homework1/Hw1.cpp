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
int main() {
	//progresia();
	//numbers();
	//square();
	//circle();
	system("pause");
	return 0;
}
