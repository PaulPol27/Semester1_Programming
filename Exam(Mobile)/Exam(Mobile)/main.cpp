#include "Mobile.h"

// ++++++++++++++++ Task 1 +++++++++++++++++++

void read_arr(Mobile**& a, int n) {

	a[0]->setNumb(958891);
	a[0]->setMonth("July");
	a[0]->setSum(100);

	a[1]->setNumb(953365);
	a[1]->setMonth("March");
	a[1]->setSum(200);

	a[2]->setNumb(667544);
	a[2]->setMonth("March");
	a[2]->setSum(150);

	a[3]->setNumb(957913);
	a[3]->setMonth("November");
	a[3]->setSum(50);

}

void max_sum(Mobile** a, int n) {
	Mobile* max = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i]->getSum() > max->getSum()) {
			max = a[i];
		}
	}
	cout << "The maximal sum has number: " << max->getNumb() << endl;
}

//+++++++++++++++++++++++++ Task 2 ++++++++++++++++++++++++++++

//void set_price_time(Mobile** a, int n, double p){
//	for (int i = 0; i < n; i++) {
//		Add_time* temp;
//		temp = dynamic_cast<Add_time*>(a[i]);
//		if (temp != nullptr) {
//			double new_sum = (temp->getTime() * p) + temp->getSum();
//			temp->setSum(new_sum);
//		}
//	}
//}
//
//void max_set_price(Mobile** a, int n, double* &numb, int &k) {
//	Add_time* max;
//	max = dynamic_cast<Add_time*>(a[0]);
//	k = 0;
//	if (max != nullptr) {
//		for (int i = 0; i < n; i++) {
//			if (a[i]->getSum() > max->getSum()) {
//				max = (Add_time*)(a[i]);
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			if (max->getSum() == a[i]->getSum()) {
//				numb[k] = a[i]->getNumb();
//				k++;
//			}
//		}
//	}
//}
//
//void print_max_price(Mobile** a, int n, double*& numb, ostream& out, int k) {
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < n; j++) {
//			Add_time* temp;
//			temp = dynamic_cast<Add_time*>(a[j]);
//			if (temp != nullptr) {
//				if (a[j]->getNumb() == numb[i]) {
//					out << temp->getNumb() << "----" << temp->getSum() << "----" << temp->getMonth() << endl;
//				}
//			}
//		}
//	}
//}
//void set_price_time(Mobile** a, int n, double p) {
//	for (int i = 0; i < n; i++) {
//		Add_time* temp;
//		temp = dynamic_cast<Add_time*>(a[i]);
//		if (temp != nullptr) {
//			double new_sum = (temp->getTime() * p) + temp->getSum();
//			temp->setSum(new_sum);
//		}
//	}
//}
//
//void max_set_price_time(Mobile** a, int n, double*& numb, int& k) {
//	Add_time* max;
//	k = 0;
//	max = dynamic_cast<Add_time*>(a[0]);
//	if (max != nullptr) {
//		for (int i = 0; i < n; i++) {
//			if (a[i]->getSum() > max->getSum()) {
//				max = (Add_time*)(a[i]);
//			}
//		}
//		for (int i = 0; i < n; i++) {
//			if (a[i]->getSum() == max->getSum()) {
//				numb[k] = a[i]->getNumb();
//				k++;
//			}
//		}
//	}
//}
//
//void print_sum_time(Mobile** a, int n, double*& numb, int k, string mon, ostream& out) {
//	for (int i = 0; i < k; i++) {
//		for (int j = 0; j < n; j++) {
//			Add_time* temp;
//			temp = dynamic_cast<Add_time*>(a[j]);
//			if (temp != nullptr) {
//				if (temp->getNumb() == numb[i] && temp->getMonth() == mon) {
//					out << temp->getNumb() << " ---- " << temp->getSum() << "----" << temp->getMonth() << endl;
//				}
//			}
//		}
//	}
//}


// ++++++++++++++++ Task 3 +++++++++++++++++++++++++++

void set_price_int(Mobile** a, int n, double b) {
	for (int i = 0; i < n; i++) {
		Internet* temp;
		temp = dynamic_cast<Internet*>(a[i]);
		if (temp != nullptr) {
			double new_sum = (temp->getGb() * b) + temp->getSum();
			temp->setSum(new_sum);
		}
	}
}

void max_set_price_int(Mobile** a, int n, double*& numb, int& k) {
	Internet* max;
	max = dynamic_cast<Internet*>(a[0]);
	k = 0;
	if (max != nullptr) {
		for (int i = 0; i < n; i++) {
			if (a[i]->getSum() > max->getSum()) {
				max = (Internet*)(a[i]);
			}
		}
		for (int i = 0; i < n; i++) {
			if (max->getSum() == a[i]->getSum()) {
				numb[k] = a[i]->getNumb();
				k++;
			}
		}
	}
}

void print_max_price_int(Mobile** a, int n, double*& numb, ostream& out, int k, string month) {
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < n; j++) {
			Internet* temp;
			temp = dynamic_cast<Internet*>(a[j]);
			if (temp != nullptr) {
				if (temp->getNumb() == numb[i]&& temp->getMonth() == month) {
					out << temp->getNumb() << "----" << temp->getSum() << "----" << temp->getMonth() << endl;
				}
			}
		}
	}
}

