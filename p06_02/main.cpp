// Testiranje na funkcii  na set

#include <iostream>

using namespace std;
#include <set>
// definicija na double set type pod ime double_set
typedef set< double, less< double > > double_set;
#include <algorithm>


int main()
{
    const int SIZE = 5;
    double a[ SIZE ] = { 2.1, 4.2, 9.5, 2.1, 3.7 };
    double_set doubleSet( a, a + SIZE );
    ostream_iterator< double > output( cout, " " );
    cout << "doubleSet sodrzi: ";
    copy( doubleSet.begin(), doubleSet.end(), output );
    // p e pair sto sodrzi const_iterator i bool
    pair< double_set::const_iterator, bool > p;
    // vmetni 13.8 vo doubleSet; povratnata vrednost smesti ja vo pair p
    // p.first e lokacijata na 13.8 vo doubleSet
    // p.second dali 13.8 e vmetnata
    p = doubleSet.insert( 13.8 ); // 13.8 ja nema prethodno vo mnoзestvoto
    cout << "\n\n" << *( p.first )
         << ( p.second ? " e" : " ne e" ) << " vmetnata";
    cout << "\ndoubleSet sodrzi: ";
    copy( doubleSet.begin(), doubleSet.end(), output );
    // vmetni 9.5 vo doubleSet
    p = doubleSet.insert( 9.5 );  // 9.5 veke ja ima vo mnosestvoto
    cout << "\n\n" << *( p.first )
         << ( p.second ? " e" : " ne e" ) << " vmetnata";

    cout << "\ndoubleSet sodrzi: ";
    copy( doubleSet.begin(), doubleSet.end(), output );
    cout << endl;

    return 0;
}
