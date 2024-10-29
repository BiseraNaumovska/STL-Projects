/*
Вежби:
1.Во една фирма платата на вработените се пресметува како производ од број на
 бодови и вредност на бод. Вредноста на бодот е иста за сите вработени.
Имплементирај класа Vraboten која содржи податочни членови ime и bodovi.
Напиши програма со која ќе се пресмета вкупната сума за да се исплати месечна
 плата за целата фирма. Програмата треба да ја прикаже вкупната сума и список
на вработените сортиран според бројот на бодови. За пресметување на сумата да
 се употреби accumulate. За сортирање на листата да се употреби sort.

*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>
using namespace std;


class Vraboten{
public:
    string ime;
    int bodovi;

    Vraboten(const string& ime, int bodovi) : ime(ime) , bodovi(bodovi){}

};

double presmetajPlata(const Vraboten& vraboten, double vrednostNaBod){
    return vraboten.bodovi*vrednostNaBod;
}


int main()
{
    double vrednostNaBod = 2.2;
   // cout<<"Vnesi vrednost na bod: ";
    //cin>>vrednostNaBod;

    vector<Vraboten> vraboteni = {Vraboten{"Bisera", 222},
                                    Vraboten{"Marko", 300},
                                    Vraboten{"Natasha", 150},
                                    Vraboten{"Vele", 100},
                                    Vraboten{"Maksim", 29}  };

    double vkupnoPlata = accumulate(vraboteni.begin(), vraboteni.end(), 0.0,[vrednostNaBod](double zbir, const Vraboten& vraboten) {
        return zbir + presmetajPlata(vraboten, vrednostNaBod);
    });

    sort(vraboteni.begin(), vraboteni.end(), [](const Vraboten& a, const Vraboten& b) {
        return a.bodovi < b.bodovi;
    });

    cout << "Sortean spisok na vrabotenite:" << endl;
    for (const auto& vraboten : vraboteni) {
        cout << vraboten.ime << " - " << vraboten.bodovi << " bodovi" << endl;
    }

    cout << "Vkupna suma za mesecna plata na firmata: " << vkupnoPlata << " denari" << endl;






    return 0;
}












