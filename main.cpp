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


class Point {
	protected:
		int x;
	public:
		Point(int x = 0) {
			cout << "Konstructor iz point klase" << endl;
			setX(x);
		}
		
		~Point(){
			cout << "Destructor iz point klase" << endl;
		}
		
		int getX() {return x;}
		
		void setX (int x) {
			this->x = x;
		}
};

// PUBLIC -> Private - x , Protected - Protected , Public - Public
// Protected -> Private - x , Protected - Protected , Public - Protected
// Private -> Private - x , Protected - Private , Public - Private


class Point2D : public Point 
{
	protected:
		int y;
	public:
		Point2D(int x = 0 , int y = 0) : Point(x){
			setY(y);
			cout << "Konstructor iz point2D klase" << endl;
		}
		
		~Point2D(){
			cout << "Destructor iz point2D klase" << endl;
		}
		
		void setY(int y) {
			this->y = y;
		}
		
		int getY() {return y;}
		
		
		void setXY(int x , int y){
			setX(x);
			setY(y);
		}
		
		
		void getXY() {
			cout << x << ", " << y << endl;
		}
};

class Point3D : public Point2D {
	protected:
		int z;
	public:
		Point3D(int x = 0 , int y = 0 , int z = 0) : Point2D(x , y) {
			setZ(z);
			cout << "Konstructor iz point3D klase" << endl;
		}
		
		~Point3D(){cout << "Destructor iz point3D klase" << endl;}
		
		void setZ (int z) {
			this->z = z;
		}
		
		void setXYZ (int x , int y , int z) {
			setZ(z);
			setXY(x , y);
		}
		
		void getXYZ(){
			cout << x << ", " << y << ", " << z << endl;
		}
};


class Monster {
	protected:
		float Healt;
		string Name;
	public:
		Monster(){}
		virtual ~Monster(){
			cout << "Destruktor iz klase Monster";
		}
		
		virtual string getName() {return this->Name;}
		virtual float getHealt() {return this->Healt;}
};

class Zombie : public Monster {
	public:
		Zombie() {
			this->Name = "Zombie";
			this->Healt = 58;
		}
		
		~Zombie() {
			cout << "Destruktor iz klase Zombie" << endl;
		}
	string getName() {return this->Name + 'x';}	
};

class X : public Zombie {
	public:
		
		X() {
				this->Name = "X";
				this->Healt = 100;
		}
		
		~X() {
				cout << "Destruktor iz klase X" << endl;
			}
			
	string getName() {return this->Name + 'z';}	
};

class Skeleton : public Monster{
    public:
        Skeleton(){
            this->Name="Skeleton";
            this->Healt=60;
        }
};

int main(int argc, char** argv) {
	
	Monster *MP = new X;
	
	cout << MP->getName();
	delete MP;
	
	//Point3D a(5);

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
	
	/*
	PodesiBroj::SetX(10 ,&sb);
	
	SakriveniBroj sb2(sb);
	PodesiBroj::SetX(5 ,&sb2);
	
	sb.printX();
	sb2.printX();
	*/
	
	return 0;
}



