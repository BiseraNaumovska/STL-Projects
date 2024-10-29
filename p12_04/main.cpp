/*
2. Напиши програма за играње на играта ’бесилка’. Креирај класа која содржи char и bool за индикација дали знак веќе бил погоден.
Одбери збор и вчитај го во вектор со објекти од таа класа. Менувањето и прикажувањето на елементите од векторот изврши го со STL алгоритми.
Играчот во циклус внесува збор кој смее да се состои само од мали букви. Ако зборот содржи и други знаци програмата да фрли исклучок.
За секој збор се прикажуваат знаците што ги погодил и знак ’-’ за знаците што сеуште не ги погодил. Користи бројач на погодувања.
Играчот победува ако го погоди зборот пред бројачот да добие вредност 0.


*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <stdexcept>
#include <cctype>
using namespace std;


class Bukva {
public:
    char znak;
    bool pogodeno;

    Bukva(char znak) : znak(znak), pogodeno(false) {}
};

void prikaziZbor(const vector<Bukva>& zbor) {
    for (const auto& b : zbor) {
        if (b.pogodeno) {
            cout << b.znak << " ";
        } else {
            cout << "- ";
        }
    }
    cout << endl;
}

// dali site karakteri se pogodeni
bool sitePogodeni(const vector<Bukva>& zbor) {
    return all_of(zbor.begin(), zbor.end(), [](const Bukva& b) { return b.pogodeno; });
}

// za mali bukvi
void proveriValidnost(const string& pogodi) {
    if (any_of(pogodi.begin(), pogodi.end(), [](char c) { return !islower(c); })) {
        throw invalid_argument("Vneseniot zbor mora da sodrzi samo mali bukvi.");
    }
}


int main()
{
    string taenZbor = "sonce";
    vector<Bukva> zbor;
    for (char c : taenZbor) {
        zbor.emplace_back(c);
    }

    int brojach = 10; // 10 obidi ima pogoduvachot

    cout << "Dobredojdovte vo igrata 'Besilka'!" << endl;
    cout << "Obidete se da go pogodite zborot. Imate " << brojach << " obidi." << endl;
    prikaziZbor(zbor);

    while (brojach > 0 && !sitePogodeni(zbor)) {
        string pogoduvanje;
        cout << "Vnesete zbor: ";
        cin >> pogoduvanje;

        try {
            proveriValidnost(pogoduvanje);
        } catch (const invalid_argument& e) {
            cout << "Greshka: " << e.what() << endl;
            continue;
        }

        bool pogodok = false;
        for (char c : pogoduvanje) {
            auto it = find_if(zbor.begin(), zbor.end(), [c](Bukva& b) { return b.znak == c; });
            if (it != zbor.end()) {
                it->pogodeno = true;
                pogodok = true;
            }
        }

        if (!pogodok) {
            brojach--;
            cout << "Pogreshno pogoduvanje! Ostanuvaat " << brojach << " obidi." << endl;
        }

        prikaziZbor(zbor);
    }

    if (sitePogodeni(zbor)) {
        cout << "WINNER! Go pogodivte zborot: " << taenZbor << endl;
    } else {
        cout << "LOOSER! Tochniot zbor bese: " << taenZbor << endl;
    }

    return 0;
}
