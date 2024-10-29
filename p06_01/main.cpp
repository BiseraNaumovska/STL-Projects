
// Testiranje na funkcii  na multiset

#include <iostream>
#include <set>
using namespace std;


// definicija na int multiset type od ime ims
typedef multiset< int, less< int > > ims;
#include <algorithm>



int main()
{
    const int SIZE = 10;
    int a[ SIZE ] = { 7, 22, 9, 1, 18, 30, 100, 22, 85, 13 };
    ims intMultiset;
    ostream_iterator< int > output( cout, " " );
    cout << "Ima " << intMultiset.count( 15 )
         << " pojavuvanja na 15 vo intMultiset\n";

    intMultiset.insert( 15 );  // vmetni 15 vo intMultiset
    intMultiset.insert( 15 );  // vmetni 15 vo intMultiset
    cout << "Po vmetnuvanjeto, ima "
         << intMultiset.count( 15 )
         << " vrednosti 15 vo intMultiset\n\n";
    ims::const_iterator result;
    // pronajdi 15 vo intMultiset; find vrakja iterator
    result = intMultiset.find( 15 );
    if ( result != intMultiset.end() ) // ako iteratorot ne e na kraj
        cout << "Pronajdena vrednost 15\n";     // pronajdena e vrednost 15

    // pronajdi 20 vo intMultiset; find vrakja iterator
    result = intMultiset.find( 20 );
    if ( result == intMultiset.end() )    // ==true
        cout << "Ne e pronajdena vrednost 20\n"; //ne e najdena 20
    // vmetni elementi od poleto array vo intMultiset
    intMultiset.insert( a, a + SIZE );
    cout << "\nPo vmetnuvanjeto, intMultiset sodrzi:\n";
    copy( intMultiset.begin(), intMultiset.end(), output );

    // najdi go prvoto i poslednoto pojavuvanje na 22 vo intMultiset
    cout << "\n\nPrvo pojavuvanje na 22: "
         << *( intMultiset.lower_bound( 22 ) );
    cout << "\nPosledno pojavuvanje na 22: "
         << *( intMultiset.upper_bound( 22 ) );
    // p e par od const_iterators
    pair< ims::const_iterator, ims::const_iterator > p;
    // opredeli prvoto i poslednoto pojavuvanje na 22 preku
    p = intMultiset.equal_range( 22 );
    cout << "\n\nequal_range na 22:"
         << "\n   Prvo pojavuvanje: " << *( p.first )
         << "\n   Posledno pojavuvanje: " << *( p.second );
    cout << endl;

    return 0;
}
