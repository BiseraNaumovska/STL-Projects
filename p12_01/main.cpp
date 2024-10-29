/*
1. Креирај class temlate Pole што реализира поле од било кој тип.
Имплементирај function template max за определување на најголем елемент во
полето. Во main креирај полиња од int, char и string, пополни ги со по 5
произволни елементи и прикажи најголем елемент за секое поле.
*/
#include <iostream>
#include <string>
#include <algorithm>
using namespace std;



template <typename T>
class Pole {
private:
    T* elementi;
    int golemina;

public:
    Pole(int n) : golemina(n) {
        elementi = new T[golemina];
    }

     ~Pole() {
        delete[] elementi;
    }

    void popolni() {
        for (int i = 0; i < golemina; i++) {
            cout << "Vnesi element " << i + 1 << ": ";
            cin >> elementi[i];
        }
    }

    T max() {
        return *max_element(elementi, elementi + golemina);
    }
};

int main() {
    //  int
    Pole<int> intPole(5);
    intPole.popolni();
    cout << "Najgolem element vo pole od int: " << intPole.max() << endl;

    // char
    Pole<char> charPole(5);
    charPole.popolni();
    cout << "Najgolem element vo pole od char: " << charPole.max() << endl;

    // string
    Pole<string> stringPole(5);
    stringPole.popolni();
    cout << "Najgolem element vo pole od string: " << stringPole.max() << endl;

    return 0;
}
