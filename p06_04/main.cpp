// Test programa za map .

#include <iostream>

using namespace std;

#include <map>  // definicija na map class-template
// definicija na map type pod ime mid
typedef map< int, double, less< int > > mid;


int main()
{
    mid pairs;
    // vmetni osum value_type objekti vo pairs
    pairs.insert( mid::value_type( 15, 2.7 ) );
    pairs.insert( mid::value_type( 30, 111.11 ) );
    pairs.insert( mid::value_type( 5, 1010.1 ) );
    pairs.insert( mid::value_type( 10, 22.22 ) );
    pairs.insert( mid::value_type( 25, 33.333 ) );
    pairs.insert( mid::value_type( 5, 77.54 ) ); // duplikat, se ignorira
    pairs.insert( mid::value_type( 20, 9.345 ) );
    pairs.insert( mid::value_type( 15, 99.3 ) ); // duplikat, se ignorira
    cout << "pairs sodrzi:\nKluc\tVrednost\n";

    // koristi const_iterator za dvizenje niz elementite na pairs
    for ( mid::const_iterator iter = pairs.begin();iter != pairs.end(); ++iter )
        cout << iter->first << '\t'<< iter->second << '\n';
    // koristi subscript operator za promena na vrednosta za klucot 25
    pairs[ 25 ] = 9999.99;

    // koristi subscript operator za promena na vrednosta za klucot 40
    pairs[ 40 ] = 8765.43;

    cout << "\nPo subscript operaciite, pairs sodrzi:"
         << "\nKluc\tVrednost\n";

    for ( mid::const_iterator iter2 = pairs.begin();iter2 != pairs.end(); ++iter2 )
        cout << iter2->first << '\t'<< iter2->second << '\n';
    cout << endl;

    return 0;
}
