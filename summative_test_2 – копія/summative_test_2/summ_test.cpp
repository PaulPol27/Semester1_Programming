#include<iostream>
#include<fstream>
using namespace std;

class River {
private:
	string name;
	int l;
	string country;
public:
	River() {
		name = "";
		l = 0;
		country = "";
	}
	River(string name, int l, string country) {
		this->name = name;
		this->l = l;
		this->country = country;
	}
	River(const River& a) {
		name = a.name;
		l = a.l;
		country = a.country;
	}
	string getName() {
		return name;
	}
	int getL()const {
		return l;
	}
	string getCountry()const {
		return country;
	}
	friend istream& operator>>(istream& in, River& a) {
		in >> a.name >> a.l >> a.country;
		return in;
	}
	friend ostream& operator<<(ostream& out, River& a) {
		out << a.name << " " << a.l << " " << a.country << " ";
		return out;
	}
};

void sort(River* a, int n) {
	River temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].getCountry() > a[j + 1].getCountry()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void sum(River* a, int n, ostream& out) {
	int s = 0;
	string total_names = "";
	for (int i = 0; i < n; i++) {
		s = a[i].getL();
		int k = 0;
		total_names = a[i].getName();
		for (int j = i + 1; j < n; j++) {
			if (a[i].getCountry() == a[j].getCountry()) {
				k++;
				s += a[j].getL();
				total_names += " " + a[j].getName();
			}
		}
		out << a[i].getCountry() << " " << total_names << " " << s << endl;
		i += k;
	}
}

void name(River* a, int n, ostream& out) {
	int s = 0;
	int k = 0;
	int max = INT_MIN;
	string name = "";
	for (int i = 0; i < n; i++) {
		s = a[i].getL();
		k = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[i].getCountry() == a[j].getCountry()) {
				k++;
				s += a[j].getL();
			}
		}
		for (int l = 0; l < k; l++) {
			if (s > max) {
				max = s;
				name = a[i].getCountry();
			}
		}
		i += k;
	}
	out << name;
}

void peremist(River* a, int n, ostream& out) {
	int max = INT_MIN;
	string* c = new string[n];
	string* r = new string[n];
	int k = 0;
	bool t = true;
	for (int i = 0; i < n; i++) {
		int len = a[i].getL();
		string country = a[i].getCountry();
		string river = a[i].getName();
		for (int j = i + 1; j < n; j++) {
			if (a[i].getCountry() == a[j].getCountry()) {
				if (len < a[j].getL()) {
					len = a[j].getL();
					river = a[j].getName();
					country = a[j].getCountry();
				}
			}
		}
		for (int l = 0; l < k; l++) {
			if (c[l] == country) {
				t = false;
			}
		}
		if (t) {
			c[k] = country;
			r[k] = river;
			k++;
		}
	}
	for (int i = 0; i < k; i++) {
		out << r[i] << endl;
	}
}


int main() {
	int n;
	ifstream in("input.txt");
	in >> n;
	River* a = new River[n];
	for (int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	ofstream out("results.txt");
	sort(a, n);
	for (int i = 0; i < n; i++) {
		out << a[i] << endl;
	}
	out << endl;
	sum(a, n, out);
	out << endl;
	name(a, n, out);
	out << endl;
	peremist(a, n, out);
	out << endl;
	out.close();
	system("pause");
	return 0;
}