
// Primer za exception-handling koj
// proveruva dali se pojavuva delenje so 0


#include <iostream>
#include <exception>
using namespace std;



//funkcii koi detektiraat delenje so 0 treba da frlat
// objekt DivideByZeroException
class DivideByZeroException : public exception {
public:
    // konstructorot ja opredeluva default error message
    DivideByZeroException() noexcept = default;

    // Preoptovaruvanje na metodot what() za da vratime prilagodena poraka
    virtual const char* what() const noexcept override {
        return "obid za delenje so nula";
    }
};  // end class DivideByZeroException
// izvrsi delenje i frli DivideByZeroException objekt
// ako nastane delenje so nula
double quotient( int numerator, int denominator )
{
    // frli DivideByZeroException
    if ( denominator == 0 )
        throw DivideByZeroException(); // prekin na funkcijata

    return static_cast< double >( numerator ) / denominator;
}  // kraj na funkcijata quotient
int main()
{
    int number1;    // delenik
    int number2;    // delitel
    double result;  // kolicnik
    cout << "Vnesi dva celi broja (end-of-file za kraj): ";

    while ( cin >> number1 >> number2 ) {

        // try block sodrzi kod sto moze da frli isklucok

        try {
            result = quotient( number1, number2 );
            cout << "Kolicnikot e: " << result << endl;
        } // kraj na try
        // exception handler za isklucok delenje so nula
        catch ( DivideByZeroException &divideByZeroException ) {
            cout << "Nastanal isklucok: " << divideByZeroException.what() << endl;
        } // kraj na catch
        cout << "\nVnesi dva celi broja (end-of-file za kraj): ";
    }
    cout << endl;
    return 0;
}  // kraj na main
