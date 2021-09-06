#include <iostream>

using namespace std;

struct Film {
	string ime , kategorija;
	unsigned int godinaIzdanja;
};

struct Test {
	int a , b;
}E;

struct Vrijeme {
	short unsigned int sat , minuta , sekunda;
};

void printTime(Vrijeme *V) {
	cout <<V->sat<< ":" << V->minuta << "::" << V->sekunda << endl;
}

void dodajSat(Vrijeme *V , unsigned int forwardTime) {
	V->sat += forwardTime;
	
	if (V->sat >= 24) {
		V->sat -= 24;
	}
}

void dodajMin(Vrijeme *V , unsigned int forwardTime) {
	V->minuta += forwardTime;
	
	if (V->minuta >= 60) {
		V->minuta -= 60;
		dodajSat(V , 1);
	}
}

void dodajSekudne(Vrijeme *V , unsigned int forwardTime) {
	V->sekunda += forwardTime;
	
	if (V->sekunda >= 60) {
		V->sekunda -= 60;
		dodajMin(V , 1);
	}
}

void pomjeritiPoSekundi(Vrijeme *V , unsigned int forwardTime) {
	unsigned int Sekundih = (forwardTime % 60) , Minuta = forwardTime / 60 , Satih;
	Satih = Minuta / 60; 
	
	dodajSat(V , Satih);
	dodajMin(V , Minuta);
	dodajSekudne(V , Sekundih);
	
	cout << Sekundih << " " << Minuta << " " << Satih << endl;
}

void pomjeritiPoMinuti(Vrijeme *V , unsigned int forwardTime) {
	unsigned int  Minuta = forwardTime % 60 , Satih = forwardTime / 60;
	
	dodajSat(V , Satih);
	dodajMin(V , Minuta);
	
	cout << Minuta << " " << Satih << endl;
}

void pomjeritiPoSatu(Vrijeme *V , unsigned int forwardTime) {
	dodajSat(V , forwardTime);
}

int main(int argc, char** argv) {
	Film A;
	
	//cout << A.godinaIzdanja;
	//cout << &E.a << " " << &E.b << " - " << sizeof(E.a);
	
	/* 
		Napraviti strukturu po imenu vrijeme i u toj strukturi napraviti varijable po imeni Sat , Minuta , Sekunda i onda napraviti 3 funkcije po imenima , pomjeritiPoSekundi , pomjeritiPoMinuti , pomjeritiPoSatu
		ovo funkcije sve uzimaju 2 paramtera jedan int i pointer za structuru , int ce biti broj (minuta ili sekunde ili sata) koji ce nam reci koliko da pomjerimo vrijeme unazad ili unaprijed
	*/
	
	Vrijeme PocetnoVrijeme;
	PocetnoVrijeme.sat = PocetnoVrijeme.minuta = PocetnoVrijeme.sekunda = 0;
	pomjeritiPoSatu(&PocetnoVrijeme , 23);
	pomjeritiPoSekundi(&PocetnoVrijeme , 800);
	pomjeritiPoMinuti(&PocetnoVrijeme , 40);
	printTime(&PocetnoVrijeme);
	
	return 0;
}

