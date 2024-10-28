//2. Во следната програма се користат функциите членки Z<T>::f() и Z<T>::g().
#include <iostream>

using namespace std;

template <class T>
class Z
{
public:
    Z() {} ;
    ~Z() {} ;
    void f(){} ;
    void g(){} ;
} ;


int main()
{
    Z<int> zi ; // implicitna instanca generira klasa Z<int>
    zi.f() ;    //i funkcija clenka Z<int>::f()
    Z<float> zf ; // implicitna instanca generira klasa Z<float>
    zf.g() ;      // i funkcija clenka Z<float>::g()

    return 0;
}
