#include <iostream>

using namespace std;

int main(int argc, char** argv) {
	string Test = "Emre i Muhammedaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaaa";


	for (unsigned int i = 0 ; i < Test.size() ; i++) {
	cout << Test[i] << ' ';
	}

	for (string::iterator it = Test.begin() ; it != Test.end() ; it++) {
		cout << *it << ' ';
	}

	return 0;
}
