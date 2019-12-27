#include "Credit.h"

// ++++++++++ Task 1 ++++++++++++++

void read_array(Credit** &a,int n) {
	a[0]->setSur("Polyuha");
	a[0]->setNumb(209867);
	a[0]->setSum(2000);

	a[1]->setSur("Balabuch");
	a[1]->setNumb(390876);
	a[1]->setSum(4000);
	  
	a[2]->setSur("Morozevuch");
	a[2]->setNumb(378488);
	a[2]->setSum(5000);
	  
	a[3]->setSur("Staskiv");
	a[3]->setNumb(347590);
	a[3]->setSum(1500);
}

void max_sum(Credit** a, int n) {
	Credit* max = a[0];
	for (size_t i = 0; i < n; ++i) {
		if (a[i]->getSum() > max->getSum()) {
			max = a[i];
		}
	}
	cout << max->getSur() << " " << max->getNumb() << " " << max->getSum() << endl;
} 

//++++++++++++ Task 2+++++++++++++++

void max_total_sum(Credit** a, int n, ostream& out) {
	Gold* max;
	max = dynamic_cast<Gold*>(a[0]);
	if (max != nullptr) {
		for (size_t i = 0; i < n; ++i) {
			Gold* temp;
			temp = dynamic_cast<Gold*>(a[i]);
			if (temp != nullptr) {
				double s = max->getSum() + max->getAddsum();
				if (s < temp->getSum() + temp->getAddsum()) {
					max = temp;
				}
			}
		}
		out << max->getSur() << " " << max->getNumb() << " " << max->getSum() + max->getAddsum() << endl;
	}
}

//++++++++++++++++++++ Task 3++++++++++++++++++++

void max_credits_sum(Credit** a, int n, double p, ostream& out) {
	VIP* max;
	max = dynamic_cast<VIP*>(a[0]);
	if (max != nullptr) {
		for (size_t i = 0; i < n; ++i) {
			VIP* temp;
			temp = dynamic_cast<VIP*>(a[i]);
			if (temp != nullptr) {
				double l = p * (temp->getSum() + temp->getAddsum());
				temp->setCredit(l);
				double s = max->getSum() + max->getAddsum() + max->getCredsum();
				if (s < temp->getSum() + temp->getAddsum() + temp->getCredsum()) {
					max = temp;
				}
			}
		}
		out << max->getSur() << " " << max->getNumb() << " " << max->getSum() << " " << max->getAddsum() << " " << max->getCredsum()<< endl;
	}
}

void print(Credit** a, int n, ostream& out) {
	for (size_t i = 0; i < n; ++i) {
		VIP* temp;
		temp = dynamic_cast<VIP*>(a[i]);
		if (temp != nullptr) {
			out << temp->getSur() << " " << temp->getNumb() << " " << temp->getCredsum() + temp->getAddsum() + temp->getSum() << endl;
		}
	}
}

int main() {

	int n1 = 4;
	Credit** a = new Credit * [n1];
	for (size_t i = 0; i < n1; ++i) {
		a[i] = new Credit;
	}
	read_array(a, n1);



	ifstream in1("input1.txt");
	in1 >> n1;
	Credit** v = new Credit * [n1];
	for (size_t i = 0; i < n1; ++i) {
		v[i] = new Credit[n1];
		v[i]->input(in1);
	}



	ifstream in2("input2.txt");
	int n2;
	in2 >> n2;
	Credit** b = new Credit * [n2];
	for (size_t i = 0; i < n2; ++i) {
		b[i] = new Gold;
		b[i]->input(in2);
	}



	ifstream in3("input3.txt");
	int n3;
	in3 >> n3;
	int n_total = n1 + n2 + n3;
	Credit** c = new Credit * [n_total];
	for (size_t i = 0; i < n3; ++i) {
		c[i] = new VIP;
		c[i]->input(in3);
	}
	int q = 0;
	for (size_t i = n3; i < n2 + n3; ++i) {
		c[i] = b[q];
		q++;
	}
	q = 0;
	for (size_t i = n2 + n3; i < n_total; ++i) {
		c[i] = v[q];
		q++;
	}


	ofstream out("result.txt");
	//+++++++++++=++++ Task 1 +++++++++++++++++
	for (size_t i = 0; i < n1; ++i) {
		a[i]->output(cout);
	}
	cout << endl;
	max_sum(a, n1);

	// ++++++++++++++ Task 2 ++++++++++++++

	max_total_sum(b, n2, out);
	out << endl;

	//+++++++++++++++++ Task 3 ++++++++++++++++

	double p;
	p = 0.5;
	max_credits_sum(c, n3, p, out);
	print(c, n3, out);

	// +++++++++++++++++++++++++++++++ END
	in1.close();
	in2.close();
	in3.close();
	out.close();
	system("pause");
	return 0;
}