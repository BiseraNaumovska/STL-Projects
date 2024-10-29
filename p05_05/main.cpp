/*
1.      Напиши function template palindrom кој има параметар vector и враќа
true ако векторот е палиндром, а false во спротивно.
*/
#include <iostream>
#include <vector>
using namespace std;


template<class T>
bool palindrom(const vector<T>& vektor){
    for(int i=0;i<vektor.size()/2;i++){
        if(vektor[i] != vektor[vektor.size()-i-1]){
            return false; // ne e palindrom
        }
    }

    return true; // e palindrom
}




int main()
{
    vector<int> vektor1 = {1, 2, 3, 2, 1};
    if (palindrom(vektor1)) {
        cout << "Vektorot e palindrom." << endl;
    } else {
        cout << "Vektorot ne e palindrom." << endl;
    }


    vector<char> vektor2 = {'a', 'b', 'c', 'b', 'a'};
    if (palindrom(vektor2)) {
        cout << "Vektorot e palindrom." << endl;
    } else {
        cout << "Vektorot ne e palindrom." << endl;
    }


    vector<int> vektor3 = {1, 2, 3, 4, 5};
    if (palindrom(vektor3)) {
        cout << "Vektorot e palindrom." << endl;
    } else {
        cout << "Vektorot ne e palindrom." << endl;
    }


    vector<char> vektor4 = {'a', 'b', 'c', 'c', 'b', 'a'};
    if (palindrom(vektor4)) {
        cout << "Vektorot e palindrom." << endl;
    } else {
        cout << "Vektorot ne e palindrom." << endl;
    }




    return 0;
}
