#include <iostream>
#include <cmath>
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

int main() {
	numb8g();
	//numb12();
	system("pause");
	return 0;
}