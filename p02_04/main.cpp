//1. Следниот пример илустрира инстанца на class template.
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
    Z<int> zi ;   //implicitna instanca na klasa Z<int>
    Z<float> zf ; // implicitna instanca na klasa Z<float>

    return 0;
}
