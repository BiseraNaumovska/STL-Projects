/*
3.    Формирај deque d од цели броеви. Потоа формирај vector v од елементите
на d, но во обратен редослед.
*/
#include <iostream>
#include <deque>      // deque class-template definicija
#include <algorithm>
#include <vector>
#include <iterator>
using namespace std;

int main()
{
    deque<int> d = {1,5,4,9,2,4,3,6,7};
    vector<int> v(d.rbegin(), d.rend());


    cout << "Elementite na deque d: ";
    for ( auto it = d.begin(); it != d.end(); ++it)
        cout << *it << " ";
    cout<<endl;

    cout << "Elementite na deque v: ";
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << " ";
    cout<<endl;



    return 0;
}
