// fill, fill_n, generate i generate_n

#include <iostream>

using namespace std;

#include <algorithm>
#include <vector>
#include <iterator>

char nextLetter();

int main()
{
    vector< char > chars( 10 );
    ostream_iterator< char > output( cout, " " );


    fill( chars.begin(), chars.end(), '5' );

    cout << "chars po popolnuvanje so 5ki:\n";
    copy( chars.begin(), chars.end(), output );


    fill_n( chars.begin(), 5, 'A' );

    cout << "\nchars po popolnuvanje dodeluvanje A na 5 elementi:\n";
    copy( chars.begin(), chars.end(), output );

    // generiranje na vrednosti na site elementi so nextLetter
    generate( chars.begin(), chars.end(), nextLetter );

    cout << "\n\nchars po generiranje na znaci A-J:\n";
    copy( chars.begin(), chars.end(), output );

    generate_n( chars.begin(), 5, nextLetter );

    cout << "\n\n chars po generiranje K-O za prvite 5 elementi\n";
    copy( chars.begin(), chars.end(), output );


    cout << endl;


    return 0;
}
// vrakja sledna bukva od abecedata (zapocnuva so A)
char nextLetter()
{
    static char letter = 'A';
    return letter++;

} // kraj na funkcija nextLetter
