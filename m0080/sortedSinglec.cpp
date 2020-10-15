#include "sortedSingle.h"

bool sortedSingle::remove( int item )
{
    node *prev = headptr;
    node *curr = headptr;
    if( empty( ) == true || item < curr->theItem )
    {
        return false;
    }
    if( item == curr->theItem )
    {
        headptr = curr->next;
        return true;
    }
    while( curr->next != nullptr && curr->theItem != item )
    {
        prev = curr;
        curr = curr->next;
    }
    if( curr->theItem == item )
    {
        prev->next = curr->next;
        return true;
    }
    return false;
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