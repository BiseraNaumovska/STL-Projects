/*
Следниот пример илустрира ситуација во која преклопување на кодот во
function template –от е неопходно:
*/

#include <iostream>
using namespace std ;
#include <cstring>



//max vrakja maksimum od dva elementi od tip T, kade za  T e
// definiran operatorot >
template <class T>
T max(T a, T b)
{
    return a > b ? a : b ;
}



// Speciaјlizacija на max за char*
template <>
char* max(char* a, char* b)
{
    return strcmp(a, b) > 0 ? a : b ;
}




int main()
{
    cout << "max(10, 15) = " << max(10, 15) << endl ;
    cout << "max('k', 's') = " << max('k', 's') << endl ;
    cout << "max(10.1, 15.2) = " << max(10.1, 15.2) << endl ;
    cout << "max(\"Aladdin\", \"Jasmine\") = " << max("Aladdin", "Jasmine") << endl;//vrsi sporeduvanje na adresi
    // za aladin i jasmin se sporeduvaat nivnite adresi a ne stringovite...
    // ama ako imame char funkcija ke dade tochen rezultat
    return 0;
}
