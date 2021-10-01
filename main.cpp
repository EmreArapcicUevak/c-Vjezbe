#include <iostream>
#include <vector>
using namespace std;


int main(int argc, char** argv) {
    try {
      vector<string> strings; // Ako konstruktoru damo neki broj x on ce staviti da pocetni size bude x

      strings.push_back("One");
      strings.push_back("Two");
      strings.push_back("Three");

      cout << strings.size() << " " << strings.capacity() << " " << strings.max_size() <<'\n'; // size je velicina popunjenog niza , capacity je trenutna cijela velicina niza


      for (unsigned int i = 0 ; i < strings.size() ; i++)
        cout << strings[i] << " ";

      // Ovako mozemo i nepravi nikakvu smetnju jel je vektor sami niz ali je bolje da se naucimo praviti for petlje sa iteratorima da mozemo tako i kroz stringove ici

      cout << endl;

      for (vector<string>::iterator it = strings.begin() ; it != strings.end() ; it++) // moze biti it++ ili it += 1 jedno i drugo radi
        cout << *it << " ";

      cout << endl << endl;

      /*
          Sad ce mo da porbamo da napravimo matricu koristeci vektore a NE nizove (ma da tu nema velike razilke)
      */


      vector< vector<int> > grid(3 , vector<int>(4 , 0)); 
      /* 
        Ovdje smo napravili vektor koji prima tipove vektor koji primaju tip int i 
        stavili smo defaltni size da bude 3 nako cega smo mu dali defaltne vrijednosti za ta 3 mjesta sto je
        podatak tipa vector (tacnije receno objekat) koji sadzri tipove podataka int i koji po defaltu dobija size od 4 
        i njegova defaultna vrijednost za svaki njegov element je 0.
      */

      for (vector<vector<int>>::iterator row = grid.begin() ; row != grid.end() ; row++){
         for (vector<int>::iterator collum = (*row).begin() ; collum != (*row).end() ; collum++)
          cout << *collum << " ";
        
          cout << endl;
      }
       

      /*
        Ispis na kraju ce biti 

        0 0 0 0 
        0 0 0 0 
        0 0 0 0 
      */

    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}