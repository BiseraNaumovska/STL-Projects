//  get, getline, put, eof.

#include <iostream>

using namespace std;

int main()
{
    int character; // koristi int za pretstavuvanje na  EOF
    const int SIZE = 80;
    char buffer1[ SIZE ];
    char buffer2[ SIZE ];

    cout << "Vnesi recenica:" << endl;
    cin >> buffer1;


    cout << "\nStringot procitan so cin e:" << endl
         << buffer1 << endl << endl;

    cin.get( buffer2, SIZE );

    cout << "Stringot procitan so cin.get e:" << endl
         << buffer2 << endl;

    cin.ignore();//Potrebno za da se otstrani '\n' od vlezniot potok
    cout << "Vnesi recenica:" << endl;
    cin.getline( buffer1, SIZE );


    cout << "\nRecenicata e:" << endl << buffer1 << endl;

    cout << "Pred vnes cin.eof() e " << cin.eof() << endl
         << "Vnesi recenica, end-of-file za kraj:" << endl;

    //Vrednosta na end-of-file zavisi od OS
    //<Ctrl>-Z na PC, <Ctrl>-D na Linux i Mac
    //Najcesto e potrebno da se pritisne <Enter> po <Ctrl>-Z


    while ( ( character = cin.get() ) != EOF )
        cout.put( character );


    cout << "\nEOF na ovoj sistem e: " << character << endl;
    cout << "Po vnes, cin.eof() e " << cin.eof() << endl;
    return 0;

}
