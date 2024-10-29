
// Upotreba na set_terminate(). Prikazuva i 'nefateni' isklucoci

#include <iostream>
#include <exception>
using namespace std;


void terminator() {
    cout << "Nov terminate!" << endl;
    exit(0);
}
void (*old_terminate)() = set_terminate(terminator);


//Problematicna klasa
class Mess {
public:
    class Fruit {};
    void f() {
        cout << "Mess::f()" << endl;
        throw Fruit();//frla isklucok
    }
    ~Mess() { throw 'c'; }//i destruktorot frla isklucok
};




int main()
{
    try {
        Mess b;
        b.f();
    } catch(...) {
        cout << "vo catch(...)" << endl;
    }

    return 0;
}
