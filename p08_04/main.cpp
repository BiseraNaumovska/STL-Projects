
// inplace_merge,reverse_copy i unique_copy

#include <iostream>

using namespace std;

#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
    const int SIZE = 10;
    int a1[ SIZE ] = { 1, 3, 5, 7, 9, 1, 2, 5, 7, 9 };
    vector< int > v1( a1, a1 + SIZE );
    ostream_iterator< int > output( cout, " " );
    cout << " v1 sodrzi: ";
    copy( v1.begin(), v1.end(), output );

    // inplace_merge spojuva dve nizi od elementi vo ist kontejner
    //spoj ja prvata polovina na v1 so vtorata taka sto
    //po spojuvanjeto v1 ke bide sortirano
    //potrebno e dvete polovini da bidat sortirani
    inplace_merge( v1.begin(), v1.begin() + 5, v1.end() );
    cout << "\n po inplace_merge, v1 sodrzi: ";
    copy( v1.begin(), v1.end(), output );

    vector< int > results1;
    // kopiraj gi po ednas elementite od v1 vo results1
    unique_copy(v1.begin(), v1.end(), back_inserter( results1 ) );
    cout << "\n po unique_copy results1 sodrzi: ";
    copy( results1.begin(), results1.end(), output );

    vector< int > results2;

    cout << "\n po reverse_copy na v1 vo results2, results2 sodrzi: ";

    // kopiraj gi elementite na v1 vo results2 vo obraten redosled
    reverse_copy(v1.begin(), v1.end(), back_inserter( results2 ) );
    copy( results2.begin(), results2.end(), output );
    cout << endl;

    return 0;
}
