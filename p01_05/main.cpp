/*1.      Напиши function template за сортирање и програма во која се
 * врши внесување, сортирање и печатење на поле од int елементи и поле
 * од double елементи. Може да се користи било кој алгоритам за сортирање. */
#include <iostream>

using namespace std;

template<class T>
void sortNiza(T *niza, const int brelementi){
    //ke sortiram vo rastechki redosled
    for(int i=0;i<brelementi-1;i++){
        for(int j=0;j<brelementi-i-1;j++){
            if(niza[j] > niza[j+1]){
                T temp = niza[j];
                niza[j] = niza[j+1];
                niza[j+1] = temp;
            }
        }
    }
}


int main()
{
    const int i=5;
    const int k=7;

    int ii[i] = {5,2,1,8,3};
    double kk[k] = {4.4,8.8,2.2,6.6,4.4,10.1,9.9};

    sortNiza(ii,i);
    cout<<"Sortirana int niza e: ";
    for(int j=0;j<i;j++){
        cout<<ii[j]<<" ";
    }
    cout<<endl;

    sortNiza(kk,k);
    cout<<"Sortirana double niza e: ";
    for(int j=0;j<k;j++){
        cout<<kk[j]<<" ";
    }
    cout<<endl;

    return 0;
}
