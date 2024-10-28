/*
Преклопи го function template-от printArray со
non-template функција која печати поле од int во четири
порамнети колони.
*/
#include <iostream>
#include <iomanip>
using namespace std;

// Definicija na function template printArray

template< class T >  //*
void printArray( const T *array, const int count )//**
{
    for ( int i = 0; i < count; i++ )
        cout << array[ i ] << " ";
    cout << endl;

} // Kraj na function template printArray


template< class T >  //*
int printArray( const T *array, const int count,  int low,  int high )//**
{
    if(low<0 || high>=count || low> high){
        return 0;
    }
    for ( int i = low; i <=high; i++ )
        cout << array[ i ] << " ";
    cout << endl;
    return (high-low +1);

} // Kraj na function template printArray

void printArray (const int *niza, const int count){
    for(int i=0;i<count;i++){
        cout<<setw(10)<<niza[i];
        if ((i + 1) % 4 == 0) { // Po sekoj chetvrti element, premesti vo nov red
            cout << endl;
        }
    }
    if (count % 4 != 0) {
        cout << endl;
    }
}




int main()
{
    const int aCount = 5;
    const int bCount = 7;
    const int cCount = 6;

    int a[aCount] = {1, 2, 3, 4, 5};
    double b[bCount] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6, 7.7};
    char c[cCount] = "HELLO";

    cout << "Poleto a sodrzi:" << endl;
    //so ova ke se povika non-tamplate funkcijata i ke se ispechati vo 4 koloni
    printArray(a, aCount); // Pechatenje na celiot niz

    cout << "Pechatenje na elementi na poleto a od indeks 1 do 3:" << endl;
    int printedCountA = printArray(a, aCount, 1, 3);
    cout << "Broj na pechateni elementi: " << printedCountA << endl;

    cout << "\nPoleto b sodrzi:" << endl;
    printArray(b, bCount); // Pechatenje na celiot niz

    cout << "Pechatenje na elementi na poleto b od indeks 2 do 5:" << endl;
    int printedCountB = printArray(b, bCount, 2, 5);
    cout << "Broj na pechateni elementi: " << printedCountB << endl;

    cout << "\nPoleto c sodrzi:" << endl;
    printArray(c, cCount); // Pechatenje na celiot niz

    cout << "Pechatenje na elementi na poleto c od indeks 0 do 4:" << endl;
    int printedCountC = printArray(c, cCount, 0, 4);
    cout << "Broj na pechateni elementi: " << printedCountC << endl;

    return 0;

} // kraj na main
