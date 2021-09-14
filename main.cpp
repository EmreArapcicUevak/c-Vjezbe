#include <iostream>
#include <fstream>

using namespace std;


class Point {
	protected:
		int x;
	public:
		Point() {
			this->x = 0;
		}

		Point(int x) {
			setX(x);
		}


		Point(const Point &obj) {
			setX(obj.x);
		}
		
		~Point(){};

		int getX() const {return x;}
		void setX(int x) {this->x = x;}
};


class Point2D : public Point {
	protected:
		int y;
	public:
		Point2D() : Point() {
			this->y = 0;
		}

		Point2D(int x , int y) : Point(x) {
			cout << "Init constructor called" << endl;
			setY(y);
		}

		Point2D(const Point2D &obj) : Point(obj) {
			cout << "Copy contructor called" << endl;
			setY(obj.y);
		}

		~Point2D(){}

		int getY() const {return y;}
		void setY(int y) {this->y = y;}

		void printXY() const {
			cout << x << " , " << y << endl;
		}
		
		void setXY(int x , int y) {
			setX(x);
			setY(y);
		}

		const Point2D &operator= (const Point2D &obj) {
			cout << "Assignment running" << endl;
			setXY(obj.x , obj.y);

			return *this;
		}

		friend ostream &operator<<(ostream & , const Point2D &);
		friend Point2D operator+(const Point2D& , const Point2D&);
		friend fstream &operator<<(fstream & ,const Point2D&);
};


ostream &operator<<(ostream &out , const Point2D &obj) {
			out << obj.x << " , " << obj.y;
			return out;
}

fstream &operator<<(fstream &file ,const Point2D& obj) {
	file << obj.x << " , " << obj.y;
	return file;
}
Point2D operator+(const Point2D& obj1 , const Point2D& obj2) {
	return Point2D(obj1.x + obj2.x , obj1.y + obj2.y);
}

int main(int argc, char** argv) {
	ofstream fileHandler;
	fileHandler.open("DotTest.txt");


	Point2D prvaTacka(1 , 5);
	Point2D drugaTacka = prvaTacka; // drugaTacka(prvaTacka)

	drugaTacka.setY(2);

	prvaTacka.setY(7);

	drugaTacka = prvaTacka;
	drugaTacka.printXY();
	cout << drugaTacka << endl;

	prvaTacka.setXY(5 , 5);
	drugaTacka = prvaTacka;

	prvaTacka = prvaTacka + drugaTacka + drugaTacka;

	cout << prvaTacka << endl;
	fileHandler << prvaTacka << " | " << drugaTacka; // isto kao operator<<(operator<<(operator<<(fileHandler , prvaTacka) , "|") , drugaTacka);
	
	fileHandler.close();
	return 0;
}
