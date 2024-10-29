/*
1. Креирај класа Pravoagolnik која содржи double sirina и double
dolzina, и класа Kvadrat која содржи double strana. Во две
текстуални датотеки се сместени линии со чија содржина може да
биде:

-	број 1 по кој следат два double броја
-	број 2 по кој следи еден double број.
-
Овие вредности треба да се вчитаат во програма и од нив да се
создадат објекти. Ако првата вредност е 1 тогаш се создава
Pravoagolnik чии димензии се двата броја што следуваат. Ако
првата вредност е 2 тогаш се создава Kvadrat чија страна е бројот
 што следува.
На пример,

1 2.5 3.5
2 10.0
1 5 5

ќе значи дека ќе се создадат два правоаголника и еден квадрат.
Ако линија содржи вредности различни од пропишаните, програмата да генерира
исклучок.

Определи ја унијата и пресекот на сите правоаголници и унијата и пресекот на
сите квадрати што се дефинирани со датотеките.

*/
#include <iostream>
#include <fstream>
#include <vector>
#include <stdexcept>
#include <algorithm>
using namespace std;



class Pravoagolnik {
public:
    double sirina;
    double dolzina;

    Pravoagolnik(double sirina, double dolzina) : sirina(sirina), dolzina(dolzina) {}

    double area() const {
        return sirina * dolzina;
    }

    static Pravoagolnik unionArea(const vector<Pravoagolnik>& pravoagolnici) {
        double maxSirina = 0;
        double maxDolzina = 0;
        for (const auto& p : pravoagolnici) {
            maxSirina = max(maxSirina, p.sirina);
            maxDolzina = max(maxDolzina, p.dolzina);
        }
        return Pravoagolnik(maxSirina, maxDolzina);
    }

    static Pravoagolnik intersectionArea(const vector<Pravoagolnik>& pravoagolnici) {
        double minSirina = pravoagolnici[0].sirina;
        double minDolzina = pravoagolnici[0].dolzina;
        for (const auto& p : pravoagolnici) {
            minSirina = min(minSirina, p.sirina);
            minDolzina = min(minDolzina, p.dolzina);
        }
        return Pravoagolnik(minSirina, minDolzina);
    }
};

class Kvadrat {
public:
    double strana;

    Kvadrat(double strana) : strana(strana) {}

    double area() const {
        return strana * strana;
    }

    static Kvadrat unionArea(const vector<Kvadrat>& kvadrati) {
        double maxStrana = 0;
        for (const auto& k : kvadrati) {
            maxStrana = max(maxStrana, k.strana);
        }
        return Kvadrat(maxStrana);
    }

    static Kvadrat intersectionArea(const vector<Kvadrat>& kvadrati) {
        double minStrana = kvadrati[0].strana;
        for (const auto& k : kvadrati) {
            minStrana = min(minStrana, k.strana);
        }
        return Kvadrat(minStrana);
    }
};

void procitajOdDatoteka(const string& imeDatoteka, vector<Pravoagolnik>& pravoagolnici, vector<Kvadrat>& kvadrati) {
    ifstream inputFile(imeDatoteka);
    if (!inputFile) {
        throw runtime_error("Ne moze da se otvori datotekata: " + imeDatoteka);
    }

    int tip;
    double vrednost1, vrednost2;
    while (inputFile >> tip) {
        if (tip == 1) {
            if (!(inputFile >> vrednost1 >> vrednost2)) {
                throw invalid_argument("Nevalidni podatoci za Pravoagolnik vo datotekata: " + imeDatoteka);
            }
            pravoagolnici.emplace_back(vrednost1, vrednost2);
        } else if (tip == 2) {
            if (!(inputFile >> vrednost1)) {
                throw invalid_argument("Nevalidni podatoci za Kvadrat vo datotekata: " + imeDatoteka);
            }
            kvadrati.emplace_back(vrednost1);
        } else {
            throw invalid_argument("Nevaliden tip vo datotekata: " + imeDatoteka);
        }
    }
}

int main()
{
    vector<Pravoagolnik> pravoagolnici;
    vector<Kvadrat> kvadrati;

    try {
        procitajOdDatoteka("datoteka1.txt", pravoagolnici, kvadrati);
        procitajOdDatoteka("datoteka2.txt", pravoagolnici, kvadrati);

        Pravoagolnik pravoagolnikUnija = Pravoagolnik::unionArea(pravoagolnici);
        Pravoagolnik pravoagolnikPres = Pravoagolnik::intersectionArea(pravoagolnici);

        Kvadrat kvadratUnija = Kvadrat::unionArea(kvadrati);
        Kvadrat kvadratPres = Kvadrat::intersectionArea(kvadrati);

        cout << "Unija na site pravoagolnici: Sirina = " << pravoagolnikUnija.sirina<< ", Dolzina = " << pravoagolnikUnija.dolzina << endl;
        cout << "Presek na site pravoagolnici: Sirina = " << pravoagolnikPres.sirina<< ", Dolzina = " << pravoagolnikPres.dolzina << endl;

        cout << "Unija na site kvadrati: Strana = " << kvadratUnija.strana << endl;
        cout << "Presek na site kvadrati: Strana = " << kvadratPres.strana << endl;

    } catch (const exception& e) {
        cerr << "Greshka: " << e.what() << endl;
        return 1;
    }
    return 0;
}




















