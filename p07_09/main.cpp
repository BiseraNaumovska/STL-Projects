// STL Mathematicki algoritmi.


#include <iostream>

using namespace std;

#include <algorithm>
#include <numeric>    // definicija na accumulate
#include <vector>

bool greater9( int );
void outputSquare( int );
int calculateCube( int );

int main()
{
    const int SIZE = 10;
    int a1[] = { 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    vector< int > v( a1, a1 + SIZE );
    ostream_iterator< int > output( cout, " " );

    cout << " v pred random_shuffle: ";
    copy( v.begin(), v.end(), output );

    // izmesaj gi elementite na v
    random_shuffle( v.begin(), v.end() );

    cout << "\n v po random_shuffle: ";
    copy( v.begin(), v.end(), output );

    int a2[] = { 100, 2, 8, 1, 50, 3, 8, 8, 9, 10 };
    vector< int > v2( a2, a2 + SIZE );

    cout << "\n\n v2 sodrzi: ";
    copy( v2.begin(), v2.end(), output );

    // izbroj gi elementite na v2 so vrednost 8
    int result = count( v2.begin(), v2.end(), 8 );

    cout << "\nBroj na elementi so vrednost 8: " << result;

    // izbroj gi elementite na v2 so vrednost pogolema od 9
    result = count_if( v2.begin(), v2.end(), greater9 );

    cout << "\nBroj na elementi od v2 so vrednost pogolema od 9: " << result;

    // najdi ja lokacijata na minimalniot element na v2
    cout << "\n\n minimalen element na v2: "
         << *( min_element( v2.begin(), v2.end() ) );

    // najdi ja lokacijata na maksimalniot element na v2
    cout << "\n maksimalen element na v2: "
         << *( max_element( v2.begin(), v2.end() ) );

    // presmetaj suma na elementi vo v
    cout << "\n\n sumata na elementite na v e: "
         << accumulate( v.begin(), v.end(), 0 );

    cout << "\n\n kvadratite na elementite na v se:\n";

    // otpecati kvadrati na elementi na v
    //tretiot argument na for_each e funkcija
    //za sekoj element vo rangot for_each ja primenuva taa funkcija
    for_each( v.begin(), v.end(), outputSquare );

    vector< int > cubes( SIZE );

    //tretiot argument na transform e funkcija
    //za sekoj element vo rangot transform ja primenuva taa funkcija
    //i rezultatot go smestuva vo izleznite elementi

    // presmetaj kubovi na elementite na v i smesti gi vo vektor cubes
    transform(v.begin(), v.end(), cubes.begin(), calculateCube );

    cout << "\n\n kubovi na elementite vo v:\n";
    copy( cubes.begin(), cubes.end(), output );

    cout << endl;

    return 0;

}

// opredeli dali argumentot e pogolem od 9
bool greater9( int value )
{
    return value > 9;

} // kraj na greater9

// otpecati kvadrat na argumentot
void outputSquare( int value )
{
    cout << value * value << ' ';

} // kraj na outputSquare

// vrati kub na argumentot
int calculateCube( int value )
{
    return value * value * value;

} // kraj na calculateCube
