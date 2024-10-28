//
// Test programa za klasata Stack class


#include <iostream>

using namespace std;

#include "tstack1.h"

// function template za manipulacija so Stack< T >
template< class T >
void testStack(
    Stack< T > &theStack,   // referenca na Stack< T >
    T value,                // pocetna vrednost za push
    T increment,            // zgolemuvanje na posledovatelni vrednosti
    const char *stackName ) // ime na objektot Stack < T >
{
    cout << "\nSmestuvanje na elementi na " << stackName << '\n';

    while ( theStack.push( value ) ) {
        cout << value << ' ';
        value += increment;

    }

    cout << "\nSkladot e poln. Ne moze da se izvrsi push " << value
         << "\n\nPop na elementi od " << stackName << '\n';

    while ( theStack.pop( value ) )
        cout << value << ' ';

    cout << "\nSkladot e prazen. Ne moze da se izvrsi pop\n";

} // kraj na funkcijata testStack

int main()
{
    Stack< double > doubleStack( 5 );
    Stack< int > intStack;

    testStack( doubleStack, 1.1, 1.1, "doubleStack" );
    testStack( intStack, 1, 1, "intStack" );

    return 0;

} // kraj na main
