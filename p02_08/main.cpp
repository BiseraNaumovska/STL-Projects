/*
6. Со тоа што се генерира само кодот на функциите што се користат се спречува
 непотребно зголемување на изворниот код. Во спротивно, генерирањето на сите
функции членки при инстанцирање на class template во голема мера ќе го
ограничи бројот на употребени template-и во една програма.
*/
#include <iostream>

using namespace std;



class X {
public:
    void f() {}
};



class Y {
public:
    void g() {}
};


template<typename T>
class Z {
    T t;
public:
    void a() { t.f(); }
    void b() { t.g(); }
};

int main()
{
    Z<X> zx;
    zx.a(); // ne se kreira Z<X>::b()
    Z<Y> zy;
    zy.b(); // ne se kreira Z<Y>::a()

    return 0;
}
