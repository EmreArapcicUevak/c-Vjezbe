#include <iostream>
#include <list>
using namespace std;


int main(int argc, char** argv) {
    try {
      list<int> numbers;

      for (unsigned int i = 1 ; i <= 3 ; i++)
        numbers.push_back(i); // Dodajemo brojeve od 1 do 3 od nazad


      numbers.push_front(7); // dodajemo broj 7 na pocetak

      list<int>::iterator it = numbers.begin();
      it++;
      numbers.insert(it , 20); // ovo ce nam gurnuti iterator za jedno unaprijed

      cout << "Elemement na trecem mjestu je " << *it << endl;

      cout << "Ispis prije brisanje :\n";

      for (list<int>::iterator it = numbers.begin() ; it != numbers.end() ; it++)
        cout << *it << " ";

      //numbers.erase(++it); Ovo NE smijemo raditi ovako AKO smo mislili opet koristiti ovaj iterator jel ovaj iterator ce pokazivati na IZBRISANU memoriju sto neki drugi program moze mijenjati

      cout << '\n';

      it = numbers.erase(++it);

      cout << "Ispis poslje brisanje :\n";

      for (list<int>::iterator it = numbers.begin() ; it != numbers.end() ; it++)
        cout << *it << " ";

      cout << '\n' << *it;

    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}