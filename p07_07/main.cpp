//  remove, remove_if, remove_copy i remove_copy_if


#include <iostream>
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

bool greater9( int );

int main()
{
    const int SIZE = 10;
    int a[ SIZE ] = { 10, 2, 10, 4, 16, 6, 14, 8, 12, 10 };

    ostream_iterator< int > output( cout, " " );

    vector< int > v( a, a + SIZE );
    vector< int >::iterator newLastElement;

    cout << "v pred otstranuvanje na site 10ki:\n   ";
    copy( v.begin(), v.end(), output );


    newLastElement = remove( v.begin(), v.end(), 10 );

    cout << "\nv po otstranuvanje na site 10ki:\n   ";
    copy( v.begin(), newLastElement, output );

    vector< int > v2( a, a + SIZE );
    vector< int > c( SIZE, 0 );

    cout << "\n\nv2 pred otstranuvanje na site 10ki:\n   "
         << "i kopiranje:\n   ";
    copy( v2.begin(), v2.end(), output );


    remove_copy( v2.begin(), v2.end(), c.begin(), 10 );

    cout << "\nc po otstranuvanje na site 10ki od v2:\n   ";
    copy( c.begin(), c.end(), output );

    vector< int > v3( a, a + SIZE );

    cout << "\nv3 pred otstranuvanje na site elementi "
         << "\npogolemi od 9:\n   ";
    copy( v3.begin(), v3.end(), output );

    newLastElement = remove_if( v3.begin(), v3.end(), greater9 );

    cout << "\nv3 po otstranuvanje na site elementi "
         << "\npogolemi od 9:\n   ";
    copy( v3.begin(), newLastElement, output );

    vector< int > v4( a, a + SIZE );
    vector< int > c2( SIZE, 0 );

    cout << "\n\nv3 pred otstranuvanje na site elementi"
         << "\npogolemi od 9 i kopiranje:\n   ";
    copy( v4.begin(), v4.end(), output );

    // kopiraj elementi od v4 vo c2, so otstranuvanje na
    // elementite pogolemi od 9
    remove_copy_if(v4.begin(), v4.end(), c2.begin(), greater9 );

    cout << "\nc2 po otstranuvanje na site elementi"
         << "\npogolemi od 9 od v4:\n   ";
    copy( c2.begin(), c2.end(), output );

    cout << endl;

    return 0;

} // kraj na main

// predikat
bool greater9( int x )
{
    return x > 9;

} // kraj na greater9
