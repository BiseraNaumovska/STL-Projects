/*

1.      Напиши function template кој има еден параметризиран тип (T) и
прифаќа четири аргументи: поле од тип T, почетен индекс, краен индекс и
опциона, почетна вредност. Функцијата трба да ја врати сумата на елементите
во полето зададени со почетниот и крајниот индекс. За почетната вредност да
се употреби конструкторот на T.
*/

#include <iostream>

using namespace std;

template<class T>
T sumafunkcija(const T* niza, int start, int end, T pochetnavrednost){
    T sum = pochetnavrednost;
    if(start<0 || end<0 || start>end){
        cout<<"ERROR"<<endl;
        return sum;
    }
    for(int i=start; i<=end;i++){
        sum = sum+niza[i];
    }
    return sum;
}





int main()
{
    const int intSize = 5;
    const int doubleSize = 6;

    int intArray[intSize] = {1, 2, 3, 4, 5};
    double doubleArray[doubleSize] = {1.1, 2.2, 3.3, 4.4, 5.5, 6.6};

    // Testiranje na funkcijata so int pole
    cout << "Sumata na elementite vo intArray od indeks 1 do 3 e: "
         << sumArray(intArray, 1, 3) << endl;

    // Testiranje na funkcijata so double pole, so pocetna vrednost 10.0
    cout << "Sumata na elementite vo doubleArray od indeks 0 do 4 so pocetna vrednost 10.0 e: "
         << sumArray(doubleArray, 0, 4, 10.0) << endl;
    return 0;
}
