#include <iostream>

using namespace std;

template<typename R, typename P>
R implicit_cast(const P& p) {
    return p;
}

int main() {
    int i = 1;
    float x = implicit_cast<float>(i);
    int j = implicit_cast<int>(x);
    //! char* p = implicit_cast<char*>(i);
    cout<<i<<x<<j<<endl;
    return 0;
} //kraj na main
