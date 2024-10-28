//3. Во следниот пример компајлерот воопшто нема да генерира класа:
#include <iostream>

using namespace std;
template <class T>
class Z
{
public:
    Z() {cout <<”Konstruktor\n”;}
    ~Z() { cout <<”Destruktor\n”;}
    void f(){} ;
    void g(){} ;
} ;

int main()
{
    Z<int>* p_zi ; //Instanciranje na Z<int> ne e potrebno
    Z<float>* p_zf ; //Instanciranje na Z<float> ne e potrebno

    return 0;
}
