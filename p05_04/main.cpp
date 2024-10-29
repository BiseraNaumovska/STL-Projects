#include <iostream>
#include <deque>      // deque class-template definicija
#include <algorithm>
using namespace std;

int main()
{
    deque< double > values;
    ostream_iterator< double > output( cout, " " );
    // vmetni elementi vo values
    values.push_front( 2.2 );
    values.push_front( 3.5 );
    values.push_back( 1.1 );
    cout << "values sodrzi: ";
    // upotrebi subscript operator za prezemanje na vrednostite na elementite
    for ( int i = 0; i < values.size(); ++i )
        cout << values[ i ] << ' ';
    values.pop_front();  // otstrani go prviot element
    cout << "\nPo pop_front, values sodrzi: ";
    copy( values.begin(), values.end(), output );
    // upotrebi subscript operator za promena na vrednosta
    // na elementot lokacija 1
    values[ 1 ] = 5.4;
    cout << "\nPo values[ 1 ] = 5.4, values sodrzi: ";
    copy( values.begin(), values.end(), output );

    cout << endl;

    return 0;
}
