/*
2.Напиши програма со која сите зборови од текстуална датотека со
големина помала од 10 знаци ќе ги запише во друга текстуална датотека.
*/
#include <iostream>
#include <fstream>
#include <string>

using namespace std;

int main() {
    ifstream inputFile;
    ofstream outputFile;


    inputFile.open("datoteka1.txt");
    if (!inputFile) {
        cerr << "Ne moze da se otvori vlezna datoteka 1!" << endl;
        return 1;
    }

    outputFile.open("datoteka2.txt");
    if (!outputFile) {
        cerr << "Ne moze da se otvori izlezna datoteka 2!" << endl;
        return 1;
    }

    string word;

    while (inputFile >> word) {
        if (word.length() < 10) {
            outputFile << word << endl;
        }
    }

    inputFile.close();
    outputFile.close();

    cout << "Zborovite pomali od 10 znaci se zabelezeni vo datoteka1.txt" << endl;

    ifstream outputFileRead("datoteka2.txt");
    if (!outputFileRead) {
        cerr << "Ne moze da se otvori datotekata 2 za citanje!" << endl;
        return 1;
    }
    cout << "Sodrzinata na datotekata 2:" << endl;
    while (outputFileRead >> word) {
        cout << word << " ";
    }
    cout << endl;

    outputFileRead.close();


    return 0;
}
