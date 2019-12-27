#include <iostream>
#include<fstream>
using namespace std;

//Stvorutu basovuy tup Vudannya, ta pochidni tupu: knuzka, zurnal, gazeta.
//Z parametramu(nazva, zasnosvnuk, rik vudannya),
//Knuzka(avtor, vudavnuztvo);
//Zurnal(genre, perioduchnist),
//Gazeta(Zasnovnuk, misze vudannya).
//Dano masuv Vudan'.
//Posortuvatu za rokom vudannya.
//Znaytu Knuzku vkazanogo avtora;
//Znaytu zurnal z maksumalnoyu perioduchnistyu.

class Publisher {
protected:
	string name;
	int year;
public:
	Publisher() {
		name = "";
		year = 0;
	}
	Publisher(string n, int y): name(n), year(y){}
	
	virtual void input(istream& in) {
		in >> name >> year;
	}
	 virtual void output(ostream& out) {
		out << name << " " << year << " ";
	}
	 bool operator>(Publisher& a) {
		 return year > a.year;
	}
	string getName()const {
		return name;
	}
	int getYear()const {
		return year;
	}
};

class Book : public Publisher {
private:
	string author;
	string publish;
public:
	Book(): Publisher(), author(""), publish(""){}
	Book(string n, int y, string a, string p): Publisher(n,y), author(a), publish(p){}
	void input(istream& in){
		Publisher::input(in);
		in >> author >> publish;
	}
	void output(ostream& out) {
		Publisher::output(out);
		out << author << " " << publish << " ";
	}
	string getAuthor() {
		return author;
	}
	string getPublish() {
		return publish;
	}
};

class Magazine: public Publisher {
private:
	string genre;
	int period;
public:
	Magazine(): Publisher(), genre(""), period(0){}
	Magazine(string n, int y, string g, int p): Publisher(n,y), genre(g), period(p){}
	void input(istream& in) {
		in >> name >> year >> genre >> period;
	}
	void output(ostream& out) {
		out << name << " " << year << " " << genre << " " << period << endl;
	}
	string getGenre() {
		return genre;
	}
	int getPeriod() {
		return period;
	}
};

class News : public Publisher {
private:
	string founder;
	string place;
public:
	News(): Publisher(), founder(""), place(""){}
	News(string n, int y, string f, string p):Publisher(n,y), founder(f), place(p){}
	void input(istream& in) {
		in >> name >> year >> founder >> place;

	}
	void output(ostream& out) {
		out << name << " " << year << " " << founder << " " << place << endl;
	}
	string getFounder() {
		return founder;
	}
	string getPlace() {
		return place;
	}

};

void sort(Publisher** a, int n) {
	Publisher* temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j]->getYear() > a[j + 1]->getYear()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void print(Publisher** a, int n, string author, ostream& out) {
	for (int i = 0; i < n; i++) {
		Book* temp;
		temp = dynamic_cast<Book*>(a[i]);
		if (temp != nullptr) {
			temp = (Book*)a[i];
			if (temp->getAuthor() == author) {
				out << temp->getName() << endl;
			}
		}
	}
	out << endl;
}

int main() {
	int n;
	ifstream in("publisher.txt");
	in >> n;
	Publisher** a = new Publisher * [n];// masuv vkazivnukiv;
	int type;
	for (int i = 0; i < n; i++) {
		in >> type;
		switch (type) {
		case 0:a[i] = new Book;
			break;
			case 1:a[i] = new News;
				break;
			case 2:a[i] = new Magazine;
				a[i]->input(in);
			}
		a[i]->input(in);

	}
	sort(a, n);
	for (int i = 0; i < n; i++) {
		a[i]->output(cout);
		cout << endl;
	}
	string author;
	cin >> author;
	print(a, n, author, cout);
	for (int i = 0; i < n; i++) {
		delete a[i];
	}
	delete[]a;
	in.close();
	system("pause");
	return 0;
}