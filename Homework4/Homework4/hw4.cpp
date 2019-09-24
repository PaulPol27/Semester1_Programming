#include <iostream>
#include <cmath>
using namespace std;

void tabilyuvatu(){
	double x, y, d, eps, a, b, h;
	int k;
	cin >> a >> b >> h >> eps;
	for (x = a; x <= b + h / 2; x += h) {
		d = 1; k = 0; y = 0;
		while (fabs(d) > 0) {
			y += d;
			d *= -x * x / ((2 * k + 2) * (2 * k + 1));
			k++;
		}
	}
	cout << " \t = " << x << " y = " << y << " cos(x) = " << cos(x) << endl;
}

int main() {
	tabilyuvatu();
	system("pause");
	return 0;
}
