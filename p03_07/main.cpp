#include <iostream>
#include <conio.h>

using namespace std;

template <class T>
class B;


template <class T>
class A {
    T val;
    friend void swap (A<T> &, B<T> &);
public:
    A(){cout <<"val="; cin >> val; cout << endl;}
    void disp() {cout << "val=" << val << endl;}
};



template <class T>
class B {
    T x;
    friend void swap (A<T> &, B<T> &);
public:
    B(){cout <<"x="; cin >> x; cout << endl;}
    void disp() {cout << "x=" << x  << endl;}
};



template <class T>
void swap( A<T> &p, B<T> &q)
{
    T buf;
    buf=p.val;p.val=q.x;q.x=buf;
}
main()
{
    A<int> objA;
    B<int> objB;

    swap<int>(objA, objB);
    objA.disp();
    objB.disp();
    return 0;
}