int main() {


	const int n = 4;
	Mobile** v = new Mobile * [n];
	for (int i = 0; i < n; i++) {
		v[i] = new Mobile;
	}
	read_arr(v, n);
	for (int i = 0; i < n; i++) {
		v[i]->output(cout);
	}
	cout << endl;
	max_sum(v, n);


	int n1;
	ifstream in1("input1.txt");
	in1 >> n1;
	Mobile** a = new Mobile * [n1];
	for (int i = 0; i < n1; i++) {
		a[i] = new Mobile[n1];
		a[i]->input(in1);
	}

	int n2;
	ifstream in2("input2.txt");
	in2 >> n2;
	Mobile** b = new Mobile * [n2];
	for (int i = 0; i < n2; i++) {
		b[i] = new Add_time[n2];
		b[i]->input(in2);
	}

	int n3;
	ifstream in3("input3.txt");
	in3 >> n3;
	int n_total = n1 + n2 + n3;
	Mobile** c = new Mobile * [n3];
	for (int i = 0; i < n3; i++) {
		c[i] = new Internet[n3];
		c[i]->input(in3);
	}
	int q = 0;
	for (int i = n3; i < n2 + n3; i++) {
		c[i] = b[q];
		q++;
	}
	q = 0;
	for (int i = n2 + n3; i < n_total; i++) {
		c[i] = a[q];
		q++;
	}
	

	//int n2;
	//ifstream in2("input2.txt");
	//in2 >> n2;
	//Mobile** b = new Mobile * [n2];
	//for (int i = 0; i < n2; i++) {
	//	b[i] = new Add_time[n2];
	//	b[i]->input(in2);
	//}

	//int n3;
	//ifstream in3("input3.txt");
	//in3 >> n3;
	//int n_total = n1 + n2 + n3;
	//Mobile** c = new Mobile * [n3];
	//for (int i = 0; i < n3; i++) {
	//	c[i] = new Internet[n3];
	//	c[i]->input(in3);
	//}
	//int q = 0;
	//for (int i = n3; i < n2 + n3; i++) {
	//	c[i] = b[q];
	//	q++;
	//}
	//q = 0;
	//for (int i = n2 + n3; i < n_total; i++) {
	//	c[i] = a[q];
	//	q++;
	//}

	// ++++++++++++++++++++ Task 2 +++++++++++++++++++++

	ofstream out("result.txt");
	double y = 1.5;
	set_price_time(b, n2, y);

	double* numb = new double[n2];
	int s = 0;
	max_set_price_time(b, n2, numb, s);
	print_sum_time(b, n2, numb, s, "May", out);
	out << endl;


	// ++++++++++++++++++ Task 3+++++++++++++++++++++++++
	double m = 2.5;
	set_price_int(c, n3, m);
	double* number = new double[n3];
	int z = 0;
	max_set_price_int(c, n3, number,z);
	print_max_price_int(c, n3, number, out, z, "May");

	system("pause");
	return 0;
}