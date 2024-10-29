/*
Следниот пример ја илустрира употребата на контејнерите.
Во него се применуваат итератори и алгоритми, за кои ќе стане збор подетално
понатаму во текстот.

•	Креирање на вектор е едноставно. default консрукторот креира празен
    вектор. Push_back() додава елементи на крај на векторот.
•	Векторот се сортира преку еден повик на генеричкиот алгоритам sort.
•	Векторот се инвертира преку еден повик на генеричкиот алгоритам reverse.
•	sort() и reverse() како аргументи користат итератори. Методата begin()
    на класата vector враќа итератор на почетокот на векторот; end() враќа
    итератор една позиција после крајот на векторот.

Sekvencijalni kontejneri

*/


#include <vector>
#include <iostream>
#include <algorithm>

using namespace std;

int main( )
{
    // Kreira prazen vektor
    vector <int> v1;
    // size_type vo zaglavnata datoteka na vector

    int i;
    // Dodaj elementi na krajot na v1
    v1.push_back(5);
    v1.push_back(12);
    v1.push_back(1);
    v1.push_back(392);
    // Otpecati go vektorot
    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    // Sortiranje
    sort(v1.begin(),v1.end());
    // Otpecati go vektorot
    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    // Invertiranje
    reverse(v1.begin(),v1.end());
    // Otpecati go vektorot
    for (i = 0; i < v1.size(); i++) {
        cout << v1[i] << " ";
    }
    cout << endl;
    return 0;
}
