//Створити тип транспортний маршрут(початкова станція, кінцева станція, протяжність маршруту в км, вартість).Станції можуть повторюватися.В класі крім необхідних методів визначити конструктор за замовченням та конструктор копіювання, функції введення та виведення.Дані містяться у файлі.Створити масив маршрутів.
//1.	Посортувати їх за початк.станцією.Вивести унікальні маршрути у форматі : початкова –  кінцева станція – середня протяжність – середня вартість.
//2.	Знайти маршрут, який починаються в станції Х з мінімальною протяжністю.
//3.	Змоделювати процес вилучення маршрутів з мінімальною ефективністю. (ефективність – вартість на 1 км)


#include <iostream>
#include <fstream>
using namespace std;

class Distance {
private:
	string init;
	string final;
	int leng;
	int price;
public:
	Distance() {
		init = "";
		final = "";
		leng = 0;
		price = 0;
	}
	Distance(string init, string final, int leng, int price) {
		this->init = init;
		this->final = final;
		this->leng = leng;
		this->price = price;
	}
	Distance(const Distance& a) {
		init = a.init;
		final = a.final;
		leng = a.leng;
		price = a.price;
	}
	string getInit() {
		return init;
	}
	string getFinal() {
		return final;
	}
	int getLeng() {
		return leng;
	}
	int getPrice() {
		return price;
	}
	friend istream& operator>>(istream& in, Distance& a) {
		in >> a.init >> a.final >> a.leng >> a.price;
		return in;
	}
	friend ostream& operator<<(ostream& out, Distance& a) {
		out << a.init << " " << a.final << " " << a.leng << " " << a.price << " ";
		return out;
	}
};

void sort(Distance* a, int n) {
	Distance temp;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n - 1; j++) {
			if (a[j].getInit() > a[j + 1].getInit()) {
				temp = a[j];
				a[j] = a[j + 1];
				a[j + 1] = temp;
			}
		}
	}
}

void unique(Distance* a, int n, ostream& out) {
	int sum1 = 0;
	int sum2 = 0;
	int k = 1;
	int l = 1;
	for (int i = 0; i < n; i++) {
		int h = 0;
		for (int j = i + 1; j < n; j++) {
			if (a[i].getInit() == a[j].getInit() && a[i].getFinal() == a[j].getFinal()) {
				h++;
				sum1 = a[i].getLeng();
				sum1 += a[j].getLeng();
				k++;
				sum2 = a[i].getPrice();
				sum2 += a[j].getPrice();
				l++;
				out << a[i].getInit() << " " << a[i].getFinal()<< " " << sum1 / k << " " << sum2 / l << endl;
				i += h;
			}
		}
	}
}

void deleting(Distance* a, int n, int& k) {
	double min = 10000.0;
	for (int i = 0; i < n; i++) {
		double h = double(a[i].getLeng()) / double(a[i].getPrice());
		if (h < min) {
			min = h;
		}
	}
	for (int i = 0; i < n; i++) {
		double h = double(a[i].getLeng()) / double(a[i].getPrice());
		if (h == min) {
			for (int j = i; j < n - 1; j++) {
				a[j] = a[j + 1];
			}
			n--;
			i--;
		}
	}
	k = n;
}


void min_dist(Distance* a, int n, string init, ostream& out) {
	int min = INT_MAX;
	string initial = "";
	string final = "";
	for (int i = 0; i < n; i++) {
		if (a[i].getInit() == init) {
			if (a[i].getLeng() < min) {
				min = a[i].getLeng();
				initial = a[i].getInit();
				final = a[i].getFinal();
			}
		}
	}
	out << initial << " " << final << " " << endl;
}

int main() {
	int n; 
	ifstream in("distance.txt");
	in >> n;
	Distance* a = new Distance[n];
	for (int i = 0; i < n; i++) {
		in >> a[i];
	}
	in.close();
	ofstream out("resultdistance.txt");
	sort(a, n);
	for (int i = 0; i < n; i++) {
		out << a[i] << endl;
	}
	out << "The unique distance is: ";
	unique(a, n, out);
	out << endl;
	string init;
	cin >> init;
	out << "Minimal length of input initial station is: ";
	min_dist(a, n, init, out);
	out << endl;
	int k ;
	deleting(a, n, k);
	for (int i = 0; i <k; i++) {
		out << a[i] << endl;
	}
	out.close();
	system("pause");
	return 0;
}