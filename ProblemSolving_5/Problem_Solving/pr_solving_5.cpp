#include <iostream>
#include <cmath>
using namespace std;

void numb1() {
	//dano matrix m * n, utvorutu vector rozmiru 3n  - 2; ( -/_)
	int m;
	cin >> m;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int* v = new int[3 * m - 2];
	int k = 0;
	for (int j = m - 1; j > 0; j--) {
		v[k] = a[m - 1][j];
		k++;
	}
	for (int i = m - 1; i > 0; i--) {
		v[k] = a[i][m - 1 - i]; //for(int j = 0; j < n; j++){ v[k] = a[m - 1 - j][j]; k++}
		k++;
	}
	for (int j = m - 1; j >= 0; j--) {
		v[k] = a[0][j];
		k++;
	}
	for (int i = 0; i < 3 * m - 2; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < m; i++) {
		delete [] a[i];
	}
	delete []a;
	delete[]v;
}

void numb2() {
	//   ( |\| )
	int m;
	cin >> m;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[m];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	int* v = new int[3 * m - 2];
	int k = 0;
	for (int i = m - 1; i > 0; i--) {
		v[k] = a[i][0];
		k++;
	}
	for (int j = 0; j < m - 1; j++) {
		v[k] = a[j][j];
		k++;
	}
	for (int i = m - 1; i >= 0; i--) {
		v[k] = a[i][m - 1];
		k++;
	}
	for (int i = 0; i < 3 * m - 2; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < m; i++) {
		delete[] a[i];
	}
	delete[]a;
	delete[]v;
}

void numb3() {
	//dano 2 vectoru riznogo rozmiru. Stvorutu 3 vector z elementiv yaki vchodyat i  v 1 i v 2 vectoru(peretun);
	int n, m;
	cin >> n >> m;
	double* a1 = new double[n];
	double* a2 = new double[m];
	double* a3;
	if (n > m) {
		a3 = new double[m];
	}
	else {
		a3 = new double[n];
	}
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
	}
	for (int i = 0; i < m; i++) {
		cin >> a2[i];
	}
	int k = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a1[i] == a2[j]) {
				a3[k] = a1[i];
				k++;
				break;
			}
		}
	}
	for (int i = 0; i < k; i++) {
		cout << a3[i] << " ";
	}
	delete[]a1;
	delete[]a2;
	delete[]a3;
}

void numb4() {
	//dano 2 vectoru riznogo rozmiru. stvorutu novuy vector z elementiv yaki vchodyat' abo v 1 vector abo v 2 vector, ale ne odnochasno v 2;
	int n, m;
	cin >> n >> m;
	double* a1 = new double[n];
	double* a2 = new double[m];
	double* a3 = new double[m + n];
	for (int i = 0; i < n; i++) {
		cin >> a1[i];
	}
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
	for (int i = 0; i < k; i++) {
		cout << a3[i] << " ";
	}
	delete[]a1;
	delete[]a2;
	delete[]a3;
}

void numb5() {
	// dano vector ziluch chusel. Stvorutu vector unikalnuch elementiv(yaki ne povtoryuyutsyua)
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			if (a[i] == a[j]) {
				for (int k = j; k < n - 1; k++) {
					a[k] = a[k + 1];
				}
				n--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete[]a;
}

int main() {
	numb1();
	//numb2();
	//numb3();
	//numb4();
	//numb5();
	system("pause");
	return 0;
}