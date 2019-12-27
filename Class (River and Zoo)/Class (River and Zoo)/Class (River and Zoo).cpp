#include <iostream>
#include <string>
#include <fstream>
using namespace std;

class River {
private:
	string name;
	int count;
	string* rivers;
	double* lenght;
public:
	River() {
		name = "";
		count = 0;
		rivers = (NULL);
		lenght = (NULL);
	}
	River(string name, int count, string* rivers, double* lenght) {
		this->name = name;
		this->count = count;
		this->rivers = new string[count];
		for (int i = 0; i < count; i++) {
			this->rivers[i] = rivers[i];
		} 
		this->lenght = new double[count];
		for (int i = 0; i < count; i++) {
			this->lenght[i] = lenght[i];
		}
	}
	void input(istream& in) {
		in >> name >> count;
		rivers = new string[count];
		for (int i = 0; i < count; i++) {
			in >> rivers[i];
		}
		lenght = new double[count];
		for (int i = 0; i < count; i++) {
			in >> lenght[i];
		}
	}
	void output(ostream& out) {
		out << name << " ";
		for (int i = 0; i < count; i++) {
			out << rivers[i] << " ";
		}
		out << endl;
		for (int i = 0; i < count; i++) {
			out << lenght[i] << " ";
		}
		out << endl;
	}
	River (const River& riv);
	River& operator=(const River& riv);
	~River() {
		delete[]rivers;
		delete[]lenght;
	}
	bool operator>(const River& a) {
		return count > a.count;
	}
	string getName() {
		return name;
	}
	string* getRivers() {
		return rivers;
	}
	double* getLenght() {
		return lenght;
	}
	int getCount() {
		return count;
	}
	friend istream& operator>>(istream& in, River& riv) {
		in >> riv.name >> riv.count;
		riv.rivers = new string[riv.count];
		for (int i = 0; i < riv.count; i++) {
			in >> riv.rivers[i];
		}
		riv.lenght = new double[riv.count];
		for (int i = 0; i < riv.count; i++) {
			in >> riv.lenght[i];
		}
		return in;
	}
	friend ostream& operator>>(ostream& out, River& riv) {
		out << riv.name << " ";
		for (int i = 0; i < riv.count; i++) {
			out << riv.rivers[i] << " ";
		}
		for (int i = 0; i < riv.count; i++) {
			out << riv.lenght[i] << " ";
		}
		return out;
	}
};

River::River(const River& a) {
	if (this != &a) {
		name = a.name;
		count = a.count;
		rivers = new string[count];
		for (int i = 0; i < count; i++) {
			rivers[i] = a.rivers[i];
		}
		lenght = new double[count];
		for (int i = 0; i < count; i++) {
			lenght[i] = a.lenght[i];
		}
	}
}

River& River :: operator=(const River& a) {
	if (this != &a) {
		delete[]rivers;
		delete[]lenght;
		name = a.name;
		count = a.count;
		rivers = new string[count];
		for (int i = 0; i < count; i++) {
			rivers[i] = a.rivers[i];
		}
		lenght = new double[count];
		for (int i = 0; i < count; i++) {
			lenght[i] = a.lenght[i];
		}
	}
	return*this;
}


string max_rivers(River* a, int n) {
	River max = a[0];
	for (int i = 1; i < n; i++) {
		if (a[i] > max) {
			max = a[i];
		}
	}
	return max.getName();
}
#pragma region er
void compare(River* riv, int n, string name, double lenght, ostream& out) {
	for (int i = 0; i < n; i++) {
		if (riv[i].getName() == name) {
			for (int j = 0; j < riv[i].getCount(); j++) {
				if (riv[i].getLenght()[j] > lenght) {
					out << riv[i].getRivers()[j] << " " << riv[i].getLenght()[j] << " ";
				}
			}
		}
	}
}


int main() {
	int n;
	ifstream in("rivers.txt");
	in >> n;
	River* riv = new River[n];
	for (int i = 0; i < n; i++) {
		in >> riv[i];
	}
	in.close();
	ofstream out("results.txt");
	out << "Max Rivers: " << max_rivers(riv, n);
	out << endl;
	string name;
	cin >> name;
	double lenght;
	cin >> lenght;
	compare(riv, n, name, lenght, out);
	out.close();
	system("pause");
	return 0;
}

