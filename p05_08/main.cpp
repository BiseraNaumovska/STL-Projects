/*
Проект 1:
Во едно множество се сместуваат објекти кои се геометриски фигури.
Креирај класи Pravoagolnik, Kvadrat и Krug. Креирај class template
Mnozestvo<T> во со функции членки за додавање, прикажување на елементи на
множеството и определување на најголем елемент во множеството (елемент со
најголема површина). Како податочна структура за сместување на елементите
на множеството може да се користи поле. Секој елемент може да се појави
само еднаш. Креирај три множества: pravoagolnici, kvadrati и krugovi од
Pravoagolnik, Kvadrat и Krug, соодветно. Креирај function template за
печатење на множество. Програмата треба да имплементира мени со следните
опции:

1.      Додај правоаголник
2.      Додај квадрат
3.      Додај круги
4.      Прикажи го множеството правоаголници
5.      Прикажи го множеството квадрати
6.      Прикажи го множеството кругови
7.      Прикажи најголеми елементи
8.      Прикажи број на елементи во множествата
9.      Крај

*/
#include <iostream>
#include <cmath>
#include <vector>
#include <algorithm>
using namespace std;


class GeometriskaFigura{
public:
    virtual double getPlostina() const = 0;
    virtual void prikazi() const = 0;
    virtual ~GeometriskaFigura(){}
};


class Pravoagolnik : public GeometriskaFigura{
    double dolzina, shirina;
public:
    Pravoagolnik(double d, double s):dolzina(d), shirina(s){}

    double getPlostina() const override{
        return dolzina*shirina;
    }

    void prikazi() const override{
        cout << "Pravoagolnik: Dolzina = " << dolzina << ", Shirina = " << shirina << endl;
    }
    bool operator==(const Pravoagolnik& other) const {
        return (dolzina == other.dolzina) && (shirina == other.shirina);
    }
};

class Kvadrat : public GeometriskaFigura{
    double strana;
public:
    Kvadrat(double s) : strana(s){}
    double getPlostina() const override{
        return strana*strana;
    }
    void prikazi() const override{
        cout << "Kvadrat: Strana = " << strana << endl;
    }
    bool operator==(const Kvadrat& other) const {
        return strana == other.strana;
    }
};


class Krug : public GeometriskaFigura{
    double radius;
public:
    Krug(double r) : radius(r){}
    double getPlostina() const override{
        return M_PI*radius*radius;
    }
    void prikazi() const override {
        cout << "Krug: Radius = " << radius << endl;
    }
    bool operator==(const Krug& other) const {
        return radius == other.radius;
    }

};

template<class T>
class Mnozestvo{
    vector<T*> elementi;
public:
    void dodadi(T* element){
        for(auto& e : elementi){
            if(*e == *element){
                cout<<"Elementot vekje postoi"<<endl;
                return;
            }
        }
        elementi.push_back(element);
    }

    void prikazi() const{
        if(elementi.empty()){
            cout<<"Mnozestvoto e prazno"<<endl;
        }else{
            for(const auto& e: elementi){
                e->prikazi();
            }
        }
    }

    T* najgolemElement() const {
        if (elementi.empty()) {
            return nullptr;
        }
        return *max_element(elementi.begin(), elementi.end(), [](T* a, T* b) { return a->getPlostina() < b->getPlostina(); });
    }

    int brojNaElementi() const {
        return elementi.size();
    }

    ~Mnozestvo() {
        for (auto& e : elementi) {
            delete e;
        }
    }
};


template <typename T>
void pecatiMnozestvo(const Mnozestvo<T>& mnozestvo) {
    mnozestvo.prikazi();
}



int main()
{
    Mnozestvo<Pravoagolnik> pravoagolnici;
    Mnozestvo<Kvadrat> kvadrati;
    Mnozestvo<Krug> krugovi;

    int izbor;
    do {
        cout << "\nMeni:\n";
        cout << "1. Dodaj pravoagolnik\n";
        cout << "2. Dodaj kvadrat\n";
        cout << "3. Dodaj krug\n";
        cout << "4. Prikazi go mnozestvoto pravoagolnici\n";
        cout << "5. Prikazi go mnozestvoto kvadrati\n";
        cout << "6. Prikazi go mnozestvoto krugovi\n";
        cout << "7. Prikazi najgolemi elementi\n";
        cout << "8. Prikazi broj na elementi vo mnozestvata\n";
        cout << "9. Kraj\n";
        cout << "Vnesete izbor: ";
        cin >> izbor;

        switch (izbor) {
        case 1: {
            double d, s;
            cout << "Vnesete dolzina i shirina: ";
            cin >> d >> s;
            pravoagolnici.dodadi(new Pravoagolnik(d, s));
            break;
        }
        case 2: {
            double s;
            cout << "Vnesete strana na kvadratot: ";
            cin >> s;
            kvadrati.dodadi(new Kvadrat(s));
            break;
        }
        case 3: {
            double r;
            cout << "Vnesete radius na krugot: ";
            cin >> r;
            krugovi.dodadi(new Krug(r));
            break;
        }
        case 4:
            pecatiMnozestvo(pravoagolnici);
            break;
        case 5:
            pecatiMnozestvo(kvadrati);
            break;
        case 6:
            pecatiMnozestvo(krugovi);
            break;
        case 7: {
            cout << "Najgolem pravoagolnik: ";
            auto p = pravoagolnici.najgolemElement();
            if (p) p->prikazi();

            cout << "Najgolem kvadrat: ";
            auto k = kvadrati.najgolemElement();
            if (k) k->prikazi();

            cout << "Najgolem krug: ";
            auto c = krugovi.najgolemElement();
            if (c) c->prikazi();
            break;
        }
        case 8:
            cout << "Broj na pravoagolnici: " << pravoagolnici.brojNaElementi() << endl;
            cout << "Broj na kvadrati: " << kvadrati.brojNaElementi() << endl;
            cout << "Broj na krugovi: " << krugovi.brojNaElementi() << endl;
            break;
        case 9:
            cout << "Kraj na programata." << endl;
            break;
        default:
            cout << "Greshen izbor. Obidete se povtorno." << endl;
        }
    } while (izbor != 9);
    return 0;
}
