#include "AZS.h"

//+++++++++++++++ Task 1 ++++++++++++++++

void read_arr(AZS** &a, int n) {
	a[0]->setName("OKKO");
	a[0]->setPrice(50);
	a[0]->setQuant(20);

	a[1]->setName("WOG");
	a[1]->setPrice(60);
	a[1]->setQuant(30);

	a[2]->setName("Socar");
	a[2]->setPrice(100);
	a[2]->setQuant(25);
}

void Max_Price(AZS** a, int n) {
	AZS* max = a[0];
	for (size_t i = 0; i < n; ++i) {
		if (a[i]->getPrice() > max->getPrice()) {
			max = a[i];
		}
	}
	cout << max->getName() << endl;
}

// ++++++++++++++++ Task 2 +++++++++++++++++++++++++

void set_new_price(AZS** a, int n, double f) {
	for (int i = 0; i < n; i++) {
		Card* temp;
		temp = dynamic_cast<Card*>(a[i]);
		if (temp != nullptr) {
			double sumas = temp->getPrice() * (1 - f);
			temp->setPrice(sumas);
		}
	}
}

void max_card_price(AZS** a, int n, ostream& out) {
	Card* max;
	max = dynamic_cast<Card*>(a[0]);
	if (max != nullptr) {
		for (size_t i = 0; i < n; ++i) {
			if (max->getPrice() < a[i]->getPrice()) {
				max = (Card*)(a[i]);
			}
		}
		out << max->getNumb() << " " << max->getPrice() << endl;
	}
}



void print(AZS** a, int n, ostream& out) {
	AZS* temp1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j]->getName() > a[j + 1]->getName()) {
				temp1 = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp1;
			}
		}
	}
	for (size_t i = 0; i < n; ++i) {
		Card* temp2;
		temp2 = dynamic_cast<Card*>(a[i]);
		int k = 0;
		if (temp2 != nullptr) {
			int s = temp2->getPrice();
			for (int j = i+1; j < n; j++) {
				Card* temp3;
				temp3 = dynamic_cast<Card*>(a[j]);
				if (temp3 != nullptr) {
					if (temp3->getName() == temp2->getName()) {
						s += temp3->getPrice();
						k++;
					}
				}
			}
			out << temp2->getName() << " " << s << endl;
		}
		i += k;
	}
}


int main() {


	int n1 = 3;
	AZS** a = new AZS * [n1];
	for (size_t i = 0; i < n1; ++i) {
		a[i] = new AZS;
	}
	read_arr(a, n1);
	for (size_t i = 0; i < n1; ++i) {
		a[i]->output(cout);
	}
	cout << endl;
	Max_Price(a, n1);

	int n2;
	ifstream in2("input2.txt");
	in2 >> n2;
	AZS** b = new AZS * [n2];
	for (size_t i = 0; i < n2; ++i) {
		b[i] = new Card;
		b[i]->input(in2);
	}
	ofstream out("result.txt");

	// +++++++++++++++++ Task 2+++++++++++++++++++
	double f = 0.7;
	set_new_price(b, n2, f);
	max_card_price(b, n2, out);
	out << endl;
	print(b, n2, out);
	system("pause");
	return 0;
}