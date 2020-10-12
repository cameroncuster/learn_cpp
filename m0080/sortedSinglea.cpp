#include "sortedSingle.h"

sortedSingle::sortedSingle( )
{
    headptr = nullptr;
}

bool sortedSingle::empty( )
{
    if( headptr == nullptr )
    {
        return true;
    }
    return false;
}

int sortedSingle::size( )
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

bool sortedSingle::find( int item )
{
    node *curr = headptr;
    if( empty( ) == true )
    {
        return false;
    }
    while( curr != nullptr )
    {
        if( curr->theItem == item )
        {
            return true;
        }
        curr = curr->next;
    }
    return false;
}

int sortedSingle::retrievePosition( int item )
{
    int count = 1;
    node *curr = headptr;
    if( empty( ) == true )
    {
        return 0;
    }
    while( curr != nullptr )
    {
        if( curr->theItem == item )
        {
            return count;
        }
        curr = curr->next;
        count++;
    }
    return 0;
}

sortedSingle::~sortedSingle( )
{
    clear( );
}