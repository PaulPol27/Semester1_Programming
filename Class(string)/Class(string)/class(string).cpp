#include <iostream>
#include <string>

using namespace std;

//int main() {
//	string line, word;
//	int pos;
//	getline(cin, line, '.');
//	line += ' ';
//	/*cout << line;*/
//	while ((pos = line.find(' ') != string::npos)) {
//		cout << pos << endl;
//		word = line.substr(0, pos); // substr -- otrumuye ryadok;
//		cout << word << endl;
//		line = line.erase(0, pos + 1); // vuluchayemo
//		/*pos = 0;*/
//	}
//	//system("pause");
//	return 0;
//}


int main() {
	string line, word;
	getline(cin, line);
	int pos = 0;
	while ((pos = line.find('f', pos)) != string::npos) {
		line.replace(pos, 1, "...");
		pos = pos + 3;
	}
	cout << line;
	system("pause");
	return 0;
}
