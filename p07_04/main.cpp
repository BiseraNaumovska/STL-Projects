// Upotreba na stream iterator.
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
using namespace std;

bool gt15(int x) { return 15 < x; }

int main() {
    int a[] = { 10, 20, 30 };

    ostream_iterator<int> output(cout, "\n") ;

    const size_t SIZE = sizeof a / sizeof a[0];
    cout << "Pecatenje so copy: \n";
    copy(a, a + SIZE, output);

    cout << "Rezultat od remove_copy_if:\n";
    remove_copy_if(a, a + SIZE,output, gt15);

    return 0;
}
