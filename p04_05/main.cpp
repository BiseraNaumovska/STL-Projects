/*
1.Напиши класа Imenik којa содржи ime и tel_broj. Креирај
телефонски именик користејќи контејнер vector.
Прикажи го именикот во абецеден редослед.

*/

#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;


class Imenik{
private:
    string ime;
    string broj;
public:
    Imenik(const string& ime, const string& broj): ime(ime),broj(broj){}
    string getIme() const{
        return ime;
    }
    string getBroj() const{
        return broj;
    }
    friend ostream& operator<<(ostream& os, const Imenik& imenik){
        os<<"Ime: "<<imenik.ime<<", Telefon: "<<imenik.broj;
        return os;
    }

};

bool sortirajPoIme(const Imenik& a, const Imenik& b) {
    return a.getIme() < b.getIme();
}

int main()
{
    vector<Imenik> imenik;

    imenik.push_back(Imenik("Bisera Naumovska" , "071257681"));
    imenik.push_back(Imenik("Marko Naumovska" , "071257681"));
    imenik.push_back(Imenik("Natasha Naumovska" , "071257681"));
    imenik.push_back(Imenik("Vele Naumovska" , "071257681"));
    imenik.push_back(Imenik("Maksim Mitevski" , "071257681"));
    imenik.push_back(Imenik("Time Dimov" , "071257681"));

    sort(imenik.begin(),imenik.end(),sortirajPoIme);

    cout<<"Sortiran telefonski imenik: "<<endl;
    for(const auto& kontakt : imenik){
        cout<<kontakt<<endl;
    }



    return 0;
}
