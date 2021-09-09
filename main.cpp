#include <iostream>

using namespace std;
/*
class Dot {
	// ovdje je isto private podrucje
	
	public:
		Dot(float x = 0, float y = 0) {
			this->x = x;
			this->y = y;
			Print();
			cout << "Pozvlai smo konstruktor" << endl;
		}
		
		~Dot() {
			cout << "Pozvali smo destruktor" << endl;
		}
		
		void Print() {
			cout << "(" << x << "," << y << ")" << endl;
		}
		
	protected:
	private:
		float x , y;
}test;
*/
 /*
class ID {
	
	int a;
	
	public:
		static void print() {
			cout << "e" << endl;
		}
		
		static int add(int a , int b) {
			return a + b;
		}
		
		void printA() {
			cout << a << endl;
		}
};
*/


/*
class Position {
		float x,y;
	public:
		Position(float x = 0, float y = 0) {
			SetXY(x , y);
			cout << "Pozvlai smo konstruktor" << endl;
		}
		
		~Position() {
			cout << "Pozvali smo destruktor" << endl;
		}
		
		void SetXY(float x, float y) {
			this->x = x;
			this->y = y;
		}
		
		void PrintPosition() const {
			cout << "(" << x << "," << y << ")" << endl;
		}
};
*/

class PodesiBroj;

class SakriveniBroj{
	int *x;
	
	public:
		SakriveniBroj(int x = 0) {
			this->x = new int(x);
		}
		
		SakriveniBroj(const SakriveniBroj& ClassToCopy) {
			this->x = new int(*(ClassToCopy.x));
		}
		
		~SakriveniBroj() {
			delete this->x;
		}

		
		void printX(){
			cout << *x << endl;
		}
		
		friend void SetX(int , SakriveniBroj *);
		friend PodesiBroj;
}sb;

class PodesiBroj {
	
	public:
		static void SetX(int x , SakriveniBroj * Broj) {
			*(Broj->x) = x;
		}
};

void SetX(int x , SakriveniBroj * Broj) {
	*(Broj->x) = x;
}

int main(int argc, char** argv) {
	//std::cout << test.x; ovo ne moze jer je x private
	/*ID test2;
	
	test2.print();
	ID::print();
	cout << endl << ID::add(1 , 2);
	test2.printA();*/
	
	/*
	Position dog;
	Position const house(100 , 100);
	
	dog.SetXY(0.1 , 1);
	dog.PrintPosition();
	
	//house.SetXY(150,150);
	house.PrintPosition();*/
	
	/*
	SetX(69 , &sb);
	PodesiBroj::SetX(10 , &sb);
	sb.printX();
	SetX(20 , &sb); 
	
	*/
	PodesiBroj::SetX(10 ,&sb);
	
	SakriveniBroj sb2(sb);
	PodesiBroj::SetX(5 ,&sb2);
	
	sb.printX();
	sb2.printX();
	
	
	return 0;
}



