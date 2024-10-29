// Test programa za STL adapter queue


#include <iostream>
#include <queue>
using namespace std;

int main()
{
    queue< double > values;

    // push na elementi na values
    values.push( 3.2 );
    values.push( 9.8 );
    values.push( 5.4 );
    cout << "Pop na elementi od redicata values: ";

    while ( !values.empty() ) {
        cout << values.front() << ' ';  // prikazi go elementot na pocetokot
        values.pop();                   // otstrani go
    }
    cout << endl;

    return 0;
}
