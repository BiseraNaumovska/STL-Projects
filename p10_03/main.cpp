//Следниот пример илустрира употреба на set_unexpected( ):
#include <exception>
#include <iostream>
using namespace std;

class Up {};
class Fit {};

void g();

void f(int i) throw(Up, Fit) {
    switch(i) {
    case 1: throw Up();
    case 2: throw Fit();
    }
    g();
}

//void g() {}         // verzija 1
void g() { throw 50; } // verzija 2

void my_unexpected() {
    cout << "unexpected exception thrown" << endl;
    exit(0);
}


int main()
{
    set_unexpected(my_unexpected);
    for(int i = 1; i <=3; i++)
        try {
            f(i);
        } catch(Up) {
            cout << "Up faten" << endl;
        } catch(Fit) {
            cout << "Fit faten" << endl;
        }

    return 0;
}
