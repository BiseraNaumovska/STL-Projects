//  equal, mismatch i lexicographical_compare



#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    const int SIZE = 10;
    int a1[ SIZE ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int a2[ SIZE ] = { 1, 2, 3, 4, 1000, 6, 7, 8, 9, 10 };

    vector< int > v1( a1, a1 + SIZE );
    vector< int > v2( a1, a1 + SIZE );
    vector< int > v3( a2, a2 + SIZE );

    ostream_iterator< int > output( cout, " " );

    cout << " v1 sodrzi: ";
    copy( v1.begin(), v1.end(), output );
    cout << "\n v2 sodrzi: ";
    copy( v2.begin(), v2.end(), output );
    cout << "\n v3 sodrzi: ";
    copy( v3.begin(), v3.end(), output );

    bool result =equal( v1.begin(), v1.end(), v2.begin() );

    cout << "\n\n v1 " << ( result ? "e" : "ne e" )<< " ednakov na v2.\n";

    result = equal( v1.begin(), v1.end(), v3.begin() );
    cout << " v1 " << ( result ? "e" : "ne e" )<< " ednakov na v3.\n";

    // location e par od vector iteratori
    pair< vector< int >::iterator, vector< int >::iterator > location;

    location = mismatch( v1.begin(), v1.end(), v3.begin() );

    cout << "\n v1 i v3 se razlikuvaat na "<< "lokacija " << ( location.first - v1.begin() )
         << "\nkade v1 sodrzi " << *location.first
         << " a v3 sodrzi " << *location.second<<endl;


    char c1[ SIZE ] = "HELLO";
    char c2[ SIZE ] = "BYE BYE";

    result = lexicographical_compare(c1, c1 + SIZE, c2, c2 + SIZE );

    cout << c1<< ( result ? " e pogolem od " :" e pomal ili ednakov na " )<< c2 << endl;

    return 0;
}
