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
    if( empty( ) == true )
    {
        return false;
    }
    node *curr = headptr;
    while( curr->next != nullptr )
    {
        if( curr->theItem == item )
        {
            return true;
        }
    }
    return false;
}

int sortedSingle::retrievePosition( int item )
{
    if( empty( ) == true )
    {
        return 0;
    }
    int count = 1;
    node *curr = headptr;
    while( curr->next != nullptr )
    {
        if( curr->theItem == item )
        {
            return count;
        }
        count++;
    }
    return 0;
}

void sortedSingle::clear( )
{
    // free all the nodes in the linked list and restore head ptr to nullptr
}

sortedSingle::~sortedSingle( )
{
    sortedSingle::clear( );
}