/*
1.Табелирај ја вредноста на i, i2,   и  за вредности на i=1,2,... n.
Ведностите да бидат прикажани во колони со ширина m (за децималните вредности
да се дефинира соодветна прецизност). Вредностите на n и m треба да се
внесат на почетокот на програмата.
*/

#include <iostream>
#include <iomanip>
using namespace std;

int main()
{
    int n=5, m=10;
    //cout << "Vnesi n (maksimalen broj): ";
   // cin >> n;
   // cout << "Vnesi m (shirinata na kolonite): ";
    //cin >> m;

    cout << setw(m) << "i" << setw(m) << "i^2" << setw(m) << "i^3" << endl;

    for (int i = 1; i <= n; ++i) {
        cout << fixed << setprecision(2)
             << setw(m) << static_cast<double>(i)
             << setw(m) << static_cast<double>(i * i)
             << setw(m) << static_cast<double>(i * i * i) << endl;
    }
    return 0;
}
