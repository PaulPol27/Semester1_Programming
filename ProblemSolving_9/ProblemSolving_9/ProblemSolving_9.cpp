#include<iostream>
#include<fstream>
using namespace std;

class Matrix {
private:
	double** mass;
	int n;
	int m;
public:
	Matrix() {
		int n = 0; 
		int m = 0;
		mass = (NULL);
	}
	Matrix(int m1, int n1) {
		m = m1;
		n = n1;
		mass = new double* [m];
		for (int i = 0; i < m; i++) {
			mass[i] = new double[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mass[i][j] = 0;
			}
		}
	}
	Matrix(const Matrix& a);
	Matrix& operator=(const Matrix& a);
	~Matrix() {
		for (int i = 0; i < m; i++) {
			delete[]mass[i];
		}
		delete[]mass;
	}
	friend istream& operator>>(istream& in, Matrix& a) {
		for (int i = 0; i < a.m; i++) {
			for (int j = 0; j < a.n; j++) {
				in >> a.mass[i][j];
			}
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Matrix& a) {
		for (int i = 0; i < a.m; i++) {
			for (int j = 0; j < a.n; j++) {
				out << a.mass[i][j] << " ";
			}
			out << endl;
		}
		return out;
	}
	Matrix operator+(const Matrix& a) {
		Matrix res(m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				res.mass[i][j] = mass[i][j] + a.mass[i][j];
			}
		}
		return res;
	}
	Matrix operator*(const Matrix& a) {
		Matrix res(m, a.n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < a.n; j++) {
				for (int l = 0; l < a.m; l++) {
					res.mass[i][j] += mass[i][l] * a.mass[l][j];
				}
			}
		}
		return res;
	}
	Matrix operator*(double x) {
		Matrix res(m, n);
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				res.mass[i][j] = mass[i][j] * x;
			}
		}
		return res;
	}
	double norma() {
		double s = 0;
		double max;
		for (int i = 0; i < m; i++) {
			max = mass[i][0];
			for (int j = 0; j < n; j++) {
				if (mass[i][j] > max) {
					max = mass[i][j];
				}
			}
			s += max;
		}
		return s;
	}
};

Matrix::Matrix(const Matrix& a) {
	if (this != &a) {
		m = a.m;
		n = a.n;
		mass = new double* [m];
		for (int i = 0; i < m; i++) {
			mass[i] = new double[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mass[i][j] = a.mass[i][j];
			}
		}
	}
}

Matrix& Matrix::operator=(const Matrix& a) {
	if (this != &a) {
		for (int i = 0; i < m; i++) {
			delete[]mass[i];
		}
		delete[]mass;
		m = a.m;
		n = a.n;
		mass = new double* [m];
		for (int i = 0; i < m; i++) {
			mass[i] = new double[n];
		}
		for (int i = 0; i < m; i++) {
			for (int j = 0; j < n; j++) {
				mass[i][j] = a.mass[i][j];
			}
		}
	}
	return*this;
}

//int main() {
//	int m;
//	int n;
//	cin >> m >> n;
//	Matrix a(m, n);
//	Matrix b(m, n);
//	Matrix c(m, n);
//	cin >> a >> b;
//	c = a + b;
//	cout << c;
//	cout << endl;
//	c = a * b;
//	cout << c << endl;
//	cout << endl;
//	cout << "Norma = " << a.norma() << endl;
//	system("pause");
//	return 0;
//} 

// ctvorutu tup lyuduna: imya i vik;
// pochidnuy : student facultet i uspishnist;
//posortuvatu za imenem

class Human {
protected:
	string name;
	int age;
public:
	Human() {
		name = " ";
		age = 0;
	}
	Human(string name, int age) {
		this->name = name;
		this->age = age;
	}
	void input() {
		cin >> name >> age;
	}
	void output() {
		cout << name << " " << age << " ";
	} 
	bool operator>(Human& a) {
		return name > a.name;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
};

class Student : public Human {
private:
	string faculty;
	double succ;
public:
	Student():Human(), faculty(""), succ(0){}
	Student(string name, int age, string faculty, double succ) :Human(name, age) {
		this->faculty = faculty;
		this->succ = succ;
	}
	void input() {
		Human::input();// vvodut imya i vik;
		cin >> faculty >> succ;
	}
	void output() {
		Human::output();
		cout << faculty << " " << succ << endl;
	}
	string getFaculty() {
		return faculty;
	}
	double getSucc() {
		return succ;
	}
};

int main() {
	int n;
	cin >> n;
	Student* a = new Student[n];
	for (int i = 0; i < n; i++) {
		a[i].input();
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			Student temp;
			if (a[j] > a[j + 1]) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
	for (int i = 0; i < n; i++) {
		a[i].output();
	}
	string faculty;
	cin >> faculty;
	for (int i = 0; i < n; i++) {
		if (a[i].getFaculty() == faculty) {
			a[i].output();
		}
	}
	delete[]a;
	system("pause");
	return 0;
}