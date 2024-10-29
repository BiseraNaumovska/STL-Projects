
#include <iostream>

using namespace std;


template <class T>
class X
{
public:
    static T s ;
} ;
template <class T> T X<T>::s = 0 ;
template <> int X<int>::s = 3 ; //int specijalizacija
template <> char* X<char*>::s = "Hello" ;//char* specijalizacija

int main()
{
    X<int> xi ;
    cout << "xi.s = " << xi.s << endl ;
    X<char*> xc ;
    cout << "xc.s = " << xc.s << endl ;

    return 0;
}
