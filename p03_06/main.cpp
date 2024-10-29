#include <iostream>

using namespace std;

template <class T>
void f(T t)
{
    static T s ;
    s = t ;
    cout << "s = " << s << endl ;
}


int main()
{
    f(10) ;
    f("Hello") ;

    return 0;
}
