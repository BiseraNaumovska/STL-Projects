// Se ignoriraat elementite za koi ne e zadovolen predikatot


// PREDIKATI

#include <algorithm>
#include <cstddef>

#include <iostream>

using namespace std;

// Korisnicki definiran predikat
bool gt15(int x) { return 15 < x; }

int main() {
    int a[] = { 0,15, 5, 10, 13, 25, 30, 2 };
    const size_t SIZE = sizeof a / sizeof a[0];
    int b[SIZE];
    int* endb = remove_copy_if(a, a+SIZE, b, gt15);
    int* beginb = b;
    while(beginb != endb)
        cout << *beginb++ << endl;
    cout<<endl;


    return 0;
}
