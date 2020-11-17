#include "sortedSingle.h"

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