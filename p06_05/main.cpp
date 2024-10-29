// Test za STL stack.
#include <iostream>

using namespace std;

#include <stack>   // definicija na stack adapter
#include <vector>  // definicija na vector class-template
#include <list>    // definicija na list class-template

// prototip na popElements function-template
template< class T >
void popElements( T &stackRef );



int main()
{
    // stack so default underlying deque
    stack< int > intDequeStack;
    // stack so underlying vector
    stack< int, vector< int > > intVectorStack;
    // stack so underlying list
    stack< int, list< int > > intListStack;
    // push vrednosti 0-9 na sekoj stack
    for ( int i = 0; i < 10; ++i ) {
        intDequeStack.push( i );
        intVectorStack.push( i );
        intListStack.push( i );
    }
    // prikazi gi i otstrani gi vrednostite od sekoj stack
    cout << "Pop od intDequeStack: ";
    popElements( intDequeStack );
    cout << "\nPop od intVectorStack: ";
    popElements( intVectorStack );
    cout << "\nPop od intListStack: ";
    popElements( intListStack );
    cout << endl;
    return 0;
}

// pop na elementite od objekt stack na koj pokazuva stackRef
template< class T >
void popElements( T &stackRef )
{
    while ( !stackRef.empty() ) {
        cout << stackRef.top() << " ";  // prikazi go elementot na vrvot
        stackRef.pop();                 // otstrani go elementot na vrvot
    }
} // kraj na funkcijata popElements
