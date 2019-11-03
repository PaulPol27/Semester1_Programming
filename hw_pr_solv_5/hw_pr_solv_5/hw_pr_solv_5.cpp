#include <iostream>
#include <cmath>
using namespace std;

void numb1a() {
	int m;
	cin >> m;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		 a[i] = new int[m];
	}
	int* v = new int[3 * m - 2];
	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int j = 0; j < m - 1; j++) {
		v[k] = a[0][j];
		k++;
	}
	for (int j = m - 1; j > 0; j--) {
		int  i = m - 1 - j;
		v[k] = a[i][j];
		k++;
	}
	for (int j = 0; j < m ; j++) {
		v[k] = a[m - 1][j];
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

void numb1b() {
	int m;
	cin >> m;
	int** a = new int* [m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[m];
	}
	int* v = new int[3 * m - 2];
	int k = 0;
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}
	for (int i = 0; i < m - 1; i++) {
		v[k] = a[i][m - 1];
		k++;
	}
	for (int i = m - 1; i > 0; i--) {
		v[k] = a[i][i];
		k++;
	}
	for (int i = 0; i < m; i++) {
		v[k] = a[i][0];
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

void numb1c() {
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
		v[k] = a[i][m - 1];
		k++;
	}
	for (int j = m - 1; j > m / 2; j--) {
		int i = m - 1 - j;
		v[k] = a[i][j];
		k++;
	}
	for (int i = m / 2; i > 0; i--) {
		v[k] = a[i][i];
		k++;
	}
	for (int i = 0; i <= m - 1; i++) {
		v[k] = a[i][0];
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

void numb1d() {
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
	for (int i = 0; i < m - 1; i++) {
		v[k] = a[i][0];
		k++;
	}
	for (int j = 0; j < m / 2; j++) {
		int i = m - 1 - j;
		v[k] = a[i][j];
		k++;
	}
	for (int j = m / 2; j < m - 1; j++) {
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
		delete[]a[i];
	}
	delete[]a;
	delete[]v;
}

void numb1e() {
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
		v[k] = a[0][j];
		k++;
	}
	for (int j = 0; j < m / 2; j++) {
		v[k] = a[j][j];
		k++;
	}
	for (int j = m / 2; j > 0; j--) {
		int i = m - j - 1;
		v[k] = a[i][j];
		k++;
	}
	for (int j = 0; j <= m - 1; j++) {
		v[k] = a[m - 1][j];
		k++;
	}
	for (int i = 0; i < 3 * m - 2; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < m; i++) {
		delete[]a[i];
	}
	delete[]a;
	delete[]v;
}

void numb2() {
	//Дано прямокутну матрицю розмірності  . Утворити вектор, кожен елемент якого дорівнює максимуму із суми цифр елементів відповідного рядка матриці.
	int m, n;
	cin >> m >> n;
	int** a = new int*[m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int* v = new int[m];
	int k = 0;
	int max = a[0][0];
	for (int i = 0; i < m; i++) {
		max = 0;
		for (int j = 0; j < n; j++) {
			int t = ((a[i][j] % 10) + (a[i][j] / 10));
			int b = (max % 10 + max / 10);
			if ( t > b) {
				max = a[i][j];
			}
		}
		v[k] = max;
		k++;
	}
	for (int i = 0; i < k; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < m; i++) {
		delete[]a[i];
	}
	delete[]a;
	delete[]v;
}

bool isPrime(int x) {
	if (x < 2)
		return false;
	for (int i = 2; i <= sqrt(x); i++) {
		if (x % i == 0) {
			return false;
		}
	}
	return true;
}

void numb3() {
	//Дано прямокутну матрицю розмірності  . Утворити вектор, кожен елемент якого дорівнює кількості простих елементів відповідного стовпця матриці.
	int m, n;
	cin >> m >> n;
	int** a = new int*[m];
	for (int i = 0; i < m; i++) {
		a[i] = new int[n];
	}
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
		}
	}
	int* v = new int[n];
	int k = 0;
	int pos = 0;
	for (int j = 0; j < n; j++) {
		k = 0;
		for (int i = 0; i < m; i++) {
			if (isPrime(a[i][j])) {
				k++;
			}		
		}
		v[j] = k;
	}
	for (int i = 0; i < n; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < m; i++) {
		delete[]a[i];
	}
	delete[]a;
	delete[]v;
}

bool palindrome(int l) {
	int n, digit, rev = 0;
	n = l;
	do
	{
		digit = l % 10;
		rev = (rev * 10) + digit;
		l = l / 10;
	} while (l != 0);
	if (n == rev)
		return true;
	else
		return false;
}

void numb4() {
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
	int* v = new int[m];
	for (int i = 0; i < m; i++) {
		int min = INT_MAX;
		for (int j = 0; j < n; j++) {
			if (palindrome(a[i][j])) {
				if(a[i][j] < min)
				min = a[i][j];
			}
		}
		v[i] = min;
	}
	for (int i = 0; i < m; i++) {
		cout << v[i] << " ";
	}
	for (int i = 0; i < m; i++) {
		delete[]a[i];
	}
	delete[]a;
	delete[]v;
}

void numb5() {
	//Дано масив цілих чисел. Вилучити з масиву елементи, які діляться на кожну зі своїх цифр.
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if (a[i] % 10 != 0) {
			int k = (a[i] % (a[i] / 10));
			int l = (a[i] % (a[i] % 10));
			if (k != 0 || l != 0) {
				for (int j = i; j < n - 1; j++) {
					a[j] = a[j + 1];
				}
				n--;
				i--;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete[]a;
}

void numb6a() {
	//Дано масив цілих чисел. Вилучити з масиву симетричні елементи. 
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {	
		if (palindrome(a[i])) {
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
	delete[]a;
}

void numb6() {
	//Дано масив цілих чисел. Вилучити з масиву симетричні елементи. 
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int digit, rev = 0;
	for (int i = 0; i < n; i++) {
		int h = a[i];
		rev = 0;
		while(h != 0){
			digit = a[i] % 10;
			rev = (rev * 10) + digit;
			h = h / 10;
		}
		if (a[i] == rev) {
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
	delete[]a;
}

void numb7() {
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	for (int i = 0; i < n; i++) {
		if ((a[i] / 10) == (a[i] % 10)) {
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
	delete[]a;
}

void numb8() {
	//Дано масив цілих чисел.Після кожного симетричного елемента вставити 0.
	int n;
	cin >> n;
	int* a = new int[2 * n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int rev = 0;
	for (int i = 0; i < n; i++) {
		rev = 0;
		int temp = a[i];
		while (temp != 0) {
			rev = (rev * 10) + temp % 10;
			temp /= 10;
		}
		if (a[i] == rev) {
			for (int j = n; j > i; j--) { // j > (=) i 
				a[j] = a[j - 1];
			}
			a[i] = 0; // yaksho pered to a[i] = 0, pislya a[i+1] = 0;
			n++;
			i++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete[]a;
}

void numb9() {
	//Дано масив цілих чисел.Від’ємні елементи замінити максимальним елементом
	int n;
	cin >> n;
	int* a = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] < 0) {
			a[i] = max;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete[]a;
}

void numb10() {
	//Дано масив дійсних чисел.  Після кожного елемента, який співпадає із максимальним елементом, вставити мінімальний елемент. 
	int n; 
	cin >> n;
	int* a = new int[2 * n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max = a[0];
	int min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
		if (a[i] < min) {
			min = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		if (a[i] == max) {
			for (int j = n; j > i; j--) {
				a[j] = a[j - 1];
			}
			a[i+1] = min;
			n++;
			i++;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete[]a;
}

void numb11() {
	//Дано послідовність цілих чисел. Для кожної підпослідовності додатних елементів поміняти максимальний і мінімальний елементи.
	int n;
	cin >> n;
	int* a = new int[2 * n];
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
	int max, min, posmax, posmin;
	for (int i = 0; i < n; i++) {
		if (a[i] > 0) {
			max = min = a[i];
			posmax = posmin = i;
			while (i < n && a[i] > 0) {
				if (a[i] > max) {
					max = a[i];
					posmax = i;
				}
				if (a[i] < min) {
					min = a[i];
					posmin = i;
				}
				i++;
			}
			a[posmin] = max;
			a[posmax] = min;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
	}
	delete[]a;
}





int main() {
	//numb1a();
	//numb1b();
	//numb1c();
	//numb1d();
	//numb1e();
	//numb2();
	//numb3();
	numb4();
	//numb5();
	//numb6a();
	//numb6();
	//numb7();
	//numb8();
	//numb9();
	//numb10();
	//numb11();
	system("pause");
	return 0;
}