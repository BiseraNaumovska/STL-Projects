// Test programa za STL priority_queue.

#include <iostream>
#include <queue>
using namespace std;

int main()
{
    priority_queue< double > priorities;

    // push elementi na priorities
    priorities.push( 3.2 );
    priorities.push( 9.8 );
    priorities.push( 5.4 );
    cout << "Pop od priorities: ";

    while ( !priorities.empty() ) {
        cout << priorities.top() << ' ';  // prikazi go elementot na pocetokot
        priorities.pop();                 // otstrani go
    }
    cout << endl;

    return 0;
}