#pragma endregion
class Zoo {
private:
	string name;
	int age;
	int count;
	string* animals;
	int* number;
public:
	Zoo() {
		name = "";
		age = 0;
		count = 0;
		animals = (NULL);
		number = (NULL);
	}
	Zoo(string name, int age, int count, string* animals, int* number) {
		this->name = name;
		this->age = age;
		this->count = count;
		this->animals = new string[count];
		for (int i = 0; i < count; i++) {
			this->animals[i] = animals[i];
		}
		this->number = new int[count];
		for (int i = 0; i < count; i++) {
			this->number[i] = number[i];
		}
	}
	void input(istream& in) {
		in >> name >> age >> count;
		animals = new string[count];
		for (int i = 0; i < count; i++) {
			in >> animals[i];
		}
		number = new int[count];
		for (int i = 0; i < count; i++) {
			in >> number[i];
		}
	}
	void output(ostream& out) {
		out << name << " " << age << " ";
		for (int i = 0; i < count; i++) {
			out << animals[i] << " ";
		}
		for (int i = 0; i < count; i++) {
			out << number[i] << " ";
		}
	}
	Zoo(const Zoo& a);
	Zoo& operator=(const Zoo& a);
	~Zoo() {
		delete[]animals;
		delete[]number;
	}
	string getName() {
		return name;
	}
	int getAge() {
		return age;
	}
	string* getAnimals() {
		return animals;
	}
	string getAnimal(int k) {
		return animals[k];
	}
	int* getNumber() {
		return number;
	}
	int getCount() {
		return count;
	}
	friend istream& operator>>(istream& in, Zoo& a) {
		in >> a.name >> a.age >> a.count;
		a.animals = new string[a.count];
		for (int i = 0; i < a.count; i++) {
			in >> a.animals[i];
		}
		a.number = new int[a.count];
		for (int i = 0; i < a.count; i++) {
			in >> a.number[i];
		}
		return in;
	}
	friend ostream& operator<<(ostream& out, Zoo& a) {
		out << a.name << " " << a.age << " ";
		for (int i = 0; i < a.count; i++) {
			out << a.animals[i] << " ";
		}
		for (int i = 0; i < a.count; i++) {
			out << a.number[i] << " ";
		}
		return out;
	}
};
Zoo::Zoo(const Zoo& a) {
	if (this != &a) {
		name = a.name;
		age = a.age;
		count = a.count;
		animals = new string[count];
		for (int i = 0; i < count; i++) {
			animals[i] = a.animals[i];
		}
		number = new int[count];
		for (int i = 0; i < count; i++) {
			number[i] = a.number[i];
		}
	}
}
Zoo& Zoo::operator=(const Zoo& a) {
	if (this != &a) {
		delete[]animals;
		delete[]number;
		name = a.name;
		age = a.age;
		count = a.count;
		animals = new string[count];
		for (int i = 0; i < count; i++) {
			animals[i] = a.animals[i];
		}
		number = new int[count];
		for (int i = 0; i < count; i++) {
			number[i] = a.number[i];
		}
	}
	return*this;
}

string max_an(Zoo* a, int n, string animal) {
	Zoo max = a[0];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < a[i].getCount(); j++) {
			if (a[i].getAnimal(j) == animal) {
				if (a[i].getNumber()[j] > max.getNumber()[j]) {
					max = a[i];
				}
			}
		}
	}
	return max.getName();
}

void all_animals(Zoo* a, int n, string zoo, ostream& out) {
	for (int i = 0; i < n; i++) {
		if (a[i].getName() == zoo) {
			for (int j = 0; j < a[i].getCount(); j++) {
				out << a[i].getAnimals()[j] << " -- " << a[i].getNumber()[j] << endl;
			}
		}
	}
}

void sort(Zoo* a, int n) {
	Zoo temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].getAge() > a[j + 1].getAge()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

int main() {
	int n;
	ifstream in("zoo.txt");
	in >> n;
	Zoo* a = new Zoo[n];
	for (int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	ofstream out("resultszoo.txt");
	string animal;
	cin >> animal;
	out << "Max Zoo is: " << max_an(a, n, animal);
	out << endl;
	string zoo;
	cin >> zoo;
	all_animals(a, n, zoo, out);
	out << endl;
	sort(a, n);
	for (int i = 0; i < n; i++) {
		out << a[i];
	}
	out.close();
	system("pause");
	return 0;
}
