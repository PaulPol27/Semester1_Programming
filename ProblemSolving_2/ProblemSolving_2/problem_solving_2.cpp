#include <iostream>
#include <cmath>
using namespace std;

void num1() {
	const int n = 10;
	int arr[n];
	for (int i = 0; i < n; i++) {
		arr[i] = 2 * i + 1;
	}
	for (int i = n - 1; i >= 0; i--) {
		cout << arr[i] << " ";
	}
	cout << endl;
}

void num2() {
	const int n = 3;
	int arr[n], y = 1, mn;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	mn = arr[n - 1];
	for (int i = n - 1; i >= 0; i--) {
		y *= mn;
		mn += arr[i - 1];
	}
	cout << y << endl;
}

void num2_g() {
	const int n = 3;
	int arr[n], y = 0;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n; i++) {
		y += arr[i] * arr[n - 1 - i];
	}
	cout << y << endl;
}

void num_3() {
	const int n = 3;
	int arr_1[n], arr_2[n], arr_3[n];
	cout << "Input first vector " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr_1[i];
	}
	cout << "Input second vector " << endl;
	for (int i = 0; i < n; i++) {
		cin >> arr_2[i];
	}
	bool t = true;
	for (int i = 0; i < n; i++) {
		if (arr_1[i] != arr_2[i]) {
			t = false;
			break;
		}
	}
	if (t == true) {
		for (int i = 0; i < n; i++) {
			arr_3[i] = arr_1[i];
		}
	}
	else {
		for (int i = 0; i < n; i++) {
			arr_3[i] = arr_1[i] + arr_2[i];
		}
	}
	for (int i = 0; i < n; i++) {
		cout << arr_3[i] << " " << endl;
	}
}

void num_6() {
	const int n = 4;
	int arr[n];
	int temp;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n / 2; i++) {
		temp = arr[i];
		arr[i] = arr[n - 1 - i];
		arr[n - 1 - i] = temp;
	}
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << endl;
	}
}

void num_6_g() {
	const int n = 4;
	int arr[n];
	int temp_1, temp_2;
	for(int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	temp_1 = arr[0];
	temp_2 = arr[1];
	for (int i = 0; i < n - 2; i++) {
		arr[i] = arr[i + 2];
	}
	arr[n - 2] = temp_1;
	arr[n - 1] = temp_2;
	for (int i = 0; i < n; i++) {
		cout << arr[i] << " " << endl;
	}
}

void num_7() {
	const int n = 5, m = 3, k = 8;
	int arr1[n], arr2[m], arr3[k];
	int i, j, l;
	for ( i = 0; i < n; i++) {
		cin >> arr1[i];
	}
	for ( i = 0; i < m; i++) {
		cin >> arr2[i];
	}
	i = j = l = 0;
	while (i < n && j < m) {
		if (arr1[i] < arr2[j]) {
			arr3[l] = arr1[i];
			l++;
			i++;
		}
		else {
			arr3[l] = arr2[j];
			j++;
			l++;
		}
	}
	if (i < n) {
		while (i < n) {
			arr3[l++] = arr1[i++];
		}
	}
	else {
		while (j < n) {
			arr3[l++] = arr2[j++];
		}
	}
	for (i = 0; i < k; i++) {
		cout << arr3[i] << " " << endl;
	}
}

void num_8a() {
	const int n = 5;
	int arr[n];
	int t = 1;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < n - 1; i++) {
		if (arr[i + 1] <= arr[i]) {
			t = 0;
			break;
		}
	}
	cout << t << endl;
}

void num11() {
	const int n = 5;
	double x[n], y[n], d, max = 0;
	int p, k;
	for (int i = 0; i < n; i++){
		cin >> x[i] >> y[i];
	}
	for (int i = 0; i < n-1; i++){
		for (int j = i + 1; j < n; j++) {
			d = sqrt(pow((x[i] - x[j]), 2) + pow((y[i] - y[j]), 2));
			if (d > max) {
				p = i;
				k = j;
				max = d;
			}
		}
	}
	cout << p << " " << k << " " << endl;
}

int main() {
	//num1();
	//num2();
	//num2_g();
	//num_3();
	//num_6();
	num_6_g();
	//num_7();
	//num_8a();
	//num11();
	system("pause");
	return 0;
}