// Kopira pole od celi broevi so copy.
#include <iostream>

using namespace std;

#include <algorithm> //definicii na algoritmite
#include <cstddef>
#include <vector>

int main()
{
    //pole od celi broevi so copy.
    int a[] = { 10, 20, 30 };
    const size_t SIZE = sizeof a / sizeof a[0];
    int b[SIZE];
    copy(a, a + SIZE, b);

    //upotreba na copy kaj vector objekti
    int a1[] = { 10, 20, 30 };
    const size_t SIZE1 = sizeof a1 / sizeof a1[0];
    vector<int> v1(a1, a1 + SIZE1);
    vector<int> v2(SIZE1);
    copy(v1.begin(), v1.end(), v2.begin());


    return 0;
}
