/*
2. Во еден магацин се води евиденција за артикли. Во текстуална датотека inventar.txt се чуваат следните податоци
 за секој артикл: инвентарен број (int), количество (int) и цена (double) за секој артикл.  Креирај класа Inventar
 која содржи id, kolicestvo и cena.  Напиши програма во која се создава vector од артикли, а потоа прикажува вкупна
вредност на артиклите во магацинот и листа на сите артикли за кои количеството е помало од 10. Пресметувањето на
вкупната вредност и прикажувањето на артиклите изврши го со STL алгоритми. Ако не постои влезна датотека,
програмата да фрли исклучок.
*/

#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <numeric>
using namespace std;


class Inventar{
public:
    int id;
    int kolicestvo;
    double cena;

    Inventar(int id, int kolicestvo, double cena): id(id), kolicestvo(kolicestvo), cena(cena){}

    double vrednost() const{
        return kolicestvo*cena;
    }
};




int main()
{
    vector<Inventar> artikli;
    ifstream inputFile("inventar.txt");

    if(!inputFile){
        throw runtime_error("Ne moze da se otvori datotekata");
    }

    int id, kolicestvo;
    double cena;

    while(inputFile >> id >> kolicestvo >> cena){
        artikli.emplace_back(id, kolicestvo, cena);
    }

    inputFile.close();


    double vkupnaVrednost = accumulate(artikli.begin(), artikli.end(), 0.0,[](double suma, const Inventar& art) {return suma + art.vrednost();});
    cout << "Vkupna vrednost na artiklite vo magazinot: " << vkupnaVrednost << endl;

    cout << "Artikli so kolicestvo pomalo od 10:" << endl;
    for (const auto& art : artikli) {
        if (art.kolicestvo < 10) {
            cout << "ID: " << art.id << ", Kolicestvo: " << art.kolicestvo << ", Cena: " << art.cena << endl;
        }
    }


    return 0;
}
























