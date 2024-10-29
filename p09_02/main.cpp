// Demonstrira exception rethrowing

#include <iostream>
#include <exception>
using namespace std;
// throw, catch i rethrow



void throwException()
{

    try {
        cout << "  Funkcijata throwException frla isklucok\n";
        throw exception();
    }

    catch ( exception &caughtException ) {
        cout << "  Isklucok obraboten vo funkcijata throwException"
             << "\n  Funkcijata throwException povtorno go frla isklucokot";
        throw;
    }
    cout << "Ova ne treba da se otpecati\n";
}  // kraj na throwException




int main()
{

    try {
        cout << "\nmain povikuva funkcija throwException\n";
        throwException();
        cout << "Ova ne treba da se otpecati\n";
    }

    catch ( exception &caughtException ) {
        cout << "\n\nIsklucok obraboten vo main\n";
    }
    cout << "Programata prodolzuva po catch vo main\n";
    return 0;
}
