#include <iostream>
#include <cmath>
using namespace std;

void numb1() {
	int n;
	cout << "Input the quantity of numbers in the array: ";
	cin >> n;
	int* a = new int[n];
	cout << "Input an array: ";
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = a[0];
	for (int i = 0; i < n - 1; i++) {
		a[i + 1] *= a[i];
		if (a[i+1] > max) {
			max = a[i + 1];
		}
	}
	cout << "The new array is: " << endl;
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	cout << "The maximal number is: " << max << endl;
	delete[]a;
}

void numb2() {
	int n;
	cout << "Input the number of columns and rows of a square matrix: ";
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	cout << "Input a square matrix: ";
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int* v = new int[3 * n - 2];
	int k = 0;
	for (int j = 0; j < n - 1; j++) {
		v[k] = a[n - 1][j];
		k++;
	}
	for (int j = n - 1; j > 0; j--) {
		v[k] = a[j][j];
		k++;
	}
	for (int j = 0; j < n; j++) {
		v[k] = a[0][j];
		k++;
	}
	cout << "The new vector is: ";
	for (int i = 0; i < 3 * n - 2; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < n; i++) {
		delete[]a[i];
	}
	delete[]a;
	delete[]v;
}

void numb3() {
	int n, m;
	cout << "Input the quantity of numbers in the first array: ";
	cin >> n;
	cout << "Input the quantity of numbers in the second array: ";
	cin >> m;
	double* a1 = new double[n];
	double* a2 = new double[m];
	double* a3 = new double[m + n];
	cout << "Input the first array: ";
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
	}
	cout << "Input the second array: ";
	for (int i = 0; i < m; i++) {
		cin >> a2[i];
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		bool t = true;
		for (int j = 0; j < m; j++) {
			if (a1[i] == a2[j]) {
				t = false;
				break;
			}
		}
		if (t) {
			a3[k] = a1[i];
			k++;
		}
	}
	for (int i = 0; i < m; i++) {
		bool t = true;
		for (int j = 0; j < n; j++) {
			if (a2[i] == a1[j]) {
				t = false;
				break;
			}
		}
		if (t) {
			a3[k] = a2[i];
			k++;
		}
	}
	cout << "Third vector is: ";
	for (int i = 0; i < k; i++) {
		cout << a3[i] << " ";
	}
	delete[]a1;
	delete[]a2;
	delete[]a3;
}

int main() {
	numb1();
	//numb2();
	//numb3();
	system("pause");
	return 0;
}