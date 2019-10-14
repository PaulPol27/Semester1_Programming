#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void number74() {
	//dano masuv rozmiru N. Obnylutu elementu masuva, yaki znachodyatsya miz minimalnum i maxumalnum elementamu, ne vklyuchayuchu max i min;
	int n;
	cin >> n;
	int* a = new int[n];
	int pmax = 0;
	int pmin = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			pmax = i;
		}
		if (a[i] < min) {
			min = a[i];
			pmin = i;
		}
	}
	if (pmax > pmin) {
		for (int i = pmin + 1; i < pmax; i++) {
			a[i] = 0;
		}
	}
	else {
		for (int i = pmax + 1; i < pmin; i++) {
			a[i] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void number75() {
	//Dano masuv A rozmiru N. Perestavutu v obernenomy poryadku elementu masuva, yaki znachodyatsya miz minimalnum i maxumalnum elementamu, vklyuchayuchu max i min;
	int n;
	cin >> n;
	int* a = new int[n];
	int pmax = 0;
	int pmin = 0;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
			pmax = i;
		}
		if (a[i] < min) {
			min = a[i];
			pmin = i;
		}
	}
	int l = abs(pmax - pmin) + 1;
	cout << l << endl;
	int temp;
	if (pmax > pmin) {
		for (int i = pmin, j = 0; i < l / 2 + pmin; i++, j++) {
			temp = a[i];
			a[i] = a[pmax - j];
			a[pmax - j] = temp;
		}
	}
	else {
		for (int i = pmax, j = 0; i < l / 2 + pmax; i++, j++) {
			temp = a[i];
			a[i] = a[pmin - j];
			a[pmin - j] = temp;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
}

void number39() {
	//Dano matrix, znaytu kilkist stovbziv, vsi elementu yakuch rizni;
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
	int k = 0;
	bool t;
	for (int j = 0; j < n; j++) {
		t = true;
		for (int i = 0; i < m - 1 && t == true; i++) {
			for (int l = i + 1; l < m; l++) {
				if (a[i][j] == a[l][j]) {
					t = false;
					break;
				}

			}
		}
		if (t == true) {
			k++;
		}
	}
	cout << k << " ";
}

void numb88() {
	//Obnylutu elementu matrix, yaki lezat' nushze pobichnoyi diagonali.
	int n;
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void number89() {
	//Obnylutu elementu matrix, yaki lezat' vushze pobichnoyi diagonali.
	int n;
	cin >> n;
	int** a = new int* [n];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			a[i][j] = 0;
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

void numb_dodutok() {
	//Dobutok dvoch matrix;
	int n, m, k;
	cin >> m >> n >> k;
	int** a, ** b, ** c;
	a = new int* [m];
	b = new int* [n];
	c = new int* [m];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
		c[i] = new int[k];
	}
	for (int i = 0; i < n; i++) {
		b[i] = new int[k];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			cin >> b[i][j];
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			c[i][j] = 0;
			for (int l = 0; l < n; l++) {
				c[i][j] += a[i][l] * b[l][j];
			}
		}
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < k; j++) {
			cout << c[i][j] << " ";
		}
		cout << endl;
	}
}

void numb_vudalutu() {
	// Min ser arufmetuchne ryadka vudalutu;
	int m, n;
	cin >> m >> n;
	int** a = new int* [m];
	for (int i = 0; i < n; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	double ar, min = 0;
	int pmin = 0;
	for (int j = 0; j < n; j++) {
		min += a[0][j];
	}
	min /= n;
	ar = 0;
	for (int i = 1; i < m; i++) {
		for (int j = 0; j < n; j++) {
			ar += a[i][j];
		}
		ar /= n;
		if (ar < min) {
			min = ar;
			pmin = i;
		}
	}
	for (int j = 0; j < n; j++) {
		for (int i = pmin; i < m - 1; i++) {
			a[i][j] = a[i + 1][j];
		}
	}
	m--;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cout << a[i][j] << " ";
		}
		cout << endl;
	}
}

int main() {
	//number74();
	//number75();
	//number39();
	//numb88();
	//number89();
	//numb_dodutok();
	numb_vudalutu();
	system("pause");
	return 0;
}