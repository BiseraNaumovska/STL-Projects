// Testiranje na funkcii za manipulacija so elementi na class template vector
#include <iostream>

using namespace std;

#include <vector>
#include <algorithm>


int main()
{
    const int SIZE = 6;
    int array[ SIZE ] = { 1, 2, 3, 4, 5, 6 };
    vector< int > integers( array, array + SIZE );
    ostream_iterator< int > output( cout, " " );
    // iterator koj prikazuva int na cout so separator " "
    cout << "Vector integers sodrzi: ";
    copy( integers.begin(), integers.end(), output );
    cout << "\nPrv element na integers: " << integers.front()
         << "\nPosleden element na integers: " << integers.back();
    integers[ 0 ] = 7;      // Postavi vrednost 7 na prv el.
    integers.at( 2 ) = 10;  // Postavi vrednost 10 na el. na pozicija 2
    // pristap do out-of-range element
    try {
        integers.at( 100 ) = 777;
    } // end try
    // ulovi out_of_range exception
    catch ( out_of_range outOfRange ) {
        cout << "\n\nException: " << outOfRange.what();
    } // end catch
    // Vmetni 22 na pozicija 2
    integers.insert( integers.begin() + 1, 22 );
    cout << "\n\nVector integers sodrzi: ";
    copy( integers.begin(), integers.end(), output );
    // izbrisi go prviot element
    integers.erase( integers.begin() );
    cout << "\n\nVector integers sodrzi: ";
    copy( integers.begin(), integers.end(), output );
    // izbrisi gi site elementi
    integers.erase( integers.begin(), integers.end() );
    cout << "\nPo brisenje na site elementi integers"
         << ( integers.empty() ? " e" : " ne e" ) << " prazno";
    // dodaj elementi od poleto
    integers.insert( integers.begin(), array, array + SIZE );
    cout << "\n\nVector integers sodrzi: ";
    copy( integers.begin(), integers.end(), output );
    //
    integers.clear();
    cout << "\nPo praznenje, integers"
         << ( integers.empty() ? " e" : " ne e" ) << " prazno";
    cout << endl;

    return 0;
}
