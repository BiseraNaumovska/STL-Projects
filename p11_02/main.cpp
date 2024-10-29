// hex, oct, dec, setbase, precision, setprecision
#include <iostream>
#include <iomanip>
#include <cmath>

using namespace std;

int main()
{
    int number;

    cout << "Vnesi dekaden broj: ";
    cin >> number;


    cout <<" hex: " << hex << number << " oct: "
         << oct << number << setbase( 10 ) << " dec: "
         << number << endl;

    double root2 = sqrt( 2.0 );
    int places;

    cout << "Koren od 2 so preciznost 0-4." << endl
         << "postavena so ios_base::precision \n";

    cout << fixed;

    for ( places = 0; places <= 4; places++ ) {
        cout.precision( places );
        cout << root2 << endl;
    }

    cout << "\nPreciznost postavena so setprecision\n " ;

    for ( places = 0; places <= 4; places++ )
        cout << setprecision( places ) << root2 << endl;

    return 0;
}
