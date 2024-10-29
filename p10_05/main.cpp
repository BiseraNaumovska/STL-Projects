//  new vrakja 0 koga ne e alocirana memorija
#include <iostream>

using namespace std;

int main()
{
    double *ptr[ 50 ];
    int i = 0;
    // alociraj memorija za ptr
    for ( i = 0; i < 50; i++ ) {
        ptr[ i ] = new double[ 5000000 ];

        // new vrakja 0 pri neuspeh
        if ( ptr[ i ] == 0 ) {
            cout << "Alociranje na memorija neuspesno za ptr[ " << i << " ]\n";

            break;

        }


        else
            cout << "Alocirani 5000000 double elementi ptr[ "
                 << i << " ]\n";

    }
    for (int j = 0; j < i; j++) {
        delete[] ptr[j];
    }

    return 0;

}
