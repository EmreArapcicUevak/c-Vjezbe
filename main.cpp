#include <iostream>
#include <fstream>

using namespace std;

int main(int argc, char** argv) {
	fstream myFileHandler;
	
	myFileHandler.open("test5.txt" ,  ios::out | ios::app | ios::binary);
	
	/*
		DEFAULT MODE
		fstream - ios::in | ios::out
		
		otvorice se file AKO POSTOJI , i mozemo pisati i citati , i kursor je uvijek na pocetku
	*/
	
	/*
		INPUT MODE
		fstream - ios::in
		
		Mozemo samo citati file
	*/
	
	/*
		OUTPUT MODE
		fstream - ios::out
		
		Mozemo samo pisati , ako file NE postoji on ce ga napraviti , medzutim on truncate-a file
	*/
	
	/*
		ios::trunc -- brise sve iz file-a
		ios::ate -- At The End - postavlja pointer na kraj fila-a
		ios::app - Appen - nove stvari  stavlja na kraj file-a ALI nije moguce mijenjati ili brisati stvari prije kraja
		ios::binary -- Otvori file kao binary file
	*/
	
	if (myFileHandler.is_open()){
		myFileHandler << "test\n";
		myFileHandler.close();
	} else {
		cout << "File nije otvoren";
	}
	
	
	return 0;
}



