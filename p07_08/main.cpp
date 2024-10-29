
// replace, replace_if, replace_copy i replace_copy_if

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

    vector< int > v1( a, a + SIZE );
    cout << " v1 pred zamena na site 10ki:\n   ";
    copy( v1.begin(), v1.end(), output );

    // zameni gi 10kite vo v1 so 100
    replace( v1.begin(), v1.end(), 10, 100 );

    cout << "\n v1 po zamena na site 10ki so 100:\n   ";
    copy( v1.begin(), v1.end(), output );

    vector< int > v2( a, a + SIZE );
    vector< int > c1( SIZE );

    cout << "\n\n v2 pred zamena na site 10ki "<< "i kopiranje:\n   ";
    copy( v2.begin(), v2.end(), output );

    // koiraj od v2 vo c1, zameni gi 10kite so 100
    replace_copy(v2.begin(), v2.end(), c1.begin(), 10, 100 );

    cout << "\n c1 po zamena na site 10ki vo v2:\n   ";
    copy( c1.begin(), c1.end(), output );

    vector< int > v3( a, a + SIZE );

    cout << "\n\n v3 pred zamena na vrednostite"<< " pogolemi od 9:\n   ";
    copy( v3.begin(), v3.end(), output );

    // zameni gi vrednostite pogolemi od 9 vo v3 so 100
    replace_if( v3.begin(), v3.end(), greater9, 100 );

    cout << "\n v3 po zamena na site vrednosti pogolemi"<< " od 9 so 100ki:\n   ";
    copy( v3.begin(), v3.end(), output );

    vector< int > v4( a, a + SIZE );
    vector< int > c2( SIZE );

    cout << "\n\n v4 pred zamena na site vrednosti pogolemi "<< "od 9 i kopiranje:\n   ";
    copy( v4.begin(), v4.end(), output );

    // kopiraj go v4 vo c2, zameni gi vrednostite pogolemi od 9 so 100
    replace_copy_if(v4.begin(), v4.end(), c2.begin(), greater9, 100 );

    cout << "\n c2 po zamena na site vrednosti pogolemi "<< "od 9 vo v4:\n   ";
    copy( c2.begin(), c2.end(), output );

    cout << endl;

    return 0;

}

// opredeli dali argumentot e pogolem od 9
bool greater9( int x )
{
    return x > 9;

}
