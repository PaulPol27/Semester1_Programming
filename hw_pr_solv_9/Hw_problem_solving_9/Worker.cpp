
#include <iostream>
#include <fstream>
using namespace std;

class Worker {
private:
	string sur;
	string pos;
	int stag;
public:
	Worker() {
		sur = "";
		pos = "";
		stag = 0;
	}
	Worker(string sur, string pos, int stag) {
		this->sur = sur;
		this->pos = pos;
		this->stag = stag;
	}
	Worker(const Worker& a) {
		sur = a.sur;
		pos = a.pos;
		stag = a.stag;
	}
	void input(istream& in) {
		in >> sur >> pos >> stag;
	}
	void output(ostream& out) {
		out << sur << " " << pos << " " << stag << " ";
	}
	string getPos() {
		return pos;
	}
	string getSur() {
		return sur;
	}
	int getStag() {
		return stag;
	}
	friend istream& operator>>(istream& in, Worker& a) {
		in >> a.sur >> a.pos >> a.stag;
		return in;
	}
	friend ostream& operator<<(ostream& out, Worker& a) {
		out << a.sur << " " << a.pos << " " << a.stag << " ";
		return out;
	}
};

void sort(Worker* a, int n, ostream& out) {
	Worker temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].getSur() > a[j + 1].getSur()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void print(Worker* a, int n, ostream& out) {
	int total_stag = 0;
	string total_pos = "";
	for (int i = 0; i < n; i++) {
		total_stag = a[i].getStag();
		int k = 0;
		total_pos = a[i].getPos();
		for (int j = i + 1; j < n; j++) {
			if (a[i].getSur() == a[j].getSur()) {
				k++;
				total_stag += a[j].getStag();
				total_pos += " "+a[j].getPos();
			}
		}
		out << a[i].getSur() << " " << total_stag << " " << total_pos << " " << endl;
		i += k;
	}
}

string min_stag(Worker* a, int n, string pos, ostream& out) {
	int min = INT_MAX;
	string name = "";
	for (int i = 0; i < n; i++) {
		if (a[i].getPos() == pos) {
			if (a[i].getStag() < min) {
				min = a[i].getStag();
				name = a[i].getSur();
			}
		}
	}
	return name;
}

void delete1(Worker*& a, int& n, string sur) {
	for (int i = 0; i < n; i++) {
		if (a[i].getSur() == sur) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}
}

int main() {
	int n;
	ifstream in("worker.txt");
	in >> n;
	Worker* a = new Worker[n];
	for (int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	ofstream out("result.txt");
	sort(a, n, out);
	out << "Sort: " << endl;
	for (int i = 0; i < n; i++) {
		out << a[i] << endl;
	}
	out << endl;
	out << "Total pos and stag: " << endl;
	print(a, n, out);
	out << endl;
	string pos;
	cin >> pos;
	out << "Min stag: ";
	out << min_stag(a, n, pos, out);
	out << endl;
	string sur;
	cin >> sur;
	out << "workers: " << endl;
	delete1(a, n, sur);
	for (int i = 0; i < n; i++) {
		out << a[i] << endl;
	}
	delete[]a;
	system("pause");
	return 0;
}

