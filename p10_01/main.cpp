
// Demonstacija na auto_ptr.

#include <iostream>

using namespace std;

#include <memory>

//using std::auto_ptr; // definicija na klasata auto_ptr

class Integer {
public:

    // Integer konstruktor
    Integer( int i = 0 ) : value( i )
    {
        cout << "Konstruktor za Integer " << value << endl;

    }

    // Integer destruktor
    ~Integer()
    {
        cout << "Destruktor za Integer " << value << endl;

    }
    void setInteger( int i )
    {
        value = i;

    }

    int getInteger() const
    {
        return value;

    }

private:
    int value;

};  // kraj na klasa Integer


int main()
{
    cout << "Kreiranje na auto_ptr objekt sto pokazuva na Integer\n";

    // postavi auto_ptr
    //unique_ptr se koristi vo ponovite verzii na C++
    auto_ptr< Integer > ptrToInteger( new Integer( 7 ) );

    cout << "\nUpotrebuvam auto_ptr za manipuliranje so Integer\n";


    ptrToInteger->setInteger( 99 );


    cout << "Integer po setInteger: "<< ( *ptrToInteger ).getInteger()<< "\n\n\kraj na programata" << endl;

    return 0;

}
