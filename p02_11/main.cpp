/*
3.      Една фирма води евиденција за лица кои можат да бидат вработени или
клиенти. За секое лице се чуваат следните податоци:  imeiprezime, mat_br,
vozrast, adresa, kod. За вработените kod има целобројна вредност, а за
клиентите е низа од знаци.
Креирај class template Lica во која ќе се сместуваат податоците за лица.
Податоците кои се низи од знаци да се внесуваат преку динамичка алокација
на меморија. Креирај две полиња од објекти, Vraboteni и Klienti. За печатење
на двете полиња употреби ја pecatiPole од претходната задача.
Напиши тест програма која содржи мени:
1.      Внесување на податоци за вработен
2.      Внесување на податоци за клиент
3.      Печетење на листа на вработени
4.      Печатење на листа на клиенти
5.      Крај

*/
#include <iostream>
#include <iostream>
#include <cstring>
#include <vector>
using namespace std;


template <class T>
class Lica {
private:
    char* imeiprezime;
    char* mat_br;
    int vozrast;
    char* adresa;
    T kod; // Kodot moze da bide int za vraboteni, a niza od znaci za klienti

public:
    // Konstruktor
    Lica(const char* ime, const char* mbr, int v, const char* adr, T k) : vozrast(v), kod(k) {
        // Dinamichka alokacija na memorija za nizite od znaci
        imeiprezime = new char[strlen(ime) + 1];
        strcpy(imeiprezime, ime);

        mat_br = new char[strlen(mbr) + 1];
        strcpy(mat_br, mbr);

        adresa = new char[strlen(adr) + 1];
        strcpy(adresa, adr);
    }

    // Destruktor
    ~Lica() {
        delete[] imeiprezime;
        delete[] mat_br;
        delete[] adresa;
    }

    // Funkcija za pechatenje na podatocite za liceto
    void pecati() const {
        cout << "Ime i prezime: " << imeiprezime << ", Maticen broj: " << mat_br
             << ", Vozrast: " << vozrast << ", Adresa: " << adresa
             << ", Kod: " << kod << endl;
    }
};

template <class T>
void pecatiPole(const vector<T>& pole) {
    for (const auto& elem : pole) {
        elem.pecati();
    }
    cout << endl;
}

int main()
{
    vector<Lica<int>> Vraboteni; // Lista od vraboteni so kod kako int
    vector<Lica<const char*>> Klienti; // Lista od klienti so kod kako niza od znaci

    int izbor;

    do {
        // Meni za izbor na opcija
        cout << "\nMeni:\n";
        cout << "1. Vnesuvanje na podatoci za vraboten\n";
        cout << "2. Vnesuvanje na podatoci za klient\n";
        cout << "3. Pechetenje na lista na vraboteni\n";
        cout << "4. Pechetenje na lista na klienti\n";
        cout << "5. Kraj\n";
        cout << "Vnesete izbor: ";
        cin >> izbor;
        cin.ignore(); // Za da se ignorira newline karakterot po vnesuvanje na broj

        if (izbor == 1) {
            // Vnesuvanje podatoci za vraboten
            char ime[50], mbr[13], adr[100];
            int vozrast, kod;

            cout << "Vnesi ime i prezime: ";
            cin.getline(ime, 50);
            cout << "Vnesi maticen broj: ";
            cin.getline(mbr, 13);
            cout << "Vnesi vozrast: ";
            cin >> vozrast;
            cin.ignore();
            cout << "Vnesi adresa: ";
            cin.getline(adr, 100);
            cout << "Vnesi kod (cel broj): ";
            cin >> kod;

            // Dodavanje na nov vraboten vo listata
            Vraboteni.emplace_back(ime, mbr, vozrast, adr, kod);
        } else if (izbor == 2) {
            // Vnesuvanje podatoci za klient
            char ime[50], mbr[13], adr[100], kod[20];
            int vozrast;

            cout << "Vnesi ime i prezime: ";
            cin.getline(ime, 50);
            cout << "Vnesi maticen broj: ";
            cin.getline(mbr, 13);
            cout << "Vnesi vozrast: ";
            cin >> vozrast;
            cin.ignore();
            cout << "Vnesi adresa: ";
            cin.getline(adr, 100);
            cout << "Vnesi kod (niza od znaci): ";
            cin.getline(kod, 20);

            // Dodavanje na nov klient vo listata
            Klienti.emplace_back(ime, mbr, vozrast, adr, kod);
        } else if (izbor == 3) {
            // Pechetenje na lista na vraboteni
            cout << "\nLista na vraboteni:\n";
            pecatiPole(Vraboteni);
        } else if (izbor == 4) {
            // Pechetenje na lista na klienti
            cout << "\nLista na klienti:\n";
            pecatiPole(Klienti);
        } else if (izbor != 5) {
            cout << "Nevaliden izbor! Obidete se povtorno.\n";
        }
    } while (izbor != 5);

    cout << "Programata zavrshi.\n";
    return 0;
}
