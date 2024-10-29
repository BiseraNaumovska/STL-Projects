// Demonsstracija na eksplicitna specijalizacija kaj function template
#include <iostream>
#include <string>
using namespace std;



template<class T>
size_t bytes(T& t)
{
    cout << "(koristam primaren template)\n";
    return sizeof t;
}




size_t bytes(char*& s)
{
    cout<<"(koristam preklopuvanje char* funkcija)\n";
    return strlen(s)+1; // za string sakame da bide vratena negovata dolzina
}





template <>
size_t bytes<>(string& s)
{
    cout<<"(koristam eksplicitna string specijalizacija)\n";
    return sizeof s;
}




template <>
size_t bytes<float>(float& x)
{
    cout<<"(koristam eksplicitna float specijalizacija)\n";
    return sizeof x;
}


int main()
{
    int i;
    cout << "broj na bajti vo i "<<bytes(i)<<endl;
    char *s="Zdravo";
    cout << "broj na bajti vo s "<<bytes(s)<<endl;
    string t;
    cout << "broj na bajti vo t "<<bytes(t)<<endl;
    float x;
    cout << "broj na bajti vo x "<<bytes(x)<<endl;
    double d;
    cout << "broj na bajti vo d "<<bytes(d)<<endl;

    return 0;
}
