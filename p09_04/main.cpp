
// Brisenje na objekti po exception

#include <iostream>

using namespace std;


class Trace {
    static int counter;
    int objid;
public:
    Trace() {
        objid = counter++;
        cout << "konstruiram Trace #" << objid << endl;
        if(objid == 3) throw 3;
    }
    ~Trace() {
        cout << "unistuvam Trace #" << objid << endl;
    }
};

int Trace::counter = 0;




int main()
{
    try {
        Trace n1;
        // Frla isklucok:
        Trace array[5];
        Trace n2;  // nema da se izvrsi.
    } catch(int i) {
        cout << "faten " << i << endl;
    }

    return 0;
}
