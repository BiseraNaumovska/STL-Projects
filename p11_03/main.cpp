//Следниот пример содржи креирање и читање на датотека во која содржината
//се структурира како запис кој содржи сметка, име и состојба.
// Rabota so sekvencijalna datoteka.


#include <iostream>
#include <fstream>
#include <iomanip>
#include <cstdlib>
using namespace std;

void outputLine( int, const char * const, double );

int main()
{
    // konstruktorot na ofstream otvora datoteka
    ofstream outClientFile( "clients.dat", ios::out );


    if ( !outClientFile ) {  // preklopen ! operator za ofstream
        cerr << "Datotekata ne moze da se otvori" << endl;
        exit( 1 );

    }

    cout << "Vnesi broj na smetka, ime, i sostojba." << endl
         << "Vnesi end-of-file za kraj na vnes.\n? ";

    int account;
    char name[ 30 ];
    double balance;


    while ( cin >> account >> name >> balance ) {
        outClientFile << account << ' ' << name << ' ' << balance
                      << endl;
        cout << "? ";

    }
    //zatvoranje na datotekata
    outClientFile.close();

    // konstruktorot na ifstream ja otvora istata datoteka za citanje
    ifstream inClientFile( "clients.dat", ios::in );


    if ( !inClientFile ) {
        cerr << "Datotekata ne moze da se otvori" << endl;
        exit( 1 );

    }

    cout << left << setw( 10 ) << "Smetka" << setw( 13 )
         << "Ime" << "Sostojba" << endl << fixed << showpoint;

    // prikazi go sekoj zapis
    while ( inClientFile >> account >> name >> balance )
        outputLine( account, name, balance );

    return 0;  // destruktorot na ofstream ja zatvora datotekata
}



void outputLine( int account, const char * const name,double balance )
{
    cout << left << setw( 10 ) << account << setw( 13 ) << name
         << setw( 7 ) << setprecision( 2 ) << right << balance
         << endl;

}
