#include <iostream>
#include <cmath>
using namespace std;
void numb_2a() {
	//(x_1*y*1 + x_3*y_3 + ...) / (x_2*y*12 + x_4*y_4 + ...), yaksho x_1, x_2, ... x_6, y_1, y_2, ... , y_6.
	const int n = 6;
	int x[n], sum1 = 0, sum2 = 0, h;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n/2 ; i+=2) {
		sum1 += x[i] * x[n / 2 + i];
	}
	for (int i = 1; i < n/2; i+=2) {
		sum2 += x[i] * x[n / 2+i];
	}
	h = sum1 / sum2;
		cout << "Sum1 = " << sum1 << " Sum2 = " << sum2 << " H = " << h << endl;
}

void numb_2b() {
	//(x_1*y*1 + x_3*y_3 + ...) / (x_2*y*12 + x_4*y_4 + ...), yaksho x_1, y_1, x_2, y_2, ... x_6, y_6.
	const int n = 6;
	int a[n];
	int sum1 = 0, sum2 = 0, h;
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	for (int i = 1; i < n; i += 4) {
		sum1 += a[i - 1] * a[i];
	}
	for (int i = 2; i < n; i += 4) {
		sum2 += a[i] * a[i + 1];
	}
	h = sum1 / sum2;
	cout << "Sum1 = " << sum1 << " Sum2 = " << sum2 << " H = " << h << endl;
}


void numb_5() {
	//Dano masuv rozmiru N, nadrukuvatu elementu indeksu yakuch ye povnumu kvadratamu.
	const int n = 100;
	int x[n];
	for (int i = 0; i < n; i++) {
		x[i] = i;
	}
	for (int i = 1; i < n; i++) {
		if (sqrt(i) - (int)sqrt(i) == 0) {
			cout << i << " ";
		}
	}
}


void numb_6() {
	// Dano masuv rozmiru N, pershui i ostanniy element zalushutu na miszi, vsi rechta zaminutu serednim arefmetuchnum trioch elementiv masuvy.
	const int n = 8;
	double a[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	/*int b[n];
	b[0] = a[0];
	b[n-1] = a[n-1];*/
	for (int i = 1; i < n - 1; i++) {
		a[i] = (a[i - 1] + a[i] + a[i + 1]) / 3;
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void numb8_b() {
	//Dano masuv ziluch chusel rozmirnosti n.Zminniy T ptusvoitu znachennya 1; yaksho v masuvi nemaye nulyovuch elementiv i pru ziomu dodatni elementu cherguyutsya z vidyemnumu;
	const int n = 8;
	int a[n];
	bool t = true;
	bool sign = true;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	if (a[0] > 0) {
		sign = true;
	}
	if (a[0] < 0) {
		sign = false;
	}
	if (a[0] == 0) {
		t = false;
	}
	else {
		for (int i = 1; i < n; i++) {
			if (a[i] == 0) {
				t = false;
				break;
			}
			if ((sign == true && a[i] > 0) || (sign == false && a[i] < 0)) {
				t = false;
				break;
			}
			if (sign == true) {
				sign = false;
			}
			else {
				sign = true;
			}
		}
	}
	cout << "T = " << t << endl;
}

void numb_10() {
	//Dano masuv rozmirnosti N. Znaytu sumu chusel, rozmishenu miz max i min chuslamu poslidovnosti;
	const int n = 10;
	int a[n], max, min, k = 0, p = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	min = max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			k = i;
		}
		if (a[i] < min) {
			min = a[i];
			p = i;
		}
	}
	if (k > p) {
		for (int i = p; i <= k; i++) {
			sum += a[i];
		}
	}
	else {
		for (int i = k; i <= p; i++) {
			sum += a[i];
		}
	}
	cout << "Sum = " << sum << endl;
}

void matrix() {
		double** a;
		int n, m, k=0;
		n = 3;
		m = 3;
		a = new double* [m];
		for (int i = 0; i < m; i++) {
			a[i] = new double[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				cin >> a[i][j];
			}
		}
		for (int i = 0; i < n ; i++) {
			for (int j = 0; j < m-1; j++) {
				if (a[i][j] < a[i][j+1]) {
					if (j != 0) {
						k++;
						cout << a[i][j] << endl;
					}
				}
				if (a[i][j] > a[i][j+1]) {
					break;
				}
			}
		}
		cout << "K = " << k << endl;

}

int main() {
	//numb_2a();
	//numb_2b();
	//numb_5();
	//numb_6();
	matrix();
	system("pause");
	return 0;
}