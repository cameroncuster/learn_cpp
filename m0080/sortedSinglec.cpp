#include "sortedSingle.h"

bool sortedSingle::remove( int item )
{
    node *prev = headptr;
    node *curr = headptr;
    if( empty( ) == true )
    {
        return false;
    }
    if( size( ) == 1 )
    {
        if( curr->theItem == item )
        {
            headptr = nullptr;
            return true;
        }
        return false;
    }
    if( curr->theItem == item )
    {
        headptr = curr->next;
        return true;
    }
    while( curr != nullptr )
    {
        if( curr->theItem == item )
        {
            prev->next = curr->next;
            return true;
        }
        prev = curr;
        curr = curr->next;
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