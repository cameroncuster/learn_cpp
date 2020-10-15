#include "sortedSingle.h"

bool sortedSingle::remove( int item )
{
    node *prev = headptr;
    node *curr = headptr;
    if( empty( ) == true )
    {
        return false;
    }
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
    {
        return false;
    }

    prev->next = curr->next;
    delete curr;
    return true;
}

void sortedSingle::clear( )
{
    node *temp = headptr;
    while( headptr != nullptr )
    {
        headptr = headptr->next;
        delete temp;
        temp = headptr;
    }
    delete headptr;
}