/*
2.      Напиши програма што определува дали два збора се анаграми. Два збора се нарекуваат анаграми ако се состојат од исти букви (Пр. стакло и слатко). Притоа користи vector. За споредба  на еднаквост на два вектори може да се користи:
      std::equal( v1.begin(), v1.end(), v2.begin() );
која враќа bool вредност.

*/
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


bool seAnagrami(const string& zbor1, const string& zbor2) {
    if (zbor1.length() != zbor2.length()) {
        return false;
    }

    vector<char> v1(zbor1.begin(), zbor1.end());
    vector<char> v2(zbor2.begin(), zbor2.end());

    sort(v1.begin(), v1.end());
    sort(v2.begin(), v2.end());

    return equal(v1.begin(), v1.end(), v2.begin());
}


int main()
{
    string zbor1, zbor2;

    cout << "Vnesi prv zbor: ";
    cin >> zbor1;
    cout << "Vnesi prv zbor: ";
    cin >> zbor2;

    if (seAnagrami(zbor1, zbor2)) {
        cout << "Zborovite \"" << zbor1 << "\" i \"" << zbor2 << "\" se anagrami.\n";
    } else {
        cout << "Zborovite \"" << zbor1 << "\" i \"" << zbor2 << "\" NE se anagrami.\n";
    }
    return 0;
}
