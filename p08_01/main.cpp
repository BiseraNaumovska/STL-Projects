// search i sort.


#include <iostream>

using namespace std;

#include <algorithm>
#include <vector>
#include<iterator>
bool greater10( int value );


int main()
{
    const int SIZE = 10;
    int a[ SIZE ] = { 10, 2, 17, 5, 16, 8, 13, 11, 20, 7 };
    vector< int > v( a, a + SIZE );
    ostream_iterator< int > output( cout, " " );
    cout << " v sodrzi: ";
    copy( v.begin(), v.end(), output );

    // najdi prvo pojavuvanje na 16 vo v
    vector< int >::iterator location;
    location = find( v.begin(), v.end(), 16 );
    if ( location != v.end() )
        cout << "\n\nPronajdov 16 na lokacija "
             << ( location - v.begin() );
    else
        cout << "\n\n16 ne e najdena";

    // najdi prvo pojavuvanje na 100 vo v
    location = find( v.begin(), v.end(), 100 );
    if ( location != v.end() )
        cout << "\nPronajdov 100 na lokacija "
             << ( location - v.begin() );
    else
        cout << "\n100 ne e najdena";
    // najdi prvo pojavuvanje na vrednost pogolema od 10 vo v
    location = find_if( v.begin(), v.end(), greater10 );
    if ( location != v.end() )
        cout << "\n\nPrvata vrednost pogolema od 10 e "
             << *location << "\n na lokacija"
             << ( location - v.begin() );
    else
        cout << "\n\nNe se pronajdeni vrednosti pogolemi od 10";
    // sortiraj gi elementite na v
    sort( v.begin(), v.end() );
    cout << "\n\n v po sort: ";
    copy( v.begin(), v.end(), output );
    // koristi binary_search da najdes vrednost 13 vo v
    //za da se koristi binary_search elementite mora da bidat sortirani
    if ( binary_search( v.begin(), v.end(), 13 ) )
        cout << "\n\n13 e pronajdena vo v";
    else
        cout << "\n\n13 ne e pronajdena vo v";
    // koristi binary_search da najdes vrednost 100 vo v
    if ( binary_search( v.begin(), v.end(), 100 ) )
        cout << "\n100 e pronajdena vo v";
    else
        cout << "\n100 ne e pronajdena vo v";
    cout << endl;
    return 0;
} // kraj na main
// opredeluva dali argumentot e pogolem od 10
bool greater10( int value )
{
    return value > 10;
} // kraj na greater10

