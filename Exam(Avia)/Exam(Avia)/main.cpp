#include "Avia_tick.h"

// +++++++++++++++++++++ Task 1 +++++++++++++++++++++++

void print1(Tickets** a, int n) {
	Tickets* min = a[0];
	for (size_t i = 0; i < n; ++i) {
		if (a[i]->getPrice() < min->getPrice()) {
			min = a[i];
		}
	}
	cout << min->getDest() << endl;
}

// ++++++++++++++++++ Task 2 +++++++++++++++++++++

void set_lug_price(Tickets** a, int n, double k) {
	for (int i = 0; i < n; i++) {
		Luggage* temp;
		temp = dynamic_cast<Luggage*>(a[i]);
		if (temp != nullptr) {
			double sumas = temp->getPrice() * (1 + k * temp->getM());
			temp->setPrice(sumas);
		}
	}
}

void min_Lugg(Tickets** a, int n, string*& com, int& k) {
	Luggage* min;
	k = 0;
	min = dynamic_cast<Luggage*>(a[0]);
	if (min != nullptr) {
		for (int i = 0; i < n; i++) {
			if (a[i]->getPrice() < min->getPrice()) {
				min = (Luggage*)(a[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			if (a[i]->getPrice() == min->getPrice()) {
				com[k] = a[i]->getName();
				k++;
			}
		}
	}
}

void print_Dest_lugg(Tickets** a, int n, ostream& out, string*& com, int k) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			Luggage* temp;
			temp = dynamic_cast<Luggage*>(a[j]);
			if (temp != nullptr) {
				if (temp->getName() == com[i]) {
					out << temp->getDest() << endl;
				}
			}
		}
	}
}

// ++++++++++++ Task 3 +++++++++++++++++++++++++

void set_bussiness_price(Tickets** a, double b, int n) {
	for (int i = 0; i < n; ++i) {
		Bussiness* temp;
		temp = dynamic_cast<Bussiness*>(a[i]);
		if (temp != nullptr) {
			temp = (Bussiness*)a[i];
			double price = temp->getPrice() + temp->getPrice() * b;
			temp->setPrice(price);
		}
	}
}

void min_bussiness_p(Tickets** a, int n, ostream& out, int& k, string* &com) {
	Bussiness* min;
	k = 0;
	min = (Bussiness*)(a[0]);
	if (min != nullptr) {
		for (int i = 0; i < n; ++i) {
			if (a[i]->getPrice() < min->getPrice()) {
				min = (Bussiness*)a[i];
			}
		}
		for (int i = 0; i < n; i++) {
			if (min->getPrice() == a[i]->getPrice()) {
				com[k] = a[i]->getName();
				k++;
			}
		}
	}
}

void print_Dest_bussiness(Tickets** a, int n, ostream& out, int k, string* &com) {
	for (int j = 0; j < k; ++j) {
		for (int i = 0; i < n; ++i) {
			Bussiness* temp = (Bussiness*)(a[i]);
			if (temp != nullptr) {
				if (a[i]->getName() == com[j]) {
					out << temp->getDest() << endl;
				}
			}
		}
	}
}

int main(){
	int n1, n2, n3;
	ifstream in1("input1.txt");
	in1 >> n1;
	Tickets** a = new Tickets*[n1];
	for (int i = 0; i < n1; i++) {
		a[i] = new Tickets;
		a[i]->input(in1);
	}

	ifstream in2("input2.txt");
	in2 >> n2;
	Tickets** b = new Tickets*[n2];
	for (int i = 0; i < n2; i++) {
		b[i] = new Luggage;
		b[i]->input(in2);
	}

	ifstream in3("input3.txt");
	in3 >> n3;
	int n_total = n1 + n2 + n3;
	Tickets** c = new Tickets * [n_total];
	for (int i = 0; i < n3; i++) {
		c[i] = new Bussiness;
		c[i]->input(in3);
	}
	double k = 1.5;
	set_lug_price(c, k, n3);
	int q = 0;
	for (int i = n3; i < n3+n2; i++) {
		c[i] = b[q];
		q++;
	}
	q = 0;
	for (int i = n3+n2; i < n_total; i++) {
		c[i] = a[q];
		q++;
	}
	ofstream out("result.txt");

	// ++++++++ Task 1 (print_all, min price)++++++++++++++++
	/*for (int i = 0; i < n1; i++) {
		a[i]->print_all();
	}
	cout << endl;*/
	print1(a, n1);
	//++++++++++++++++++++++++++++++++++++++++++++++     End  

	// ++++++++ Task 2 (setprice, min price)++++++++++++++++

	double h = 1.5;
	set_lug_price(b, h, n2);
	string* company = new string[n2];
	int s = 0;
	min_Lugg(b, n2, company, s);
	print_Dest_lugg(b, n2, out, company, s);
	out << endl;

	//++++++++++++++++++++++++++++++++++++++++++++++     End 

	// ++++++++ Task 3 (setprice, min price)++++++++++++++++

	double l = 0.3;
	set_bussiness_price(c, l, n3);
	//for (int i = 0; i < n3;i++) {
	//	c[i]->output(out);
	//}
	string* comp = new string[n3];
	int u = 0;
	min_bussiness_p(c, n3, out, u, comp);
	print_Dest_bussiness(c, n3, out, u, comp);

	// ++++++++++++++++++++++++++++++++++++++++++++      End
	in1.close();
	in2.close();
	in3.close();
	out.close();
	system("pause");
	return 0;
}