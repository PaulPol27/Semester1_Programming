//#include <fstream>
//#include <iostream>
//using namespace std;
//int main() {    // Записати в зворотньому порядку
//  ifstream in("input.txt");
//  int k = 0, x;
//  while (!in.eof()) { // while( int >> x) { k++; } також допустимий запис
//    in >> x;
//    k++;
//  }
//  in.close();
//  in.open("input.txt");
//  int* a = new int[k];
//  for (int i = 0; i < k; i++) {
//    in >> a[i];
//  }
//  ofstream out("result.txt");
//  for (int i = k - 1; i >= 0; i--) {
//    out << a[i] << " ";
//  }
//  in.close();
//  out.close();
//}



//fstream inout;  Введення з допомогою fstream
//inout.open("text.txt", ios::in);
//ios::text;
//int x;
//inout >> x;
//
//. . . . . . . . . .
//
//inout.close();
//inout.open("text.txt", ios::out);
//inout << t;

//Створити тип студент, прізвище факультет і масив оцінок, посортувати студентів
//За успішністю від більшого до меншого і знайти факультет з максимальною середньою успішністю.
#include <fstream>
#include <iostream>
#include <string>
using namespace std;
class student {
private:
	string name, faculty;
	int* marks, n;
public:
	student() :name(""), faculty(""), marks(NULL), n(0) {}
	student(const student&);
	void input(istream& in);
	void output(ostream& out);
	double avarage();
	string getFaculty()const {
		return faculty;
	}
	~student() {
		delete[] marks;
	}
	student& operator=(const student& a) {
		if (this != &a) {
			delete[]marks;
			name = a.name;
			faculty = a.faculty;
			n = a.n;
			marks = new int[n];
			for (int i = 0; i < n; i++) {
				marks[i] = a.marks[i];
			}
		}
		return *this;
	}
};

student::student(const student& a) {
	if (this != &a) {
		name = a.name;
		faculty = a.faculty;
		n = a.n;
		marks = new int[n];
		for (int i = 0; i < n; i++) {
			marks[i] = a.marks[i];
		}
	}
}


void student::input(istream& in) {
	in >> name >> faculty >> n;
	marks = new int[n];
	for (int i = 0; i < n; i++) {
		in >> marks[i];
	}
}
void student::output(ostream& out) {
	out << name << " " << faculty << " " << avarage() << endl;
}
double student::avarage() {
	double s = 0;
	for (int i = 0; i < n; i++) {
		s += marks[i];
	}
	return s / n;
}

void sort(student* a, int n) {
	student temp;
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].avarage() < a[j + 1].avarage()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}


}

string maxUsp(student* a, int n) {
	string faculty, ftemp;
	double s, max = 0;
	int k;
	for (int i = 0; i < n; i++) {
		ftemp = a[i].getFaculty();
		s = a[i].avarage();
		k = 1;
		for (int j = i + 1; j < n; j++) {
			if (a[j].getFaculty() == ftemp) {
				s += a[j].avarage();
				k++;
			}
		}
		if (s / k > max) {
			max = s / k;
			faculty = ftemp;
		}
	}
	return faculty;
}

int main() {
	int n;
	ifstream in("student.txt");
	in >> n;
	student* a = new student[n];
	for (int i = 0; i < n; i++) {
		a[i].input(in);
	}
	sort(a, n);
	ofstream out("sorted.txt");
	for (int i = 0; i < n; i++) {
		a[i].output(out);
	}
	cout << maxUsp(a, n) << endl;
	delete[]a;
	in.close();
	out.close();
	system("pause");
	return 0;
}


// ctvorutu tun odnovumirnuy masuv diysnuch chusel
//napusatu tru konstuktoru, metodu vvodu vuvodu, znachodzennya scalaru, poshuk max elementu
//posortuvatu za zrostannyam, spadannyam, zrostannyam sumu zyfer elementiv.

class Mass {
private:
	int n;
	int* a;
public:
	Mass() {
		int n = 0;
		int* a = NULL;
	}
	Mass(){}
};
