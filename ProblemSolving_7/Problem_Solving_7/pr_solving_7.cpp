#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#define _USE_MATH_DEFINES
using namespace std;
//stvorutu klass animal z polyamu nazva i zina
class Animal {
private:
	string name;
	double price;
public:
	Animal() {
		name = " ";
		price = 0;
	}
	Animal(string name1, double price1) {
		name = name1;
		price = price1;
	}
	void input(istream& in) { // chutannya z potoku(istream - ze potik dlya chutannya); (&) ze posulannya na potik;
		in >> name >> price;
	}
	void output(ostream& out) { // potik dlya vuvody v potik(ostream - dlya vuvody);
		out << name << " " << price << endl;
	}
	// get - distayemo zakruti polya;
	string getName()const { // const - ne vnosumo zminu v polya klasu; 
		return name;
	}
	double getPrice()const {
		return price;
	}
	// (set) dlya vstanovlennya svogo znachennya;
	void setName(string n1) {
		name = n1;
	}
	void setPrice(double price) {
		this -> price = price; //te same sho i v setName; this - vkazivnuk;
	}

};

//int main() {
//	const int n = 7;
//	Animal a[n];
//	ifstream in; // zchutannya z faylu
//	in.open("animal.txt");
//	for (int i = 0; i < n; i++) {
//		a[i].input(in);
//	}
//	Animal temp;
//	for (int i = 0; i < n; i++) {
//		for (int j = 0; j < n - 1 - i; j++) {
//			if (a[j].getName() > a[j + 1].getName()) {
//				temp = a[j];
//				a[j] = a[j + 1];
//				a[j + 1] = temp;
//			}
//		}
//	}
//	ofstream out("sorted(anim).txt");
//	for (int i = 0; i < n; i++) {
//		a[i].output(out);//yaksho na ekran, todi (cout);
//	}
//	for (int i = 0; i < n; i++) {
//		if (a[i].getPrice() >= 10.0 && a[i].getPrice() <= 50.0) {
//			a[i].output(cout);
//		}
//	}
//	double sum = 0;
//	for (int i = 0; i < n; i++) {
//		if (a[i].getName()[0] == 'a') {// [0] - ze persha litera
//			sum += a[i].getPrice();
//		}
//	}
//	cout << "sum = " << sum << endl;
//	double price; // pereozinka vartosti tvarunu; zmenshutu vartist na 10%;
//	for (int i = 0; i < n; i++) {
//		price = a[i].getPrice();
//		if (price >= 500) {
//			price = price - price * 10 / 100;
//			a[i].setPrice(price);
//		}
//	}
//	for (int i = 0; i < n; i++) {
//		a[i].output(cout);//yaksho na ekran, todi (cout);
//	}
//	in.close();
//	out.close();
//	system("pause");
//	return 0;
//}

 //dano masuv trukytnukiv, posortuvatu ich za zrostannyam plosh, i vuvestu rivnostoronni trukutnuku vkazanogo kolyoru;

class Triangle {
private:
	double a, b, c;
	string colour;
public:
	Triangle() :a(0), b(0), c(0), colour("") {}
	void input() {
		cin >> a >> b >> c >> colour;
	}
	void output() {
		cout << a << " " << b << " " << c << " " << colour << endl;
	}
	double square() {
		double p = (a + b + c) / 2;
		return sqrt(p * (p - a) * (p - b) * (p - c));
	}
	double per() {
		return a + b + c;
	}
	string getColour()const {
		return colour;
	}
	bool isEqual() {
		return a == b && a == c;
	}
};

void sort(Triangle* a, int n) {
	Triangle temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (a[j].square() > a[j + 1].square()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void print1(Triangle* a, int n, string colour) {
	for (int i = 0; i < n; i++) {
		if (a[i].isEqual() && a[i].getColour() == colour) {
			a[i].output();
		}
	}
}

//int main() {
//	int n;
//	cin >> n;
//	Triangle* a = new Triangle[n];
//	for (int i = 0; i < n; i++) {
//		a[i].input();
//	}
//	sort(a, n);
//	for (int i = 0; i < n; i++) {
//		a[i].output();
//		cout << "Square = " << a[i].square() << endl;
//	}
//	string colour;
//	cin >> colour;
//	print(a, n, colour);
//	delete[]a;
//	system("pause");
//	return 0;
//}


class Round {
private:
	double x;
	double y;
	double r;
	string colour;
public:
	Round() {
		x = 0;
		y = 0; 
		r = 0;
		colour = "";
	}
	Round(double x1, double y1, double r1, string colour1) {
		x = x1;
		y = y1; 
		r = r1;
		colour = colour1;
	}
	void input(ifstream& in) {
		in >> x >> y >> r >> colour;
	}
	double square() {
		double s;
		s = 3.14 * pow(r, 2);
		return s;
	}
	bool firstquater() {
		if (x - r >= 0 && y - r >= 0) {
			return true;
		}
		else return false;
	}
	double length() {
		double l;
		l = 2 * 3.14 * r;
		return l;
	}
	string getColour()const {
		return colour;
	}
	void output(ostream& out) {
		out << x << " " << y << " " << r << " " << square() << " " << colour << endl;
	}
	void print() {
		cout << x << " " << y << " " << r << " " << square() << " " << colour << endl;
	}
};

void sort(Round* a, int n) {
	Round temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].square() > a[j + 1].square()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void exam(Round* a, string colour, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].firstquater() && a[i].getColour() == colour) {
			a[i].print();
		}
	}
}

