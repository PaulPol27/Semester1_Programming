#include <iostream>
#include <cmath>
#include <random>
using namespace std;

void numb8g() {
	double x;
	int k = 1;
	double sum = 0;
	double eps;
	double d;
	cin >> x >> eps;
	//double x_test = x;
	if (fabs(x) < 1) {
		d = x;
		while (fabs(d) > eps) {
			sum += d;
			d *= - x * k / (k + 1);
			k++;
		}
	}
	cout << "Sum = " << sum << " ln( x + 1) = " << log(x + 1) << endl;
}

void numb12() {
	for (int i = 1; i <= 9; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int l = 0; l <= 9; l++) {
				if (i != j && i != l && j != l) {
					cout << i << j << l << endl;
				}
			}
		}
	}

}

void num_14(){
	const int n = 80;
	int lower = 0;
	int upper = 10000;
	double arr[n];
	double min = DBL_MAX;
	int position;
	cout << min << endl;
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)(rand() % (upper - (lower)+1) + (lower)) / 1000;
	}
	for (int i = 0; i < n; i++) {
		int a = (int)arr[i];
		int b = a + 1;
		double dist_1 = b - arr[i];
		double dist_2 = arr[i] - a;
		double distance;
		if (dist_1 > dist_2)
		{
			distance = dist_2;
		}
		else {
			distance = dist_1;
		}
		if (distance < min) {
			min = distance;
			position = i;
		}
		cout << min << endl;
	}
	cout << position << " " << arr[position] << " " << min << endl;
}

void num_14_2_sposib() {
	int n, k = 0;
	double x, c, f, min = 1;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> x;
		c = ceil(x);
		f = floor(x);
		if (fabs(x - c) < min) {
			min = fabs(x - c);
			k = i;
		}
		if (fabs(x - f) < min) {
			min = fabs(x - f);
			k = i;
		}
	}
	cout << "K = " << k << endl;

}

void num_17() {
	int n;
	cin >> n;
	double sum = 0;
	int lower = 0;
	int upper = 10000;
	double *arr= new double[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = (double)(rand() % (upper - (lower)+1) + (lower)) / 1000;
		cout << arr[i] << endl;
	}
	int k = n;
	for (int i = 0; i < n; i++) {
		sum += k * arr[i];
		k -= 1;
	}
	cout << "Sum = " << sum << endl;
}

void num_18() {
	const int n = 200;
	double arr[n];
	int lower = 0;
	int upper = 10000;
	for (int i = 0; i < n; i++) {
		arr[i] = (double)(rand() % (upper - (lower)+1) + (lower)) / 1000;
	}
	int count = 0;
	for (int i = 1; i < n - 1; i++) {
		if (arr[i] > arr[i - 1] && arr[i] > arr[i + 1]) {
			count++;
		}
	}
	cout << "Count = " << count << endl;
}

int main() {
	//numb8g();
	//numb12();
	//num_14();
	//num_17();
	//num_18();
	num_14_2_sposib();
	system("pause");
	return 0;
}