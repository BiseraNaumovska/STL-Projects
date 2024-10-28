/*
5.      Напиши програма која содржи class template Array со која може да се
инстанцира поле од било кој тип. Класата треба да содржи функции членки за
сместување и преземање на вредност на елемент од полето. Да се демонстрира
создавање на објекти за int и double тип.
*/

#include <iostream>

using namespace std;

template<class T>
class Array{
private:
    T* elements;
    int size;
public:
    // konstruktor
    Array(int s):size(s){
        elements = new T[size];
    }
    //destruktor
    ~Array(){
        delete [] elements;
    }

    int getSize(){
        return size;
    }

    void setElement(int index, T value){
        if(index>=0 && index<size){
            elements[index] = value;
        }else{
            cout<<"Error"<<endl;
        }
    }

    T getElement(int index) const{
        if(index>=0 && index<size){
            return elements[index];
        }else{
            return T();
        }
    }


};

int main()
{
    Array<int> intArray(5);

    for (int i = 0; i < intArray.getSize(); i++) {
        intArray.setElement(i, i * 2);
    }

    // Prikazuvanje na vrednostite od int poleto
    cout << "Elementite vo intArray se: ";
    for (int i = 0; i < intArray.getSize(); i++) {
        cout << intArray.getElement(i) << " ";
    }
    cout << endl;

    // Kreiranje na objekt od tip Array<double> so 5 elementi
    Array<double> doubleArray(5);

    // Postavuvanje vrednosti vo double poleto
    for (int i = 0; i < doubleArray.getSize(); i++) {
        doubleArray.setElement(i, i * 1.1);
    }

    // Prikazuvanje na vrednostite od double poleto
    cout << "Elementite vo doubleArray se: ";
    for (int i = 0; i < doubleArray.getSize(); i++) {
        cout << doubleArray.getElement(i) << " ";
    }
    cout << endl;








    return 0;
}











