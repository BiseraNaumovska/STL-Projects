/*
2.      Дадени се три листи од e-mail адреси. Некои адреси се појавуваат
само во една од листите, а некои се повторуваат и во другите листи. Напиши
програма со која ќе се состави една листа во која ќе се содржат сите
адреси по еднаш.
*/
#include <iostream>
#include <vector>
#include <list>
#include <algorithm>
#include <set>
#include <string>
#include <iterator>
using namespace std;

int main()
{
    list<string> lista1 = {"bisera.naumovska@gmail.com", "markonaumovski7@yahoo.com", "natenaumovska@hotmail.com"};
    list<string> lista2 = {"markonaumovski7@yahoo.com", "velenaumovski1973@gmail.com", "og_maxim@outlook.com"};
    list<string> lista3 = {"natenaumovska@hotmail.com", "og_maxim@yahoo.com", "bisera.naumovska@gmail.com"};

    list<string> unikatniAdresi;


    // site listi ke gi stavime vo edna lista: unikatniAdresi
    unikatniAdresi.merge(lista1);
    unikatniAdresi.merge(lista2);
    unikatniAdresi.merge(lista3);

    // za da ne se dupliraat elementite, ke ja sortirame, pa ke gi ostranime duplikatite so upotreba na MERGE -> samo vo listata shto ja prenesuvame ako ima duplikat, se vadi
    //sega sakam vo unikatniAdresi listata da gi sortiram i izvadam duplikatote
    unikatniAdresi.sort();
    unikatniAdresi.unique();


    cout << "Site unikatni e-mail adresi:\n";
    ostream_iterator< string > output( cout, " \n" );
    copy( unikatniAdresi.begin(), unikatniAdresi.end(), output );

    return 0;
}