void delete1(Round* a, double l, int n) {
	for (int i = 0; i < n; i++) {
		if (a[i].length() > l) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}
}

//int main() {
//	int n;
//	ifstream in;
//	in.open("circle.txt");
//	in >> n;
//	Round* a = new Round[n];
//	for (int i = 0; i < n; i++) {
//		a[i].input(in);
//	}
//	in.close();
//	sort(a, n);
//	ofstream out("sort(triangl).txt");
//	for (int i = 0; i < n; i++) {
//		a[i].output(out);
//	}
//	string colour;
//	cin >> colour;
//	exam(a, colour, n);
//	double l;
//	cin >> l;
//	for (int i = 0; i < n; i++) {
//		if (a[i].length() > l) {
//			for (int j = i; j < n - 1; j++) {
//				a[j] = a[j + 1];
//			}
//			n--;
//			i--;
//		}
//	}
//	cout << endl;
//	for (int i = 0; i < n; i++) {
//		a[i].print();
//	}
//	out.close();
//	system("pause");
//	return 0;
//}

// ctvorutu tun odnovumirnuy masuv diysnuch chusel
//napusatu tru konstuktoru, metodu vvodu vuvodu, znachodzennya scalaru, poshuk max elementu.
//posortuvatu za zrostannyam, spadannyam, zrostannyam sumu zyfer elementiv.

class Mass {
private:
	int n;
	int* a;
public:
	Mass() {
		int n = 0;
		a = NULL;
	}
	Mass(int n1) {
		n = n1;
		a = new int[n];
	}
	void input(istream& in) {
		for (int i = 0; i < n; i++) {
			in >> a[i];
		}
	}
	void output(ostream& out) {
		for (int i = 0; i < n; i++) {
			out << a[i] << " ";
		}
	}
	int maxel() {
		int max = a[0];
		for (int i = 0; i < n; i++) {
			if (a[i] > max) {
				max = a[i];

			}
		}
		return max;
	}
	int scalar(Mass& b) {
		int s = 0;
		for (int i = 0; i < n; i++) {
			s += a[i] * b.a[i];
		}
		return s;
	}
	void sort() {
		int temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (a[j] < a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}
	void sort2(bool(*pf)(int, int)) {
		int temp;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n - 1; j++) {
				if (a[j] < a[j + 1]) {
					temp = a[j];
					a[j] = a[j + 1];
					a[j + 1] = temp;
				}
			}
		}
	}

};

bool less(int x, int y) {
	return x < y;
}

bool greater(int x, int y) {
	return x > y;
}


//int main() {
//	int n;
//	ifstream in;
//	in.open("mass.txt");
//	in >> n;
//	Mass a(n);
//	a.input(in);
//	Mass b(n);
//	b.input(in);
//	a.sort();
//	a.output(cout);
//	cout << endl;
//	cout << b.scalar(a);
//	cout << endl;
//	cout << a.maxel();
//	cout << endl;
//	system("pause");
//	return 0;
//
//}

///створити тип товар
//назва виробник ціна
//без конструкторів копіювання - простіше
//дано масив товарів
//посортувати товари за назвою
//знайти виробника вказаного товару з найнижчою ціною.
//н.п.молокія, альма - віта...

class Goods {
private:
	string name;
	string firm;
	double price;
public:
	Goods() {
		name = " ";
		firm = " ";
		price = 0;
	}
	Goods(string name, string firm, double price) {
		this->name = name;
		this->firm = firm;
		this->price = price;
	}
	void input(istream& in) {
		in >> name >> firm >> price;
	}
	void output(ostream& out) {
		out << name << " " << firm << " " << price << endl;
	}
	string getName()const {
		return name;
	}
	double getPrice()const {
		return price;
	}
	void print() {
		cout << name << " " << firm << " " << price << endl;
	}
};

void sort(Goods* a, int n) {
	Goods temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].getName() > a[j + 1].getName()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}


