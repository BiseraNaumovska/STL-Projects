/*
2.      Креирај класа Kvadrat со податоци strana и класа Pravoagolnik со
податоци sirina и dolzina.  Напиши function template sortirajPole со кој
се врши сортирање на поле и function template pecatiPole со кој се врши
печатење на поле. Во main креирај две полиња од квадрати и праваголници,
прикажи ги со pecatiPole, сортирај ги според плоштина со sortirajPole и
повторно отпечати ги.
*/

#include <iostream>
#include <algorithm>
using namespace std;

class Kvadrat {
private:
    double strana;
public:
    Kvadrat(double s = 0) : strana(s) {}

    // Funkcija za presmetka na ploshtina
    double plostina() const {
        return strana * strana;
    }

    // Get za dobivanje na stranata (za pechatenje)
    double getStrana() const {
        return strana;
    }
};
class Pravoagolnik {
private:
    double sirina;
    double dolzina;
public:
    Pravoagolnik(double s = 0, double d = 0) : sirina(s), dolzina(d) {}

    // Funkcija za presmetka na ploshtina
    double plostina() const {
        return sirina * dolzina;
    }

    // Get za dobivanje na sirina i dolzina (za pechatenje)
    double getSirina() const {
        return sirina;
    }

    double getDolzina() const {
        return dolzina;
    }
};


template <class T>
void sortirajPole(T* array, int size) {
    // Sortiranje spored ploshtina na objektite
    sort(array, array + size, [](const T& a, const T& b) {
        return a.plostina() < b.plostina();
    });
}

// Template funkcija za pechatenje na pole
template <class T>
void pecatiPole(const T* array, int size) {
    for (int i = 0; i < size; i++) {
        cout << array[i].plostina() << " "; // Pechati ja ploshtinata na sekoj element
    }
    cout << endl;
}


int main()
{
    const int brojKvadrati = 5;
    const int brojPravoagolnici = 5;

    // Kreiranje na pole od kvadrati
    Kvadrat kvadrati[brojKvadrati] = {Kvadrat(3), Kvadrat(5), Kvadrat(2), Kvadrat(4), Kvadrat(1)};

    // Kreiranje na pole od pravoagolnici
    Pravoagolnik pravoagolnici[brojPravoagolnici] = {
        Pravoagolnik(3, 4), Pravoagolnik(5, 6), Pravoagolnik(2, 3), Pravoagolnik(4, 5), Pravoagolnik(1, 2)};

    // Pecatenje na originalnite nizi
    cout << "Originalni kvadrati (ploshtina): ";
    pecatiPole(kvadrati, brojKvadrati);

    cout << "Originalni pravoagolnici (ploshtina): ";
    pecatiPole(pravoagolnici, brojPravoagolnici);

    // Sortiranje na nizite spored ploshtina
    sortirajPole(kvadrati, brojKvadrati);
    sortirajPole(pravoagolnici, brojPravoagolnici);

    // Pecatenje na sortiranite nizi
    cout << "\nSortirani kvadrati (ploshtina): ";
    pecatiPole(kvadrati, brojKvadrati);

    cout << "Sortirani pravoagolnici (ploshtina): ";
    pecatiPole(pravoagolnici, brojPravoagolnici);
    return 0;
}
