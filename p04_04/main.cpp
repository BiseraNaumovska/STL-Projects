
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main()
{
    vector< int > years;
    years.push_back( 1962 );
    years.push_back( 1992 );
    years.push_back( 2001 );
    years.push_back( 1999 );
    sort( years.begin(), years.end() );
    vector< int >::iterator i;
    for ( i = years.begin(); i != years.end(); ++i )
        cout << *i <<endl;

    return 0;
}
