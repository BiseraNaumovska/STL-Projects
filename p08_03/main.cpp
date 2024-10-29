
// copy_backward, merge, unique i reverse

#include <iostream>

using namespace std;

#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
    const int SIZE = 5;
    int a1[ SIZE ] = { 1, 3, 5, 7, 9 };
    int a2[ SIZE ] = { 2, 4, 5, 7, 9 };

    vector< int > v1( a1, a1 + SIZE );
    vector< int > v2( a2, a2 + SIZE );
    ostream_iterator< int > output( cout, " " );
    cout << " v1 sodrzi: ";
    copy( v1.begin(), v1.end(), output );
    cout << "\n v2 sodrzi: ";
    copy( v2.begin(), v2.end(), output );
    vector< int > results( v1.size() );
    // iskopiraj gi elementite na v1 vo results vo obraten redosled
    //copy_backward kopira od desno kon levo
    copy_backward( v1.begin(), v1.end(), results.end() );
    cout << "\n\n po copy_backward, results sodrzi: ";
    copy( results.begin(), results.end(), output );

    vector< int > results2( v1.size() + v2.size() );
    // spoi gi elementite na v1 i v2 vo results2 sortirani
    // results2 mora da ima golemina baremkolku zbirot na
    // goleminite na v1 i v2
    merge( v1.begin(), v1.end(), v2.begin(), v2.end(),results2.begin() );
    cout << "\n\n po merge na v1 i v2 results2 sodrzi:\n";
    copy( results2.begin(), results2.end(), output );

    // izbrisi gi duplite elementi od results2
    vector< int >::iterator endLocation;
    endLocation = unique( results2.begin(), results2.end() );
    cout << "\n\n po unique results2 sodrzi:\n";
    copy( results2.begin(), endLocation, output );

    cout << "\n\n v1 po reverse: ";

    // invertiraj gi elementite na v1
    reverse( v1.begin(), v1.end() );
    copy( v1.begin(), v1.end(), output );
    cout << endl;
    return 0;
} // kraj na main
