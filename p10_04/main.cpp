//  stack unwinding.
#include <iostream>
#include <stdexcept>
using namespace std;

// function3 frla run-time error
void function3() throw ( runtime_error )
{
    throw runtime_error( "runtime_error vo function3" );
}


void function2() throw ( runtime_error )
{
    function3();
}


void function1() throw ( runtime_error )
{
    function2();
}



int main()
{
    try {
        function1();

    }


    catch ( runtime_error &error )
    {
        cout << "Nastanal isklucok: " << error.what() << endl;

    }

    return 0;
}
