// Vrsi parcijalna specijalizacija
#include <iostream>
using namespace std;

template<class T, class U>
class C {
public:
    void f() { cout << "Primaren template\n"; }
};

template<class U>
class C<int, U> {
public:
    void f() { cout << "T == int\n"; }
};

template<class T>
class C<T, double> {
public:
    void f() { cout << "U == double\n"; }
    };

    template<class T, class U>
    class C<T*, U> {
    public:
        void f() { cout << "T*  \n"; }
        };

        template<class T, class U>
        class C<T, U*> {
        public:
            void f() { cout << "U*  \n"; }
            };

            template<class T, class U>
            class C<T*, U*> {
            public:
                void f() { cout << "T* i U*  \n"; }
                };

                template<class T>
                class C<T, T> {
                public:
                    void f() { cout << "T == U\n"; }
                    };

                    int main() {
                        C<float, int>().f();    // 1: Primaren template
                        C<int, float>().f();    // 2: T == int
                        C<float, double>().f(); // 3: U == double
                        C<float, float>().f();  // 4: T == U
                        C<float*, float>().f(); // 5: T* [T e float]
                        C<float, float*>().f(); // 6: U* [U e float]
                        C<float*, int*>().f();  // 7: T* i U* [float,int]
                        // Slednite specijalizacii se dvosmisleni.
                        //   8: C<int, int>().f();
                        //   9: C<double, double>().f();
                        //  10: C<float*, float*>().f();
                        //  11: C<int, int*>().f();
                        //  12: C<int*, int*>().f();
                    } // kraj na main
