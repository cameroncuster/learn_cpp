#include <iostream>
#include <sstream>
#include <string>
using std::ostream;
using std::string;
using std::nothrow;
using namespace std;

template <class TY>
class sortedSingle
{
    private:

    struct node
    {
        TY theItem;
        node *next;
    };
    node *headptr;

    public:

    // copy constructor for the linked list
    sortedSingle( sortedSingle<TY> &l );

    // default constructor and destructor
    sortedSingle( );
    ~sortedSingle( );

    // foundational linked list membership functions
    bool find( TY item );
    int retrievePosition( TY item );
    int size( );
    bool empty( );
    bool insert( TY item );
    void print( ostream &out, string seperator = ", " );
    bool remove( TY item );
    void clear( );
};

// functions for template avaliable at compile time
template <typename TY>
sortedSingle<TY>::sortedSingle( sortedSingle<TY> &l )
{
    node *src = nullptr;
    node *dest = nullptr;
    headptr = nullptr;
    if( l.headptr == nullptr )
        return;
    headptr = new ( nothrow ) node;
    if( headptr == nullptr )
        exit( 1 );
    headptr->theItem = l.headptr->theItem;
    headptr->next = nullptr;

    src = l.headptr->next;
    dest = headptr;
    while( src != nullptr )
    {
        dest->next = new ( nothrow ) node;
        if( dest->next == nullptr )
            exit( 1 );
        dest = dest->next;
        dest->theItem = src->theItem;
        dest->next = nullptr;
        src = src->next;
    }
}

template <typename TY>
bool sortedSingle<TY>::remove( TY item )
{
    node *prev = headptr;
    node *curr = headptr;
    if( empty( ) == true )
        return false;
    if( item == curr->theItem )
    {
        headptr = curr->next;
        delete curr;
        return true;
    }
    while( curr != nullptr && curr->theItem != item )
    {
        prev = curr;
        curr = curr->next;
    }
    if( curr == nullptr )
        return false;
    prev->next = curr->next;
    delete curr;
    return true;
}

template <typename TY>
void sortedSingle<TY>::clear( )
{
    node *temp = headptr;
    while( headptr != nullptr )
    {
        headptr = headptr->next;
        delete temp;
        temp = headptr;
    }
}

template <typename TY>
bool sortedSingle<TY>::insert( TY item )
{
    node *newItem;
    newItem = new ( nothrow ) node;
    if( newItem == nullptr )
        return false;
    newItem->theItem = item;
    newItem->next = nullptr;
    if( empty( ) == true )
    {
        headptr = newItem;
        return true;
    }
    node *prev = headptr;
    node *curr = headptr;
    if( item <= curr->theItem )
    {
        newItem->next = curr;
        headptr = newItem;
        return true;
    }
    while( curr != nullptr && curr->theItem <= newItem->theItem )
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = newItem;
    newItem->next = curr;
    return true;
}

template <typename TY>
void sortedSingle<TY>::print( ostream &out, string seperator )
{
    node *temp = headptr;
    if( empty( ) == true )
        return;
    while( temp->next != nullptr )
    {
        out << temp->theItem;
        out << seperator;
        temp = temp->next;
    }
    out << temp->theItem;
}

template <typename TY>
sortedSingle<TY>::sortedSingle( )
{
    headptr = nullptr;
}

template <typename TY>
bool sortedSingle<TY>::empty( )
{
    if( headptr == nullptr )
        return true;
    return false;
}

template <typename TY>
int sortedSingle<TY>::size( )
{
    int count = 0;
    node *curr = headptr;
    while( curr != nullptr )
    {
        curr = curr->next;
        count++;
    }
    return count;
}

template <typename TY>
bool sortedSingle<TY>::find( TY item )
{
    node *curr = headptr;
    if( empty( ) == true )
        return false;
    while( curr != nullptr )
    {
        if( curr->theItem == item )
            return true;
        curr = curr->next;
    }
    return false;
}

template <typename TY>
int sortedSingle<TY>::retrievePosition( TY item )
{
    int count = 1;
    node *curr = headptr;
    if( empty( ) == true )
        return 0;
    while( curr != nullptr )
    {
        if( curr->theItem == item )
            return count;
        curr = curr->next;
        count++;
    }
    return 0;
}

template <typename TY>
sortedSingle<TY>::~sortedSingle( )
{
    clear( );
}
