#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void numb53() {
	//Dano masuv A i B rozmiru N. Stvorutu novuy masuv rozmiru N, koznuy element yakogo = maksumalnomy z elementiv masuvy A i B z tum ze indeksom.
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int* c = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> b[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] >= b[i]) {
			c[i] = a[i];
		}
		if (a[i] < b[i]) {
			c[i] = b[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << c[i] << " ";
	}
}

void numb54() {
	// Dano masuv A z ziluch chusel rozmiru N. Prtrpusatu v novuy zilochuselnuy masuv B vsi parni chusla z masuvy A i vuveztu rozmir masuva B i yogo elementu.
	int n, count = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			count++;
		}
	}
	int* b = new int[count];//novuy zilochuselnuy masuv B;
	int k = count;
	for (int i = 0; i < n; i++) {
		if (a[i] % 2 == 0) {
			b[count - k] = a[i];
			k--;
		}
	}
	for (int i = 0; i < count; i++) {
		cout << b[i] << " ";
	}
}

void numb56() {
	//dano masuv A z ziluch chusel rozmiru N(<=15). Prtrpusatu v novuy zilochuselnuy masuv B vsi elementu z poryadkovanumu nomeramu, kratnumu(3, 6, ...) i vuvestu rozmir i elemenru;
	int n, count = 0;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 3 == 0) {
			count++;
		}
	}
	int* b = new int[count];
	int k = count;
	for (int i = 0; i < n; i++) {
		if (a[i] % 3 == 0) {
			b[count - k] = a[i];
			k--;
		}
	}
	for (int i = 0; i < count; i++) {
		cout << b[i] << " ";
	}
}

void numb57() {
	// dano zilochuselnuy masuv A rozmirom N. Perepusatu v novuy masuv B vsi elementu masuvy A spochatku z parnumu indeksamu potim z neparnumu;
	int n;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int k = n;
	for (int i = 0; i < n; i += 2) {
		b[n - k] = a[i];
		k--;
	}
	for (int i = 1; i < n; i += 2) {
		b[n - k] = a[i];
		k--;
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}

void numb58() {
	// dano masuv A rozmiru N. sformuvatu novuy masuv togo z rozmiru: element B_k = sumi elementiv masuva A z nomera vid 1 do k;
	int n; 
	int sum = 0;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		sum += a[i];
		b[i] = sum;
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}

void numb59() {
	// dano masuv A rozmiru N. sformuvatu novuy masuv togo z rozmiru: element B_k = serednyomu arefmetuchnomy elementiv masuvu A vid 1 do K;
	int n;
	int sum = 0;
	cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		sum += a[i];
		b[i] = sum/ (i + 1);
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}

}

void numb60() {
	//dano masuv A rozmiru N. sformuvatu novuy masuv togo z rozmiru: element B_k = sumi elementiv masuva A z nomera vid K do N;
	int n; cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	int k = sum;
	for (int i = 0; i < n; i++) {
		b[i] = k;
		k -= a[i];
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}

void numb61() {
	// dano masuv A rozmiru N. sformuvatu novuy masuv togo z rozmiru: element B_k = serednyomu arefmetuchnomy elementiv masuvu A vid K do N;
	int n; cin >> n;
	int* a = new int[n];
	int* b = new int[n];
	int sum = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		sum += a[i];
	}
	int k = sum;
	for (int i = 0; i < n; i++) {
		b[i] = k / (n - i);
		k -= a[i];
	}
	for (int i = 0; i < n; i++) {
		cout << b[i] << " ";
	}
}

void numb62() {
	//dano masuv A rozmiru N. Stvotutu novi masuvu B i C togo z rozmiru, tak shob masuv B mistuv vsi dodatni elementu, a masuv C vidyemni. 
	int n;
	cin >> n;
	int* a = new int[n];
	int count1 = 0;
	int count2 = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			count1++;
		}
		if (a[i] < 0) {
			count2++;
		}
	}
	int* b = new int[count1];
	int k_1 = count1;
	int* c = new int[count2];
	int k_2 = count2;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			b[count1 - k_1] = a[i];
			k_1--;
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			c[count2 - k_2] = a[i];
			k_2--;
		}
	}
	for (int i = 0; i < count1; i++) {
		cout << b[i] << " ";
	}
	for (int i = 0; i < count2; i++) {
		cout << c[i] << " ";
	}
}

void numbu() {
	double** a;
	int n, m, k = 0;
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
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m - 1; j++) {
			if (a[i][j] < a[i][j + 1]) {
				if (j != 0) {
					k++;
					cout << a[i][j] << endl;
				}
			}
			if (a[i][j] > a[i][j + 1]) {
				break;
			}
		}
	}
	cout << "K = " << k << endl;
}

int main() {
	//numb53();
	 numb54();
	//numb56();
	//numb57();
	//numb58();
	//numb59();
	//numb60();
	//numb61();
	//numb62();
	//numbu();
	system("pause");
	return 0;
}