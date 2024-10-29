// Frlanje na bad_alloc isklucok koga ne moze da se alocira memorija

#include <iostream>

using namespace std;
#include <new>


int main()
{
    double *ptr[ 50 ];

    // obid da se alocira memorija
    try {


        // frli bad_alloc pri neuspeh
        for ( int i = 0; i < 50; i++ ) {
            ptr[ i ] = new double[ 5000000 ];
            cout << "Alocirani 5000000 double elementi ptr[ "<< i << " ]\n";
        }

    }
    catch ( bad_alloc &memoryAllocationException ) {
        cout << "Nastanal isklucok: "<< memoryAllocationException.what() << endl;
        for(int j=0; j<i;j++)
            delete ptr[j];


    }

    return 0;

}
