#include "Avia_tick.h"

void print1(Tickets* a, int n) {
	Tickets min = a[0];
	string name1 = "";
	for (size_t i = 0; i < n; ++i) {
		if (a[i].getPrice() < min.getPrice()) {
			min = a[i];
		}
	}
	cout << min.getDest() << endl;
}

//void print2(Tickets** a, double k, int n) {
//	for (int i = 0; i < n; ++i) {
//		Luggage* temp;
//		temp = dynamic_cast<Luggage*>(a[i]);
//		if (temp != nullptr) {
//			temp = (Luggage*)a[i];
//			double price = temp->getPrice() * (1 + k * temp->getM());
//			temp->setPrice(price);
//			//cout << temp->getPrice();
//		}
//	}
//}
//
//void print3(Tickets** a, int n, ostream& out) {
//	Luggage* min;
//	min = (Luggage*)(a[0]);
//	if (min != nullptr) {
//		for (int i = 0; i < n; ++i) {
//			if (a[i]->getPrice() < min->getPrice()) {
//				min = (Luggage*)a[i];
//			}
//		}
//		out << min->getDest() << endl;
//		cout << 3 << endl;
//	}
//}

//void print3(Tickets** a, double k, int n) {
//	for (int i = 0; i < n; ++i) {
//		Bussiness* temp;
//		temp = dynamic_cast<Bussiness*>(a[i]);
//		if (temp != nullptr) {
//			temp = (Bussiness*)a[i];
//			double price = temp->getPrice() * (1 + k * temp->getM());
//			temp->setPrice(price);
//			//cout << temp->getPrice();
//		}
//	}
//}

int main() {
	int n;
	ifstream in1("input1.txt");
	in1 >> n;
	Tickets* a = new Tickets[n];
	for (int i = 0; i < n; i++) {
		a[i].input(in1);
	}

	ifstream in2("input2.txt");
	in2 >> n;
	Tickets* a = new Tickets[n];
	for (int i = 0; i < n; i++) {
		a[i].input(in2);
	}

	ifstream in3("input3.txt");
	in3 >> n;
	Tickets* a = new Tickets[n];
	for (int i = 0; i < n; i++) {
		a[i].input(in3);
	}
	ofstream out("result.txt");
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	out << endl;
	print1(a, n);
	out << endl;
	/*print2(a, 1.5, n);
	out << endl;
	for (int i = 0; i < n; i++) {
		a[i]->output(out);
	}
	out << endl;
	print3(a, n, out);*/
	system("pause");
	return 0;
}