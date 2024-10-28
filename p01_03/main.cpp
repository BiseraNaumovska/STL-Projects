#include <iostream>
#include "tstack1.h"  // Stack class template definicija
using namespace std;

int main()
{
    Stack< double > doubleStack( 5 );
    double doubleValue = 1.1;

    cout << "Push na elementi na double sklad \n";

    while ( doubleStack.push( doubleValue ) ) {
        cout << doubleValue << ' ';
        doubleValue += 1.1;

    }

    cout << "\nSkladot e poln. Ne moze da se izvrsi push " << doubleValue
         << "\n\nPop na elementi na double sklad\n";

    while ( doubleStack.pop( doubleValue ) )
        cout << doubleValue << ' ';

    cout << "\nSkladot e prazen. Ne moze da se izvrsi pop\n";

    Stack< int > intStack;
    int intValue = 1;
    cout << "\nPush na elementi na int sklad\n";

    while ( intStack.push( intValue ) ) {
        cout << intValue << ' ';
        ++intValue;

    } // end while

    cout << "\nSkladot e poln. Ne moze da se izvrsi push " << intValue
         << "\n\nPop na elementi na int sklad\n";

    while ( intStack.pop( intValue ) )
        cout << intValue << ' ';

    cout << "\nSkladot e prazen. Ne moze da se izvrsi pop\n";

    return 0;
}
