#include <iostream>
#include <string>
#include <cmath>
#include <fstream>
#define _USE_MATH_DEFINES
using namespace std;

///*Створити тип історія хвороби пацієнта(карточка).
//Параметри:Прізвище, вік, масив захворювань
	//Створити функції : Сортування за віком пацієнтів, вивід всіх пацєнтів у формі : призвіще і захворювання на яке
	//він найчастіше хворів(Приклад : Іванов ОРЗ), пошук найстаршого пацієнта, який переніс вказане захворювання.* /

class History {
private:
	string name;
	int age, count;
	string* ill;
public:
	History() {
		string name = "";
		int age = 0;
		int count = 0;
		ill = (NULL);
	}
	History(string name, int age, string* ill, int count) {
		this->name = name;
		this->age = age;
		this->count = count;
		this->ill = new string[count];
		for (int i = 0; i < count; i++) {
			this->ill[i] = ill[i];
		}
	}
	History(const History& a);
	History& operator=(const History& a);
	void input(istream& in) {
		in >> name >> age >> count;
		ill = new string[count];
		for (int i = 0; i < count; i++) {
			in >> ill[i];
		}
	}
	void output(ostream& out) {
		out << name << " " << age << " ";
		for (int i = 0; i < count; i++) {
			out << ill[i] << " ";
		}
		out << endl;
	}
	string getName()const {
		return name;
	}
	bool operator>(const History& a) {
		return age > a.age;
	}
	int getAge()const {
		return age;
	}
	string max_ill() {
		string max;
		string illness;
		int max_k = 0;
		int k = 0;
		for (int i = 0; i < count; i++) {
			illness = ill[i];
			k = 1;
			for(int j = i + 1; j < count; j++) {
				if (ill[j] == illness) {
					k++;
				}
			}
			if (k > max_k) {
				max_k = k;
				max = illness;
			}
		}
		return max;
	}
	~History() {
		delete[]ill;
	}
	bool isIll(string s) {
		for (int i = 0; i < count; i++) {
			if (ill[i] == s) {
				return true;
			}
		}
		return false;
	}
	friend istream& operator>>(istream& in, History& a) {
		in >> a.name >> a.age >> a.count;
		a.ill = new string[a.count];
		for (int i = 0; i < a.count; i++) {
			in >> a.ill[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, History& a) {
		out << a.name << " " << a.age <<" ";
		for (int i = 0; i < a.count; i++) {
			out << a.ill[i] << " ";
		}
		out << endl;
		return out;
	}
};

History::History(const History& a) {
	if (this != &a) {
		name = a.name;
		age = a.age;
		count = a.count;
		ill = new string[count];
		for (int i = 0; i < count; i++) {
			ill[i] = a.ill[i];
		}
	}
}


History& History ::operator=(const History& a) { 
	if (this != &a) { 
		delete[]ill;
		name = a.name;
		age = a.age;
		count = a.count;
		ill = new string[count];
		for (int i = 0; i < count; i++) {
			ill[i] = a.ill[i];
		}
	}
	return*this;
}


void sort(History* a, int n) {
	History temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++){
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void print(History* a, int n, ostream& out) {
	for (int i = 0; i < n; i++) {
		out << a[i].getName() << " - " << a[i].max_ill() << endl;
	}
}

History human(History* a, int n, string ill) {
	History oldest;
	for (int i = 0; i < n; i++) {
		if (a[i].isIll(ill) && a[i].getAge() > oldest.getAge()) {
			oldest = a[i];
		}
	}
	return oldest;
}

int main() {
	int n;
	ifstream in("history.txt");
	in >> n;
	History* a = new History[n];
	for (int i = 0; i < n; i++) {
		in >> a[i];
		/*a[i].input(in);*/
	}
	sort(a, n);
	ofstream out("result.txt");
	for (int i = 0; i < n; i++) {
		/*a[i].output(out);*/
		out << a[i];
	}
	print(a, n, out);
	string s; //Zachvoryuvannya;
	cin >> s;
	History max = human(a, n, s);
	max.output(cout);
	in.close();
	out.close();
	delete[]a;
	system("pause");
	return 0;
}


 // Perenavantazennya operatoriv
//           funcziyi chlena klasu           friend(ne mayut vkazivnuka this)
// Unarni    complex operator-()             friend complex operator-(complex)
// Binarni   complex operator*(complex)      friend complex operator*(complex, complex)
//complex a, b; c = a.operator*(b); c = a*b;  complex a, b; (c = operator*(a, b);)===(c = a * b)(tak pushut')
//operatoru vvedenya i vuvedennya pushemo yak perenavantazennya operatora friend;

class Drib {
private:
	int ch;
	int zn;
public:
	Drib(): ch(0), zn(1){} // znamennuk ne dorivnyuye 0
	Drib(int c, int z):ch(c),zn(z){}
	Drib(const Drib& a): ch(a.ch),zn(a.zn){}
	~Drib(){}
	friend istream& operator>>(istream& in, Drib& a) {
		in >> a.ch >> a.zn;
		return in;
	}
	friend ostream& operator<<(ostream& out, Drib& a) {
		out << a.ch << " / " << a.zn;
		return out;
	}
	void scorochennya() {
		int max = ch > zn ? ch : zn;//pereviryayemo chu chuselnuk bilshuy za znamennuk; yaksho tak, to beremo chuselnuk, yaksho nit to beremo znamennuk;
		int min = ch < zn ? ch : zn;
		for (int d = min; d > 1; d--) {
			if (ch % d == 0 && zn % d == 0) {
				ch /= d; zn /= d;
			}
		}
	}
	Drib operator+(Drib& a) {
		Drib res;
		res.ch = ch * a.zn + a.ch * zn;
		res.zn = zn * a.zn;
		res.scorochennya();
		return res;
	}
	Drib operator*(Drib& a) {
		Drib res;
		res.ch = ch * a.ch;
		res.zn = zn * a.zn;
		res.scorochennya();
		return res;
	}
	Drib operator/(Drib& a) {
		Drib res;
		res.ch = ch * a.zn;
		res.zn = zn * a.ch;
		res.scorochennya();
		return res;
	}
	Drib& operator=(const Drib& a) {
		if (this != &a) {
			ch = a.ch;
			zn = a.zn;
		}
		return*this;
	}// constantne posulannya na obyekt kalsu(tak yak v konstructori kopiyuvannya
	bool operator>(Drib& a) {
		return ((double)ch) / zn > ((double)a.ch) / a.zn;// (double) - ze operator zvedennya tupy;
	}
};

//Dano 2 vectoru drobiv 1) znaytu scalar; 2) posortuvatu 1 masuv za zrostannyam; 3) znaytu max element 2 masuvu;

void sort(Drib* a, int n) {
	Drib temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j] > a[j + 1]) {//operator > ye perrenavantazenuy;
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void input(Drib* a, int n) {
	for (int i = 0; i < n; i++) {
		cin >> a[i];
	}
}

void output(Drib* a, int n) {
	for (int i = 0; i < n; i++) {
		cout << a[i] << " ";
		cout << endl;
	}
}

Drib scalar(Drib* a, Drib* b, int n) {
	Drib s;
	Drib m;

	for (int i = 0; i < n; i++) {
		m = a[i] * b[i];
		s = s + m;
	}
	return s;
}

Drib max(Drib* a, int n) {
	Drib max;
	for (int i = 0; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max;
}

int main() {
	int n;
	cin >> n;
	Drib* a = new Drib[n];
	Drib* b = new Drib[n];
	input(a, n);
	input(b, n);
	Drib s = scalar(a, b, n);
	cout << "s= " << s << endl;
	sort(a, n);
	output(a, n);
	Drib d = max(b, n);
	cout << " d = " << d << endl;
	delete[]a;
	delete[]b;
	system("pause");
	return 0;
}

// stvorutu tup vector diysnuch chusel.Perenavantazennya operatoriv, mnozennya, sortuvannya, max, mnozennya vectora na diysne chuslo; funcziya revers, remove if, unique; 