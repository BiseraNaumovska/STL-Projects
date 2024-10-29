
// Test programa za multimap.

#include <iostream>

using namespace std;

#include <map>  //definicija na map class-template
// definicija na multimap type pod ime mmid
typedef multimap< int, double, less< int > > mmid;




int main()
{
    mmid pairs;
    cout << "Ima " << pairs.count( 15 )
         << " parovi so kluc 15 vo pairs\n";
    // vmetni dva value_type objekti vo pairs
    pairs.insert( mmid::value_type( 15, 2.7 ) );
    pairs.insert( mmid::value_type( 15, 99.3 ) );

    cout << "Po vmetnuvanjeto ima "
         << pairs.count( 15 )
         << " parovi so kluc 15\n\n";

    // vmetni pet value_type objekti vo pairs
    pairs.insert( mmid::value_type( 30, 111.11 ) );
    pairs.insert( mmid::value_type( 10, 22.22 ) );
    pairs.insert( mmid::value_type( 25, 33.333 ) );
    pairs.insert( mmid::value_type( 20, 9.345 ) );
    pairs.insert( mmid::value_type( 5, 77.54 ) );

    //vmetnuvanje na objekt od tip pair
    pair< int, double > p;
    p.first=5; p.second=11.1;
    pairs.insert( p);
    //definiranje na tip na elementi kako pair i vmetnuvanje na
    //element preku konstruktor
    typedef pair< int, double > El;
    pairs.insert(El(5,10.5));
    cout << "Multimap pairs sodrzi:\nKluc\tVrednost\n";

    // koristi const_iterator za dvizenje niz elementite
    for ( mmid::const_iterator iter = pairs.begin();
         iter != pairs.end(); ++iter )
        cout << iter->first << '\t'
             << iter->second << '\n';
    cout << endl;
    return 0;

    return 0;
}
