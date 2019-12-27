//#include "problem_solving_11.cpp"
//
//int main() {
//	int n;
//	ifstream in("input.txt");
//	in >> n;
//	Figure** a = new Figure * [n];
//	size_t type;
//	for (size_t i = 0; i < n; i++) {
//		in >> type;
//		switch (type) {
//		case 0:a[i] = new Circle;
//			break;
//		case 1:a[i] = new Poligon;
//		}
//		a[i]->input(in);
//	}
//	sort(a, n);
//	for (size_t i = 0; i < n; i++) {
//		a[i]->output(cout);
//		cout << a[i]->square() << endl;
//	}
//	string myColour;
//	in >> myColour;
//	int i = search(a, n, myColour);
//	if (i != -1) {
//		a[i]->output(cout);
//	}
//	else {
//		cout << "No figure" << endl;
//	}
//	for (size_t i = 0; i < n; i++) {
//		delete a[i];
//	}
//	delete[]a;
//	in.close();
//	system("pause");
//	return 0;
//
//}