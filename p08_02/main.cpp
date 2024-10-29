// iter_swap, swap i swap_ranges.

#include <iostream>

using namespace std;

#include <algorithm>
#include <iterator>


int main()
{
    const int SIZE = 10;
    int a[ SIZE ] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };
    ostream_iterator< int > output( cout, " " );
    cout << "Poleto a sodrzi:\n   ";
    copy( a, a + SIZE, output );
    // zameni gi elementite na lokacija 0 and 1
    // swap razmenuva dve vrednosti
    swap( a[ 0 ], a[ 1 ] );
    cout << "\na po zamena na a[0] i a[1] so swap \n";
    copy( a, a + SIZE, output );
    // koristi iteratori za zamena na elementi
    iter_swap( &a[ 0 ], &a[ 1 ] );
    cout << "\na po zamena na a[0] i a[1] so iter_swap\n";
    copy( a, a + SIZE, output );
    // zameni gi prvite 5 so poslednite 5 elementi
    swap_ranges( a, a + 5, a + 5 );
    cout << "\n a po zamena na ptvite 5 so poslednite 5 elementi\n";
    copy( a, a + SIZE, output );
    cout << endl;
    sort(a, a+SIZE);
    copy( a, a + SIZE, output );
    cout << endl;
    swap_ranges(a, a+2,a+8);
    copy( a, a + SIZE, output );
    cout << endl;
    return 0;
} // kraj na main
