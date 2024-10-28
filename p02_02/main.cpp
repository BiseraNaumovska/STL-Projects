//Следниот function template пресметува сума на низа од елементи:
#include <iostream>

using namespace std;


template<class T >
T sum(T* b, T* e, T init = T()) { // inti na pochetok ke ima vrednost 0
    while(b != e)
        init += *b++;
    return init;
}

int main()
{
    float a[] = { 1.5, 2, 3, 4, 5, 6};
    cout << sum(a, a + sizeof a / sizeof a[0]) << endl; // 6

    return 0;
}
