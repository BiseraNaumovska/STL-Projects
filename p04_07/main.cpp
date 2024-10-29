/*
3. За текст внесен од тастатура прикажи ги сите зборови од кои се состои
текстот по еднаш, во абецеден редослед.
*/
#include <iostream>
#include <sstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
    string tekst="ova e eden tekst so tri povtoreni zborovi bla bla bla";

    vector<string> zborovi;

    istringstream stream(tekst); // za da se chita zbor po zbor
    string zbor;
    while (stream >> zbor) {
        if (find(zborovi.begin(), zborovi.end(), zbor) == zborovi.end()) {
            zborovi.push_back(zbor); // ako nema duplikat, go dodavame
        }
    }

    sort(zborovi.begin(), zborovi.end());

    cout << "Zborovite vo tekstot (po ednash, abeceden redosled):\n";
    for (const auto& z : zborovi) {
        cout << z << endl;
    }

    return 0;
}
