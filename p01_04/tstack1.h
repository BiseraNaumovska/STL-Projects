#ifndef TSTACK1_H
#define TSTACK1_H

template< class T >
class Stack {

public:
    Stack( int = 10 );  // default constructor (golemina na sklad=10)

    // destructor
    ~Stack()
    {
        delete [] stackPtr;

    } // end ~Stack destructor

    bool push( const T& );  // push
    bool pop( T& );         // pop

    // Opredeli dali skladot e prazen
    bool isEmpty() const
    {
        return top == -1;

    } // kraj na isEmpty

    // Opredeli dali skladot e poln
    bool isFull() const
    {
        return top == size - 1;

    } // kraj na isFull

private:
    int size;     // broj na elementi vo skladot
    int top;      // lokacija na elementot na vrvot
    T *stackPtr;  // pokazuvac kon skadot

}; // kraj na klasa Stack

// konstruktor
template< class T >
Stack< T >::Stack( int s )
{
    size = s > 0 ? s : 10;
    top = -1;  // Na pocetokot skladot e prazen
    stackPtr = new T[ size ]; // alociraj memorija za elementite

} // kraj na Stack constructor

// push
// pri uspeh, vrati true; inaku, vrati false
template< class T >
bool Stack< T >::push( const T &pushValue )
{
    if ( !isFull() ) {
        stackPtr[ ++top ] = pushValue; //smesti element na skladot
        return true;

    }

    return false;

} //kraj na push

// pop
// pri uspeh, vrati true; inaku, vrati false
template< class T >
bool Stack< T >::pop( T &popValue )
{
    if ( !isEmpty() ) {
        popValue = stackPtr[ top-- ];  //otstrani element od skladot
        return true;

    }

    return false;

} // kraj na pop

#endif
