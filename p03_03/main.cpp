//Demonsstracija na eksplicitna specijalizacija kaj class template
#include <iostream>
using namespace std;


template<typename T>
class A
{
public:
    A(){cout << "Primaren template\n";}
};



template <>
class A<char>
{
public:
    A(){cout << "char specijalizacija\n";}
};




template <>
class A<float>
{
public:
    A(){cout << "float specijalizacija\n";}
};


int main()
{
    A<int> a1;
    A<char> a2;
    A<float> a3;
    A<double> a4;

    return 0;
}
