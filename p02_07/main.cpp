//4. Следниот пример илустрира имплицитно инстанцирање на function template.
#include <iostream>

using namespace std;
//max vrakja maksimum na dva elementi
template <class T>
T max(T a, T b)
{
    return a > b ? a : b ;
}

int main()
{
    int I ;
    I = max(10, 15) ; //implicitna instanca na max(int, int)
    char c ;
    c = max('k', 's') ; //implicitna instanca na max(char, char)

    return 0;
}
