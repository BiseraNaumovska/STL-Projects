
/*
2.      Креирај класа Garaza во која има Avtomobil што може да има проблеми
со својот Motor. Употреби try блок во конструкторот на Garaza за фаќање на
исклучокот од Motor кога се иницијализира Avtomobil. Фрли друг исклучок
од catch блокот во конструкторот на  Garaza и фати го во main( ).
*/

#include <iostream>
#include <stdexcept>
using namespace std;


class Motor {
public:
    Motor() {
        throw runtime_error("Motor: ne moze da se startuva");
    }
};


class Avtomobil {
public:
    Avtomobil() {
        Motor motor;
    }
};


class Garaza {
public:
    Garaza() {
        try {
            Avtomobil avtomobil;
        } catch (const runtime_error& e) {
            cout << "exception in Garaza: " << e.what() << endl;
            throw runtime_error("Garaza nema Avtomobil.");
        }
    }
};

int main() {
    try {
        Garaza garaza;
    } catch (const runtime_error& e) {
        cout << "exception in main: " << e.what() << endl;
    }

    return 0;
}
