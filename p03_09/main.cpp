/*
2.      Креирај class template Mnozestvo<T> во со функции членки за додавање,
 прикажување на елементи на множеството и определување на најголем елемент
во множеството. Како податочна структура за сместување на елементите на
множеството може да се користи поле. Секој елемент може да се појави само
еднаш. Секое множество содржи static компонента во која е сместен бројот
на елементи на множеството. Креирај три множества: А од int, B од double
и C од char*. Користи соодветна специјализација за коректно определување
на најголем елемент во множеството од стрингови. Програмата треба да
имплементира мени со следните опции:

1.      Додај елемент во А
2.      Додај елемент во B
3.      Додај елемент во C
4.      Прикажи го А
5.      Прикажи го B
6.      Прикажи го C
7.      Прикажи најголеми елементи
8.      Прикажи број на елементи во множествата
9.      Крај

*/

#include <iostream>
#include <cstring>

using namespace std;

const int MAX_SIZE = 100;


template <class T>
class Mnozestvo{
private:
    T elementi[MAX_SIZE]; // niza od int iili double elementi
    static int brojElementi;
public:
    Mnozestvo(){
        brojElementi = 0; // vo konstruktorot stavam default za br elementi da e 0
    }

    //funkcija za dodavanje elementi
    void dodadi(const T& elem){
        if (brojElementi >= MAX_SIZE){
                cout<<"Polno mnozestvo"<<endl;
                return;
        }
        for(int i=0 ; i<brojElementi;i++){
            if(elementi[i] == elem){
                cout<<"Elementot vekje postoi"<<endl;
                return;
            }
        }
        elementi[brojElementi++] = elem;

    }

    //funkcija za pechatenje na elementi
    void prikazi() const{
        for(int i=0;i<brojElementi;i++){
            cout<<elementi[i]<<" ";
        }
        cout<<endl;
    }

    //funkcija za opredeluvanje na najgolem element
    T najgolem() const {
        if(brojElementi == 0){
            throw runtime_error("Prazno mnozestvo.");
        }
        T maxElem = elementi[0]; // prviot neka e najgolem demek
        for(int i=1;i<brojElementi;i++){
            if(elementi[i] > maxElem){
                maxElem = elementi[i];
            }
        }
        return maxElem;
    }

    //da se vrati brojot na elementi
    static int getBrojElementi(){
        return brojElementi;
    }

};


template<class T>
int Mnozestvo<T>::brojElementi=0; // statichka promenliva ja inicijalizirame

// za int i double ke se koristi taa gore funkcija, a za char ke se prepokrie
template<>
class Mnozestvo<char*>{
private:
    char* elementi[MAX_SIZE];
    static int brojElementi;
public:
    Mnozestvo(){
        brojElementi = 0;
    }
    void dodadi(const char* elem){
        if(brojElementi>=MAX_SIZE){
            cout<<"Mnozestvoto e polno"<<endl;
            return;
        }
        for(int i=0;i<brojElementi;i++){
            if(strcmp(elementi[i],elem) == 0){
                cout<<"Elementot vekje postoi vo mnozestvoto"<<endl;
                return;
            }
        }
        elementi[brojElementi] = new char[strlen(elem) + 1];
        strcpy(elementi[brojElementi++], elem);
    }

    void prikazi() const {
        for(int i=0;i<brojElementi;i++){
            cout<<elementi[i]<<" ";
        }
        cout<<endl;
    }

    char* najgolem() const{
        if(brojElementi == 0){
            throw runtime_error("Prazno mnozestvo.");
        }
        char* maxElem = elementi[0];
        for(int i=1;i<brojElementi;i++){
            if(strcmp(elementi[i],maxElem) > 0){
                maxElem = elementi[i];
            }
        }
        return maxElem;
    }

    static int getBrojElementi(){
        return brojElementi;
    }

};

int Mnozestvo<char*>::brojElementi = 0;


int main()
{
    Mnozestvo<int> A;
    Mnozestvo<double> B;
    Mnozestvo<char*> C;

    int izbor;
    do{
        cout<<"Meni: "<<endl;
        cout<<"1. Dodadi element vo A: "<<endl;
        cout<<"2. Dodadi element vo B: "<<endl;
        cout<<"3. Dodadi element vo C: "<<endl;
        cout<<"4. Prikazi go A: "<<endl;
        cout<<"5. Prikazi go B: "<<endl;
        cout<<"6. Prikazi go C: "<<endl;
        cout<<"7. Prikazi najgolemi elementi: "<<endl;
        cout<<"8. Prikazi broj na elementi vo mnozestva: "<<endl;
        cout<<"9. Kraj!! "<<endl;
        cout<<"Izberi opcija: ";
        cin>> izbor;
        cout<<endl;

        switch (izbor) {
        case 1: {
            int elem;
            cout << "Dodadi element vo A: ";
            cin >> elem;
            A.dodadi(elem);
            break;
        }
        case 2: {
            double elem;
            cout << "Dodadi element vo B: ";
            cin >> elem;
            B.dodadi(elem);
            break;
        }
        case 3: {
            char elem[100];
            cout << "Dodadi element vo C: ";
            cin >> elem;
            C.dodadi(elem);
            break;
        }
        case 4:
            cout << "Elementi vo A se: ";
            A.prikazi();
            break;
        case 5:
            cout << "Elementi vo B se: ";
            B.prikazi();
            break;
        case 6:
            cout << "Elementi vo C se: ";
            C.prikazi();
            break;
        case 7:
            cout << "Najgolemiot element vo A e: " << A.najgolem() << endl;
            cout << "Najgolemiot element vo B e: " << B.najgolem() << endl;
            cout << "Najgolemiot element vo C e: " << C.najgolem() << endl;

            break;
        case 8:
            cout << "Broj na elementi vo A: " << A.getBrojElementi() << endl;
            cout << "Broj na elementi vo B: " << B.getBrojElementi() << endl;
            cout << "Broj na elementi vo C: " << C.getBrojElementi() << endl;
            break;
        case 9:
            cout << "KRAJ !!!"<<endl;
            break;
        default:
            cout << "Nevalidna opcija, error !"<<endl;
        }
    } while (izbor != 9);


    return 0;
}
