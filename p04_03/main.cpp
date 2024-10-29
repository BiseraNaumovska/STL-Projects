//     adapteri kontejneri !!
/*
Следниот пример демонстрира влез од стандарден влез и излез на стандарден
излез преку итераторите istream_iterator и ostream_iterator.
*/
#include <iostream>
#include <iterator>
using namespace std;

int main()
{
    cout << "Vnesi dva celi broja: ";
    // kreiraj istream_iterator za citanje na vrednosti od cin
    istream_iterator< int > inputInt( cin );
    int number1 = *inputInt;  // citaj int od standard input
    ++inputInt;          // zgolemi go iteratorot
    int number2 = *inputInt;  // citaj od standard input
    // Kreiraj ostream_iterator za zapisuvanje na int na cout
    ostream_iterator< int > outputInt( cout );
    cout << "Sumata e: ";
    *outputInt = number1 + number2;  // prikazi rezultat na cout
    cout << endl;

    return 0;
}
