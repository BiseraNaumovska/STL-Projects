/*
Вежби:

1.      Креирај листа од 10000 случајни цели броеви co вредности од 0 до
9999. Потоа прикажи ги следните вредности:
-         број на парни елементи
-         број на елементи помали од 2000
-         број на елементи во интервал [2000, 4000)
-         број на елементи во интервал [4000, 6000)
-         број на елементи во интервал [6000, 8000)
-         број на елементи во интервал [8000, 10000)
-         средна вредност на елементите

*/


#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <iterator>
#include <algorithm>
#include <numeric>
using namespace std;


bool isEven(int x) { return x % 2 == 0; }
bool lessThan2000(int x) { return x < 2000; }
bool in2000to4000(int x) { return x >= 2000 && x < 4000; }
bool in4000to6000(int x) { return x >= 4000 && x < 6000; }
bool in6000to8000(int x) { return x >= 6000 && x < 8000; }
bool in8000to10000(int x) { return x >= 8000 && x < 10000; }



int main()
{
    const int SIZE = 10000;
    int a1[SIZE];
    for(int i=0;i<SIZE;i++){
        a1[i] = i;
    }

    vector< int > v( a1, a1 + SIZE );
    ostream_iterator< int > output( cout, " " );


    // izmesaj gi elementite na v
    random_shuffle( v.begin(), v.end() );

    cout << "\n v po random_shuffle: ";
    copy( v.begin(), v.end(), output );
    cout<<endl;
    // na ovoj nachin sekoj broj ke se pojavi ednash

    int evenCount = count_if(v.begin(), v.end(), isEven);
    int lessThan2000Count = count_if(v.begin(), v.end(), lessThan2000);
    int in2000to4000Count = count_if(v.begin(), v.end(), in2000to4000);
    int in4000to6000Count = count_if(v.begin(), v.end(), in4000to6000);
    int in6000to8000Count = count_if(v.begin(), v.end(), in6000to8000);
    int in8000to10000Count = count_if(v.begin(), v.end(), in8000to10000);

    double sum = accumulate(v.begin(), v.end(), 0.0);

    double average = sum / SIZE;

    cout << "Broj parni elementi: " << evenCount << endl;
    cout << "Broj na elementi pomali od 2000: " << lessThan2000Count << endl;
    cout << "Broj na elementi vo interval [2000, 4000): " << in2000to4000Count << endl;
    cout << "Broj na elementi vo interval [4000, 6000): " << in4000to6000Count << endl;
    cout << "Broj na elementi vo interval [6000, 8000): " << in6000to8000Count << endl;
    cout << "Broj na elementi vo interval [8000, 10000): " << in8000to10000Count << endl;
    cout << "Sredna vrednost na elementite: " << average << endl;


    return 0;
}
