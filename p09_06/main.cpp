/*
Вежби:
1. Креирај два вектори со случаен број на елементи кој е во интервалот
[1, 1000). Потоа ископирај го вториот вектор во првиот со copy. Претходно
провери дали првиот вектор има големина поголема или еднаква на големината
на првиот. Ако не е, да се изврши фрлање на исклучок пред да се изврши
копирањето на векторот. Постапката да се повторува во циклус во кој е
сместена try-catch секвенца.

*/
#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <exception>

using namespace std;


class NotEnoughSpaceException : public exception {
public:
    const char* what() const noexcept override {
        return "Prviot vektor nema dovolna golemina za kopiranje!";
    }
};

int main() {
    srand(static_cast<unsigned int>(time(0)));

    while (true) {
        try {
            int size1 = rand() % 999 + 1;
            int size2 = rand() % 999 + 1;

            vector<int> v1(size1);
            vector<int> v2(size2);

            generate(v1.begin(), v1.end(), []() { return rand() % 100; });
            generate(v2.begin(), v2.end(), []() { return rand() % 100; });

            if (v1.size() < v2.size()) {
                throw NotEnoughSpaceException();
            }

            copy(v2.begin(), v2.end(), v1.begin());

            cout << "Vektorot v2 e uspesno kopiran vo vektorot v1." << endl;
            cout << "Goleminata na vektorot v1: " << v1.size() << endl;
            cout << "Goleminata na vektorot v2: " << v2.size() << endl;

            break;
        }
        catch (const NotEnoughSpaceException& e) {
            cout << "Iskluchok: " << e.what() << endl;
            cout << "Obidete se povtorno so drugi golemini na vektorite." << endl;
        }
    }

    return 0;
}
