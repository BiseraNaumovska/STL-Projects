
// Naked pointers.


#include <iostream>
#include <cstddef>

using namespace std;


class Cat {
public:
    Cat() { cout << "Cat()" << endl; }
    ~Cat() { cout << "~Cat()" << endl; }
};

class Dog {
public:
    void* operator new(size_t sz) {
        cout << "alociram Dog" << endl;
        throw 47;
    }
    void operator delete(void* p) {
        cout << "dealociram Dog" << endl;
        delete p;
    }
};

class UseResources {
    Cat* bp;
    Dog* op;
public:
    UseResources(int count = 1) {
        cout << "UseResources()" << endl;
        bp = new Cat[count];
        op = new Dog;
    }
    ~UseResources() {
        cout << "~UseResources()" << endl;
        delete [] bp; // brisenje na poleto
        delete op;
    }
};



int main()
{
    try {
        UseResources ur(3);
    } catch(int) {
        cout << "vo handler" << endl;
    }

    return 0;
}
