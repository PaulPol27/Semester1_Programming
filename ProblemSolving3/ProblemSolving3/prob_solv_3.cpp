#include <iostream>
#include <cmath>
using namespace std;

void numb8_b() {
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

void numb_matrix1() {
	const int size = 100;
	int n;
	cin >> n;
	int a[size];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void numb_2() {
	const int size = 100;
	int n;
	int a[size];
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			for (int j = n; j > i; j--) {
				a[j] = a[j - 1];
			}
			n++;
			a[i + 1] = a[i] * a[i];
		}
	}
	for (int i = 0; i < n ; i++) {
		cout << a[i] << endl;
	}
}
void numb_25() {
	const int n = 4;
	int m[n][n];
	int max, min, k, p;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	max = min = m[0][0];
	p = k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (m[i][j] > max) {
				max = m[i][j];
				p = j;
			}
			if (m[i][j] < min) {
				min = m[i][j];
				k = i;
			}
		}
	}
	int dob = 0;
	for (int i = 0; i < n; i++) {
		dob += m[k][i] * m[p][i];
	}
	cout << dob << endl;

}

void numb_18() {
	const int n = 4;
	int m[n][n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		sum += m[0][i] + m[n - 1][i];
	}
	for (int i = 1; i < n - 1; i++) {
		sum += m[i][0] + m[i][n - 1];
	}
	cout << sum << endl;
}

void numb_transponuvatu() {
	const int n = 4;
	int m[n][n];
	int temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			temp = m[i][j];
			m[i][j] = m[j][i];
			m[j][i] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << " ";
		}
		cout << endl;
	}
}

void num_14() {
	const int n = 4;
	int m[n][n];
	int x[n], y[n];
	int dob = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> m[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
	for (int i = 0; i < n; i++) {
		y[i] = 0;
		for (int j = 0; j < n; j++) {
			y[i] += m[i][j] * x[j];
		} 
	}
	for (int i = 0; i < n; i++) {
		cout << y[i] << " ";
	}
}

int main() {
	//numb8_b();
	//numb_10();
	//numb_matrix1();
	//numb_2();
	//numb_25();
	//numb_18();
	//numb_transponuvatu();
	num_14();
	system("pause");
	return 0;
}