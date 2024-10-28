/*
Следниот пример реализира генератор на случајни броеви. Тој користи bitset
за евиденција на броевите кои веќе биле генерирани. Преклопен е operator( )
за да се добие синтакса слична на функциски повик.
*/


#include <iostream>
#include <bitset>
#include <cstddef>
#include <cstdlib>
#include <ctime>

using namespace std;


template<size_t UpperBound> class Urand {
    bitset<UpperBound> used;
public:
    Urand() { srand(time(0)); } // Randomize
    size_t operator()(); // Generatorska funkcija
};

template<size_t UpperBound>
inline size_t Urand<UpperBound>::operator()() {
    if(used.count() == UpperBound)
        used.reset();  // resetiranje na bitovite
    size_t newval;
    while(used[newval = rand() % UpperBound])
        ; // povtoruvaj dodeka ne se pronajde nova slucajna vrednost
    used[newval] = true;
    return newval;
}


int main()
{
    Urand<10> u;
    for(int i = 0; i < 20; ++i)
        cout << u() << ' ';

    return 0;
}
