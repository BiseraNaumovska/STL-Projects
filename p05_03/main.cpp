// Test programa za STL list class template.
#include <iostream>
#include <list>       // list class-template definicija
#include <algorithm>

using namespace std;

template < class T >
void printList( const list< T > &listRef );


int main()
{
    const int SIZE = 4;
    int array[ SIZE ] = { 2, 6, 4, 8 };
    list< int > values;
    list< int > otherValues;
    // vmetnuvanje elementi vo listata values
    values.push_front( 1 );
    values.push_front( 2 );
    values.push_back( 4 );
    values.push_back( 3 );

    cout << "values sodrzi: ";
    printList( values );
    values.sort();  // sortiraj
    cout << "\nvalues po sortiranje: ";
    printList( values );

    // vmetni gi elementite od poleto array vo otherValues
    otherValues.insert( otherValues.begin(),
                       array, array + SIZE );
    cout << "\notherValues po dodavanje elementi: ";
    printList( otherValues );
    // ostrani elementi od otherValues i dodaj gi na kraj na values
    values.splice( values.end(), otherValues );

    cout << "\nvalues po splice: ";
    printList( values );
    cout << "\notherValues po splice: ";
    printList( otherValues );
    values.sort();  // sortiraj go values
    cout << "\nvalues po sort: ";
    printList( values );
    // vmetni gi elementite od poleto array vo otherValues
    otherValues.insert( otherValues.begin(),
                       array, array + SIZE );
    otherValues.sort();

    cout << "\notherValues po dodavanje elementi: ";
    printList( otherValues );

    // ostrani elementi od otherValues i dodaj gi vo values sortirani
    values.merge( otherValues );

    cout << "\nPo merge:\n   values sodrzi: ";
    printList( values );
    cout << "\n   otherValues sodrzi: ";
    printList( otherValues );
    values.pop_front();  // otstrani go elementot na pocetok
    values.pop_back();   // otstrani go elementot na kraj

    cout << "\nPo pop_front i pop_back:"
         << "\n   values sodrzi: ";
    printList( values );

    values.unique();  // ostrani dupli elementi

    cout << "\nPo unique, values sodrzi: ";
    printList( values );
    // razmeni gi elementite na values i otherValues
    values.swap( otherValues );

    cout << "\nPo swap:\n   values sodrzi: ";
    printList( values );
    cout << "\n   otherValues sodrzi: ";
    printList( otherValues );
    // zameni ja sodrzinata na values so elementi od otherValues
    values.assign( otherValues.begin(), otherValues.end() );

    cout << "\nPo assign, values sodrzi: ";
    printList( values );
        // ostrani elementi od otherValues i dodaj gi vo values sortirani
    values.merge( otherValues );

    cout << "\nPo merge, values sodrzi: ";
    printList( values );

    values.remove( 4 );  // otstrani ki site 4-ki

    cout << "\nPo remove( 4 ), values sodrzi: ";
    printList( values );
    cout << endl;
    return 0;
}


// ostream_iterator i copy algoritam za pecatenje na elementi
template < class T >
void printList( const list< T > &listRef )
{
    if ( listRef.empty() )
        cout << "Listаta e prazna";
    else {
        ostream_iterator< T > output( cout, " " );
        copy( listRef.begin(), listRef.end(), output );
    }
} // kraj na printList
