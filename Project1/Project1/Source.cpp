void numb_1() {
	// type_result name(type1 param1, type2 param2){ body...}
	//1) po znachennyu : void swap(int a(x), int b(y)){ int t = a; a = b; b = t;} int x = 5, y = 5; swap (x, y); cout << x << " " << y; // result is : 5 7;
	//2) cherez vkazivnuk : void swap(int* a(x), int* b(y)) { int* t = a; a = b; b = t;} int x = 5; int y = 7; swap (&x, &y); cout << x << y; // result is : 7 5;
	//3) cherez posulannya : void swap(int &a(=x), int &b(= y)){ int t = a; a = b; b = t;} int x = 5; int y = 7; swap (x, y); cout << x << y; // result is : 7 5;
	// dano n chusel, perevirutu skilku z nuch ye chuslamu Fibonachi;
	bool isFibo(int x);
	if (x <= 0) {
		return false;
	}
	if (x == 1) {
		return true;
	}
	int x1, x2, xn;
	x1 = x2 = 1;
	while ((xn = x1 + x2) < x) {
		x1 = x2;
		x2 = xn;
	}
	if (xn == x) {
		return true;
	}
	else {
		return false;
	}
}

void numb_2() {
	int n, a, k = 0;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a;
		if (isFibo(a)) {
			k++;
		}
	}
	cout << k << endl;
}
int main() {
	numb_1();
	numb_2();
	system("pause");
	return 0;
}