Goods* minprice(Goods* a, int n, int& k) {
	Goods min;
	Goods* b = new Goods[n];
	min = a[0];
	for (int i = 0; i < n; i++) {
		if (a[i].getPrice() < min.getPrice()) {
			min = a[i];
		}
	}
	for (int i = 0; i < n; i++) { // vuvestu vsi tovatu z min zinoyu;
		if (min.getPrice() == a[i].getPrice()) {
			b[k] = a[i];
			k++;
		}
	}

	return b;
}

//int main() {
//	int n;
//	ifstream in;
//	in.open("goods.txt");
//	in >> n;
//	Goods* a = new Goods[n];
//	for (int i = 0; i < n; i++) {
//		a[i].input(in);
//	}
//	in.close();
//	sort(a, n);
//	ofstream out("sorted(goods).txt");
//	for (int i = 0; i < n; i++) {
//		a[i].output(out);
//	}
//	int k = 0;
//	Goods* b = minprice(a, n, k);
//	for (int i = 0; i < k; i++) {
//		b[i].print();
//	}
//	out.close();
//	system("pause");
//	return 0;
//}


class Books {
private:
	string name;
	string author;
	double price;
public:
	Books() {
		string name = " ";
		string author = " ";
		double price = 0;
	}
	Books(string name, string author, double price) {
		this->name = name;
		this->author = author;
		this->price = price;
	}
	void input(istream& in) {
		in >> name >> author >> price;
	}
	void output(ostream& out) {
		out << name << " " << author << " " << price << endl;
	}
	string getAuthor()const {
		return author;
	}
	string getName()const {
		return name;
	}
	double setPrice(double price) {
		this->price = price;
	}
	double getPrice()const {
		return price;
	}
	void print(ostream& out) {
		out << name;
	}
};

void sort(Books* a, int n) {
	Books temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].getAuthor() > a[j + 1].getAuthor()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void compare(Books* books, int n, ostream& out, int min, int max) {
	for (int i = 0; i < n; i++) {
		if (books[i].getPrice() >= min && books[i].getPrice() <= max) {
			books[i].print(out);
		}
	}
}

int sum(Books* book, int n, string author) {
	int sum = 0;
	for (int i = 0; i < n; i++) {
		if (book[i].getAuthor() == author) {
			sum += book[i].getPrice();
		}
	}
	return sum;
}

void book(Books* book, int n, string name, ostream& out) {
	int min = 0;
	for (int i = 0; i < n; i++) {
		if (book[i].getName() == name) {
			if (book[i].getPrice() < min) {
				min = book[i].getPrice();
			}
		}
	}
	out << name << " " << min << endl;
}

void arufmet(Books* book, int n, string name, ostream& out) {
	int sum = 0;
	int k = 0;
	for (int i = 0; i < n; i++) {
		if (book[i].getName() == name) {
			sum += book[i].getPrice();
			k++;
		}
	}
	out << name << " " << sum / k << endl;
}
 
Books* new_arr(Books* book, int n, int& k) {
	Books* b = new Books[n];
	for (int i = 0; i < n; i++) {
		Books max = book[i];
		for (int j = i + 1; j < n; j++) {
			if (book[i].getAuthor() == book[j].getAuthor()) {
				if (book[j].getPrice() >= max.getPrice()) {
					max = book[j];
				}
			}
		}
		bool flag = false;
		for (int l = 0; l < k; l++) {
			if (b[l].getAuthor() == max.getAuthor()) {
				flag = true;
			}
		}
		if (!flag) {
			b[k] = max;
			k++;
		}
	}
	return b;
}

int main() {
	int n;
	ifstream in("books.txt");
	in >> n;
	Books* books = new Books[n];
	for (int i = 0; i < n; i++) {
		books[i].input(in);
	}
	in.close();
	ofstream out("results.txt");
	out << "First task: " << endl;
	for (int i = 0; i < n; i++) {
		books[i].output(out);
	}
	out << endl;
	sort(books, n);
	for (int i = 0; i < n; i++) {
		books[i].output(out);
	}
	out << endl << "Second task: " << endl;
	int min = 50;
	int max = 100;
	compare(books, n, out, min, max);
	out << endl;
	string author;
	cin >> author;
	out << sum(books, n, author);
	out << endl << "Third task: " << endl;
	string name;
	cin >> name;
	book(books, n, name, out);
	out << endl;
	arufmet(books, n, name, out);
	out << endl << "Fourth task: " << endl;
	int k = 0;
	Books* new_array = new_arr(books, n, k);
	for (int i = 0; i < k; i++) {
		new_array[i].output(out);
	}
	out.close();
	system("pause");
	return 0;
}



