//  lower_bound, upper_bound i equal_range
// za sortirana niza od vrednosti.



#include <iostream>

using namespace std;
#include <algorithm>
#include <vector>
#include <iterator>

int main()
{
    const int SIZE = 10;
    int a1[] = { 2, 2, 4, 4, 4, 6, 6, 6, 6, 8 };
    vector< int > v( a1, a1 + SIZE );
    ostream_iterator< int > output( cout, " " );

    cout << " v sodrzi:\n";
    copy( v.begin(), v.end(), output );

    // opredeli najleva granica za vmetnuvanje na 6 vo v
    // potrebno e v da e sortirana
    vector< int >::iterator lower;
    lower = lower_bound( v.begin(), v.end(), 6 );

    cout << "\n\nLower bound za 6 e elementot "<< ( lower - v.begin() ) << " od v";


    // opredeli najdesna granica za vmetnuvanje na 6 vo v
    // potrebno e v da e sortirana
    vector< int >::iterator upper;
    upper = upper_bound( v.begin(), v.end(), 6 );
    cout << "\nUpper bound za 6 e elementot "<< ( upper - v.begin() ) << " of vector v";


    // so equal_range opredeli gi lower- i
    // upper-bound za 6
    // potrebno e v da e sortirana
    pair< vector< int >::iterator,vector< int >::iterator > eq;
    eq = equal_range( v.begin(), v.end(), 6 );
    cout << "\nSo equal_range:\n"
         << "   Lower bound za 6 e elementot "
         << ( eq.first - v.begin() ) << " od v";
    cout << "\n   Upper bound za 6 e elementot "
         << ( eq.second - v.begin() ) << " od v";

    cout << "\n\nSo lower_bound najdi ja prvata lokacija\n"
         << "na koja 5 moze da se vmetne vo sortiran redosled";
    // opredeli najleva granica za vmetnuvanje na 5 vo v

    lower = lower_bound( v.begin(), v.end(), 5 );
    cout << "\n   Lower bound za 5 e elementot "
         << ( lower - v.begin() ) << " od v";

    cout << "\n\nSo uper_bound najdi ja prvata lokacija\n"
         << "na koja 7 moze da se vmetne vo sortiran redosled";
    // opredeli najdesna granica za vmetnuvanje na 7 vo v
    upper = upper_bound( v.begin(), v.end(), 7 );
    cout << "\n   Upper bound za 7 e elementot "
         << ( upper - v.begin() ) << " od v";
    cout << "\n\nSo equal_range najdi ja prvata i poslednata lokacija\n"
         << "na koja 5 moze da se vmetne vo sortiran redosled";
    // so equal_range opredeli gi lower- i
    // upper-bound za 5
    eq = equal_range( v.begin(), v.end(), 5 );
    cout << "\n   Lower bound za 5 e elementot "
         << ( eq.first - v.begin() ) << " od v";
    cout << "\n   Upper bound za 5 e elementot "
         << ( eq.second - v.begin() ) << " od v"
         << endl;

    return 0;
}
