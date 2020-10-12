#include "sortedSingle.h"
/*
bool sortedSingle::remove( int item )
{
    if( empty( ) == true )
    {
        return false;
    }
    node *prev = headptr;
    node *curr = headptr;
    while( curr->theItem != item && curr->next != nullptr )
    {
        prev = curr;
        curr = curr->next;
    }
    if( curr->theItem == item )
    {
        prev->next = curr->next;
    }
    delete curr;
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
}
*/