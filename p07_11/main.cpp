/*
2.      Напиши програма за играње на едноставна игра со карти која
ги има следните правила: шпилот од 52 карти се меша и се делат
картите на сите играчи подеднакво. Добива оној играч што има
најголем збир.
а) Вредностите на картите се од 1 до 14 соодветно, без разлика на
бојата, А има вредност 1.
б) Вредностите на картите се од 1 до 14 соодветно, А има вредност 1. Картите срце се бројат двојно.
На почетокот на играта да се внесе бројот на играчи. Во излезот
да се прикажат картите и збирот што ги добил секој играч.
Со среќа!.


*/


#include <iostream>
#include <vector>
#include <algorithm>
#include <ctime>
#include <cstdlib>
#include <numeric>
#include <iterator>
using namespace std;


int vrednostKarta(int karta, bool srceDvojno) {
    int vrednost = karta % 14;
    if (vrednost == 0) vrednost = 14;
    if (srceDvojno && karta / 14 == 1) {
        vrednost *= 2;
    }
    return vrednost;
}

int sledenBroj()
{
    static int broj = 1;
    return broj++;

}




int main()
{
    int brojIgraci;
    cout<<"Vnesi broj na igrachi pomegju 2 i 10: ";
    cin>>brojIgraci;

    if((brojIgraci < 2) || (brojIgraci > 10)){
        cout<<"Brojot na igrachi treba da bide pomegju 2 i 10"<<endl;
        return 1;
    }

    vector<int> spil(52); // spilot ima 52 karti, znachi vektorot ima 52 polinja
    ostream_iterator<int> output(cout, " ");

    // generiranje na karti od 1 do 52, primer:
    // 1 - 13 = detelina
    // 14 - 26 = srce
    // 27 - 39 = list
    // 40 - 52 = baklava
    generate_n( spil.begin(),52, sledenBroj );

    //meshanje na kartite
    random_shuffle(spil.begin(), spil.end());

    //sekoj igrac ima vektor od karti shto ke mu se dodealt
    vector<vector<int>> igraci(brojIgraci);

    // dodeluvanje na akrtite na sekoj igrac
    for (int i = 0; i < spil.size(); ++i) {
        igraci[i % brojIgraci].push_back(spil[i]);
    }

    vector<int> zbroevi(brojIgraci);
    transform(igraci.begin(), igraci.end(), zbroevi.begin(),[](const vector<int>& karti) { // accumulate za sobiranje na elementite
                                                                return accumulate(karti.begin(), karti.end(), 0, [](int zbir, int karta) {
                                                                                                                return zbir + vrednostKarta(karta, true); });});
    for (int i = 0; i < brojIgraci; ++i) {
        cout << "Igrac " << i + 1 << " karti: ";
        for (int k : igraci[i]) {
            cout << vrednostKarta(k, true) << " ";
        }
        cout << "=> Zbir: " << zbroevi[i] << endl;
    }

    int pobednik = max_element(zbroevi.begin(), zbroevi.end()) - zbroevi.begin();
    cout << "Pobednik e igrac " << pobednik + 1 << " so zbir " << zbroevi[pobednik] << "!" << endl;
    cout << "So srekja!" << endl;




    return 0;
}












