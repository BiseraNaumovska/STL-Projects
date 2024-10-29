
//  set_difference, set_intersection, set_symmetric_difference i set_union

#include <iostream>

using namespace std;
#include <algorithm>
#include <iterator>

int main()
{
    const int SIZE1 = 10, SIZE2 = 5, SIZE3 = 20;
    int a1[ SIZE1 ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    int a2[ SIZE2 ] = { 4, 5, 6, 7, 8 };
    int a3[ SIZE2 ] = { 4, 5, 6, 11, 15 };
    ostream_iterator< int > output( cout, " " );
    cout << "a1 sodrzi: ";
    copy( a1, a1 + SIZE1, output );
    cout << "\na2 sodrzi: ";
    copy( a2, a2 + SIZE2, output );
    cout << "\na3 sodrzi: ";
    copy( a3, a3 + SIZE2, output );

    // opredeli dali a2 se sodrzi vo a1
    if ( includes( a1, a1 + SIZE1, a2, a2 + SIZE2 ) )
        cout << "\n\na1 go sodrzi a2";
    else
        cout << "\n\na1 ne go sodrzi a2";

    // opredeli dali a3 se sodrzi vo a1
    if ( includes( a1, a1 + SIZE1, a3, a3 + SIZE2 ) )
        cout << "\na1 go sodrzi a3";
    else
        cout << "\na1 ne go sodrzi a3";



    int difference[ SIZE1 ];
    // opredeli koi elementi od a1 ne se vo a2
    int *ptr = set_difference( a1, a1 + SIZE1,a2, a2 + SIZE2, difference );
    cout << "\n\nset_difference na a1 i a2 e: ";
    copy( difference, ptr, output );


    int intersection[ SIZE1 ];
    // opredeli presek na a1 i a2
    ptr = set_intersection( a1, a1 + SIZE1,a2, a2 + SIZE2, intersection );
    cout << "\n\nset_intersection na a1 i a2 e: ";
    copy( intersection, ptr, output );


    int symmetric_difference[ SIZE1 ];
    // najdi gi elementite vo a1 sto ne se vo a2 i
    // elementite od a2 sto ne se vo a1
    ptr = set_symmetric_difference( a1, a1 + SIZE1,a2, a2 + SIZE2, symmetric_difference );
    cout << "\n\nset_symmetric_difference na a1 i a2 e: ";
    copy( symmetric_difference, ptr, output );


    int unionSet[ SIZE3 ];
    // opredeli unija na a1 i a3
    ptr = set_union( a1, a1 + SIZE1,a3, a3 + SIZE2, unionSet );
    cout << "\n\nset_union na a1 i a3 e: ";
    copy( unionSet, ptr, output );

    cout << endl;

    return 0;
}
