#include <iostream>
#include <fstream>
#include <string>
using namespace std;
class Patient {
private:
	string surname, sick;
	int age, count;
public:
	Patient() : surname(""), age(0), sick(""), count(0) {}
	Patient(string su, int ag, string si, int co) : surname(su), age(ag), sick(si), count(co) {}
	Patient(const Patient& other) {
		surname = other.surname;
		age = other.age;
		sick = other.sick;
		count = other.count;
	}
	string getSick() {
		return sick;
	}
	string getPatient() {
		return surname;
	}
	friend istream& operator>>(istream& in, Patient& other) {
		in >> other.surname >> other.age >> other.sick >> other.count;
		return in;
	}
	friend ostream& operator<<(ostream& out, Patient& other) {
		out << other.surname << " " << other.age << " " << other.sick << " " << other.count << endl;
		return out;
	}
};

void sort(Patient* mass, int n) {
	Patient temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1 - i; j++) {
			if (mass[j].getSick() > mass[j + 1].getSick()) {
				temp = mass[j];
				mass[j] = mass[j + 1];
				mass[j + 1] = temp;
			}
		}
	}
}

void print(Patient* mass, int n, string sick, ostream& out) {
	string pat = "";
	int k = 0;
	for (int i = 0; i < n; i++) {
		pat = mass[i].getPatient();
		int count = 1;
		k = 0;
		for (int j = i + 1; j < n; j++) {
			if (mass[i].getSick() == mass[j].getSick()) {
				k++;
				pat += " " + mass[j].getPatient();
				count++;
			}
		}
		out << mass[i].getSick() << " " << pat << " " << count << endl;
		i += k;
	}
}

int main() {
	ifstream in("Text.txt");
	int n;
	in >> n;
	Patient* arr = new Patient[n];
	for (int i = 0; i < n; i++) {
		in >> arr[i];
	}
	ofstream out("result.txt");
	for (int i = 0; i < n; i++) {
		out << arr[i];
	}
	out << "------------------" << endl;
	sort(arr, n);
	out << endl;
	string sick;
	cin >> sick;
	print(arr, n, sick, out);
	out << endl;
	in.close();
	out.close();
	system("pause");
	return 0;
}