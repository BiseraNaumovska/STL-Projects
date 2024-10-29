//Nasleduvanje od std::runtime_error.

#include <iostream>
#include <stdexcept>
using namespace std;


class MyError : public runtime_error {
public:
    MyError(const string& msg = "") : runtime_error(msg) {}
};



int main()
{
    try {
        throw MyError("Moja poraka");
    } catch(MyError& x) {
        cout << x.what() << endl;
    }

    return 0;
}
