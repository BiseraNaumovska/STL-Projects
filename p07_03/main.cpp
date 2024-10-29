// ITERATORI

// Upotreba na stream iterator.
#include <algorithm>
#include <cstddef>
#include <iostream>
#include <iterator>
using namespace std;

int main() {
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];
    copy(a, a + SIZE, ostream_iterator<int>(cout, "\n"));
    return 0;
}
