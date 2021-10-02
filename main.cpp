#include <iostream>
#include <map>
using namespace std;


int main(int argc, char** argv) {
    try {
      map<string , int> ages; // Pravimo objekat map koji kao kljuceve uzima stringove a kao vrijednosti uzima intove

      ages["Emre"] = 18;
      ages["Muhhamed"] = 18;
      ages["Ahmed"] = 16;

      cout << ages["Emre"] << '\n'; // printa ce broj 18

      // cout << ages["Neko ko nepostoji u mapi"] << endl; ovo je lose jel ce nam dodati tu vrijednost u nasu mapu

      if (ages.find("Neko ko nepostoji u mapi") != ages.end())
        cout << "Key found\n";
      else
        cout << "Key NOT found\n";

      pair<string , int> age = *(ages.begin()); // Ovo je taj jedan "Node" mape
      ages.insert(age); // ovjde unosimo "par" u mapu ali posto vec postoji nece se nista mijenjati
      // a mozemo nesto i ovako raditi ages.insert(pair<string , int>("Emre2" , 19))
      for (map<string , int>::iterator it = ages.begin() ; it != ages.end() ; it++)
        cout << it->first << ": " << it->second << endl; // first je kljuc , second je vrijednost u tom klucu

    }catch (const char *errorMsg) {
        cout << errorMsg;
    }
    return 0;
}