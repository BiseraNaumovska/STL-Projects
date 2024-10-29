/*
Вежби:
1.      Во една банка пристигаат уплати за штедачи. Напиши програма во која
ќе се внесуваат податоци за уплати и ќе се прикажува листа и вкупна уплата
за даден штедач. Импламентирај класа Uplata која содржи податоци за штедач и
големина на уплата. Користи контејнер multimap. Програмата треба да
овозможува едноставно мени за внесување и прикажување на уплати.
1.      Додај уплата
2.      Прикажи уплати за даден штедач
3.      Крај

*/
#include <iostream>
#include <map>
#include <string>
using namespace std;

class Uplata{
    string stedac;
    double iznos;
public:
    Uplata(const string& stedac, double iznos): stedac(stedac) , iznos(iznos){}

    string getStedac() const{
        return stedac;
    }

    double getIznos() const{
        return iznos;
    }

};


int main()
{
    multimap<string ,double> uplati;
    int izbor;
    string ime;
    double iznosUplata;

    do {
        cout << "1. Dodadi uplata" << endl;
        cout << "2. Prikazhi uplati za daden shtedach" << endl;
        cout << "3. Kraj" << endl;
        cout << "Vnesi izbor: ";
        cin >> izbor;

        switch (izbor) {
        case 1:
            cout << "Vnesi ime na shtedach: ";
            cin >> ime;
            cout << "Vnesi iznos na uplata: ";
            cin >> iznosUplata;
            uplati.insert(make_pair(ime, iznosUplata));
            cout << "Uplata e dodadena." << endl;
            break;

        case 2:
            cout << "Vnesi ime na shtedach: ";
            cin >> ime;
            {
                auto range = uplati.equal_range(ime);
                double vkupno = 0;
                cout << "Uplati za shtedachot " << ime << ":" << endl;
                for (auto it = range.first; it != range.second; ++it) {
                    cout << "- " << it->second << " denari" << endl;
                    vkupno += it->second;
                }
                cout << "Vkupna uplata: " << vkupno << " denari" << endl;
            }
            break;

        case 3:
            cout << "Kraj na programata." << endl;
            break;

        default:
            cout << "Greshen izbor. Obidete se povtorno." << endl;
        }
    } while (izbor != 3);






    return 0;
}











