#include <iostream>

using namespace std;
template <class type>
bool match(type someText) {
	return someText.size() >= 3;
}

template <class type>
bool match2(type someText) { 
	return someText[0] == 'E';
}

template <class type>
unsigned int Prebroji(type arr[] , unsigned int size , bool (*match)(type) ) {
	unsigned int counter = 0;
	
	for (unsigned int i = 0 ; i < size ; i++) {
		if (	match(arr[i])	)
			counter++;
	}

	return counter;
}

void printHello() {
	cout << "Hello" << endl;
}



struct MatchTest {
	bool operator()(string &text) {
		return text == "ab";
	}
};



int main(int argc, char** argv) {
	
	MatchTest a;
	
	void (*pFunc)() = printHello;
	pFunc();

	string TextArr[] = {"ab" , "abc" , "Emre" , "Muhammed" , "ab"};
	
	cout << "Imamo " << Prebroji(TextArr , 5 , match) << " stringova cija je velicina veca ili jednaka 3" << endl;
	cout << "Imamo " << Prebroji(TextArr , 5 , match2) << " stringova koji pocinju sa velikim slovom E" << endl;
	
	for (unsigned int i = 0 ; i < 5 ; i++) {
		if (	a(TextArr[i])	)
			cout << "ab found" << endl;
	}


	return 0;
}
