#include <iostream>

using namespace std;

#include <vector>


// prototip za function template printVector
template < class T >
void printVector( const vector< T > &integers2 );



int main()
{
    const int SIZE = 6;
    int array[ SIZE ] = { 1, 2, 3, 4, 5, 6 };
    vector< int > integers;
    cout << "Pocetnata golemina na vector-ot integers e: "
         << integers.size()
         << "\nPocetniot kapacitet na vector-ot integers e: "
         << integers.capacity();
    // Dodavanje na elementi
    integers.push_back( 2 );
    integers.push_back( 3 );
    integers.push_back( 4 );
    cout << "\nGoleminata na vector-ot integers e: " << integers.size()
         << "\nKapacitetot na vector-ot integers: "
         << integers.capacity();
    cout << "\n\nPrikaz na pole preku pokazuvaci: ";
    for ( int *ptr = array; ptr != array + SIZE; ++ptr )
        cout << *ptr << ' ';
    cout << "\nPrikaz na vector preku iterator: ";
    printVector( integers );
    cout << "\nInvertirana sodrzina na vector: ";
    vector< int >::reverse_iterator reverseIterator;
    for ( reverseIterator = integers.rbegin();
         reverseIterator!= integers.rend();
         ++reverseIterator )
        cout << *reverseIterator << ' ';
    cout << endl;
    return 0;
}


template < class T >
void printVector( const vector< T > &integers2 )
{
    vector< T >::const_iterator constIterator;
    for ( constIterator = integers2.begin(); constIterator != integers2.end(); constIterator++ )
        cout << *constIterator << ' ';
}
