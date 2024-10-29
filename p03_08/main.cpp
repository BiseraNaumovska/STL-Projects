/*
Вежби:
1.      Напиши class template Zapis<T> кој содржи три приватни членки:
x, y и z од тип Т. Креирај function template kontrolor кој ќе проверува
дали збирот на елементите x, y и z во Zapis надминува 10000. Напиши
соодветна програма за демонстрација со инстанцирање на објекти од тип
Zapis<int> и Zapis<double>.

*/

#include <iostream>

using namespace std;


template<class T>
class Zapis {
private:
    T x;
    T y;
    T z;
public:
    Zapis(T x, T y, T z) : x(x), y(y), z(z) {}

    template <typename U>
    friend bool kontrolor(const Zapis<U>& obj);
};

// Function template kontrolor
template<class T>
bool kontrolor(const Zapis<T>& obj) {
    T suma = obj.x + obj.y + obj.z;
    if (suma > 10000) {
        return true;
    } else {
        return false;
    }
}


int main() {
    Zapis<int> intZapis(3000, 4000, 5000);
    Zapis<double> doubleZapis(3000.5, 4000.5, 5000.5);
    Zapis<double> doubleZapis1(100.5, 400.5, 500.5);
    Zapis<int> intZapis1(300, 400, 500);

    if (kontrolor(intZapis)) {
        cout << "Zbirot na elementite nadminuva 10000.\n";
    } else {
        cout << "Zbirot na elementite NE nadminuva 10000.\n";
    }

    if (kontrolor(doubleZapis)) {
        cout << "Zbirot na elementite nadminuva 10000.\n";
    } else {
        cout << "Zbirot na elementite NE nadminuva 10000.\n";
    }

    if (kontrolor(intZapis1)) {
        cout << "Zbirot na elementite nadminuva 10000.\n";
    } else {
        cout << "Zbirot na elementite NE nadminuva 10000.\n";
    }

    if (kontrolor(doubleZapis1)) {
        cout << "Zbirot na elementite nadminuva 10000.\n";
    } else {
        cout << "Zbirot na elementite NE nadminuva 10000.\n";
    }

    return 0;
}
