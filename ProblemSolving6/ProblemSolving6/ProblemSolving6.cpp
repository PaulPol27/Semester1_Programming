#include <iostream>
#include <cmath>
using namespace std;
// function
// Dano masuv ziluch chusel, znaytu kilkist prostuch, chusel fibonachi, i  k-st chusel, suma zufer yakuch rivna (x);

bool isPrime(int x) {
	if (x < 2) {
		return false;
	}
	for (int i = 2; i <= sqrt(x); i++) { // dilnuku
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

bool isFibo(int x) {
	if (x < 0) {
		return false;
	}
	if (x == 1) {
		return true;
	}
	int f0 = 1, f1 = 1, fn;
	while ((fn = f0 + f1) < x) {
		f0 = f1; 
		f1 = fn;
	}
	return fn == x ? true : false; // tetranarnuy if
}

int SumOfNumbers(int x) {
	int k = 0;
	while (x != 0) {
		k += x % 10;
		x /= 10;
	}
	return k;
}

int count_if(int* a, int n, bool(*pf)(int)) { // (*pf) ze vkazivnuk na funcziyu z odnum parametrom (int) i povertaye (bool)
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (pf(a[i])) {
			k++;
		}
	}
	return k;
}

void remove_if(int* a, int &n, bool(*pf)(int)) {
	for (int i = 0; i < n; i++) {
		if (pf(a[i])) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			n--; 
			i--;
		}
	}
}

bool dodatnye(int x) {
	if (x < 0)
		return false;
	return true;
}



void main() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}

	remove_if(a, n, isPrime);
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}

	/*bool(*pf)(int);
	pf = isPrime;
	int k = count_if(a, n, pf);*/
	/*for (int i = 0; i < n; i++) {
		if (isPrime(a[i])) {
			k++;
		}
	}*/
	/*cout << k << endl;
	pf = isFibo;
	k = count_if(a, n, pf);*/


	/*for (int i = 0; i < n; i++) {
		if (isFibo(a[i])) {
			k++;
		}
	}*/
	/*cout << k << endl;

	k = count_if(a, n, dodatnye);*/
	/*k = 0;*/

	/*int x;
	cin >> x;
	for (int i = 0; i < n; i++) {
		if (SumOfNumbers(a[i]) == x) {
			k++;
		}
	}*/
	/*cout << k << endl;*/
	system("pause");
}



