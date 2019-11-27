#include <iostream>
#include<fstream>
using namespace std;

//Stvorutu tup ingredient nazva, kaloriynist, zina;
//Stvorutu tup bludo, nazva, masuv ingredientiv; Dano masuv blud, posortuvatu yich za zinoyu, znaytu bludo z min kaloriynistyu, vuvestu nazvu blud yaki mistat vkazanuy ingredient;


class Item {
protected:
	string name;
	double kal;
	double price;
public:
	Item() {
		name = "";
		kal = 0;
		price = 0;
	}
	Item(string name, double kal, double price) {
		this->name = name;
		this->kal = kal;
		this->price = price;
	}
	friend istream& operator>>(istream& in, Item& a) {
		in >> a.name >> a.kal >> a.price;
		return in;
	}
	friend ostream& operator<<(ostream& out, Item& a) {
		out << a.name << " ";
		return out;
	}
	string getName()const {
		return name;
	}
	double getKal()const {
		return kal;
	}
	double getPrice()const {
		return price;
	}
};

class Dish{
protected:
	string name_1;
	int n;
	Item* items;
public:
	Dish() {
		name_1 = "";
		n = 0;
		items = (NULL);
	}
	Dish(string name_1, int n) {
		this->name_1 = name_1;
		this->n = n;
		items = new Item[n];
	}
	Dish(const Dish& a) {
		name_1 = a.name_1;
		n = a.n;
		items = new Item[a.n];
		for (int i = 0; i < a.n; i++) {
			items[i] = a.items[i];
		}
	}
	Dish& operator=(const Dish& a) {
		if (this != &a) {
			delete[]items;
			name_1 = a.name_1;
			n = a.n;
			items = new Item[a.n];
			for (int i = 0; i < a.n; i++) {
				items[i] = a.items[i];
			}
		}
		return*this;
	}
	~Dish() {
		delete[]items;
	}
	string getName() {
		return name_1;
	}
	double getDish_price() {
		double s = 0;
		for (int i = 0; i < n; i++) {
			s += items[i].getPrice();
		}
		return s;
	}
	double getDish_kal() {
		double s = 0;
		for (int i = 0; i < n; i++) {
			s += items[i].getKal();
		}
		return s;
	}
	bool hasIng(string ing) {
		for (int i = 0; i < n; i++) {
			if (items[i].getName() == ing) {
				return true;
			}
		}
		return false;
	}
	friend istream& operator>>(istream& in, Dish& a) {
		in >> a.name_1 >> a.n;
		a.items = new Item[a.n];
		for (int i = 0; i < a.n; i++) {
			in >> a.items[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Dish& a) {
		out << a.name_1 << " ";
		for (int i = 0; i < a.n; i++) {
			out << a.items[i] << " ";
		}
		out << a.getDish_price() << " " << a.getDish_kal() << endl;
		return out;
	}
};

void sort(Dish* a, int n) {
	Dish temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].getDish_price() > a[j + 1].getDish_price()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void min_kal(Dish* a, int n, ostream& out) {
	double min = a[0].getDish_kal();
	string name = "";
	for (int i = 0; i < n; i++) {
		if (a[i].getDish_kal() < min) {
			min = a[i].getDish_kal();
			name = a[i].getName();
		}
	}
	out << name << " ";
}

void search(Dish* a, int n, string ing, ostream& out) {
	for (int i = 0; i < n; i++) {
		if (a[i].hasIng(ing)) {
			out << a[i].getName() << endl;
		}
	}
}

int main() {
	int n;
	ifstream in("dishes.txt");
	in >> n;
	Dish* a = new Dish[n];
	for (int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	ofstream out("results.txt");
	sort(a, n);
	for (int i = 0; i < n; i++) {
		out << a[i] << " ";
	}
	out << endl;
	min_kal(a, n, out);
	out << endl;
	string ing;
	cin >> ing;
	search(a, n, ing, out);
	out.close();
	system("pause");
	return 0;
}

