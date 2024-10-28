// Koristi 'typename' kako prefiks za vgnezdeni tipovi.
#include <iostream>

using namespace std;

template<class T>
class X {
    // Bez typename, ке se dobie greska
    typename T::id i;
public:
    void f() { i.g(); }
};

class Y {
public:
    class id {
    public:
        void g() {}
    };
};


int main()
{
    X<Y> xy;
    xy.f();

    return 0;
}
