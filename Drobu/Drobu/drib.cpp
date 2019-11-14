#include <iostream>
#include <cmath>
using namespace std;

class Drib {
	int ch, zn;
public:
	Drib(int a, int b) {
		ch = a;
		zn = b;
	}
	void print() {
		cout << ch << " / " << zn;
	}
	void print_other_drib(int a, int b)
	{
		cout << a << " / " << b;
	}
	void multiply(int a, int b) {
		cout << "Multiply: ";
		print();
		cout << " * ";
		print_other_drib(a, b);
		cout << " = " << ch * a << " / " << zn * b << endl;
	}
	void divide(int a, int b) {
		cout << "Divide: (" ;
		print();
		cout << ") / (";
		print_other_drib(a, b);
		cout << ") = " << ch * b << " / " << zn * a << endl;
	}
	double reduce;
	double add;
	double subtract;
};

int main() {
	int a, b;
	cin >> a >> b;
	int c, d;
	cin >> c >> d;
	Drib drib (a, b);
	drib.print();
	cout << endl;

	drib.multiply(c, d);

	drib.divide(c, d);

	system("pause");
	return 0;

}



