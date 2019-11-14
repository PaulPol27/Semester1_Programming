#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void numb1() {
	//Dano matrix M*N, vudalutu ryadok, suma elementiv yakogo minimalna.
	int m, n;
	cin >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int sum;
	int k;
	int min = INT_MAX;
	for (int i = 0; i < m; i++) {
		sum = 0;
		for (int j = 0; j < n; j++) {
			sum += a[i][j];
		}
		if (sum < min) {
			k = i;
			min = sum;
		}

	} 
	m--;
	cout << "k = " << k + 1 << endl;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void numb_2() {
	int m, n;
	cin >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int min = a[0][0];
	int max = a[0][0];
	int pmin = 0, pmax = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (a[i][j] < min) {
				min = a[i][j];
				pmin = i;
			}
			if (a[i][j] > max) {
				max = a[i][j];
				pmax = i;
			}
		}
	}
	cout << pmin << pmax;
	for (int i = 0; i < n; i++) {
		int el_max = a[i][pmax];
		int el_min = a[i][pmin];
		a[i][pmax] = el_max;
		a[i][pmin] = el_min;
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	numb1();
	//numb_2();
	system("pause");
	return 0;
}