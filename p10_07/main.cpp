/*
1.      Напиши програма која демонстрира дека ако е фрлен покажувач на
создаден објект, објектот нема да биде уништен.
*/


#include <iostream>

using namespace std;

class Sample {
public:
    Sample() {
        cout << "Konstruktor." << endl;
    }

    ~Sample() {
        cout << "Destruktor." << endl;
    }

    void display() {
        cout << "Display." << endl;
    }
};



int main()
{
    Sample* obj = new Sample();

    obj->display();
    obj = nullptr;
    Sample* anotherPointer = new Sample();
    anotherPointer->display();

    delete anotherPointer;



    return 0;
}
