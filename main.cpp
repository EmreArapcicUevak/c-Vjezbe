#include <iostream>
#include <fstream>

using namespace std;

template<class someType>

class Test {
	private:
		someType obj;
	public:
		Test(someType obj) {
			this->obj = obj;
		}

		void print() {
			cout << obj << endl;
		}
};

template<class someType>

void print(someType n) {
	cout << "Template version -> " <<  n << endl;
}


void print(int n) {
	cout << "Int version -> " <<  n << endl;
}

template<class someType>
void show(){
	cout << someType() << endl;
}


int main(int argc, char** argv) {
	Test<int> a(1);
	a.print();

	print(1);
	print<int>(1);
	print<>(1);
	print(1.1);

	show<int>();
	return 0;
}
