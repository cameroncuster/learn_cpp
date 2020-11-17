/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"

sortedSingle::sortedSingle( sortedSingle &l )
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

sortedSingle::iterator sortedSingle::begin( )
{
    return iterator( headptr );
}

sortedSingle::iterator sortedSingle::end( )
{
    return iterator( nullptr );
}

sortedSingle::iterator::iterator( node *ptr )
{
    itptr = ptr;
}

sortedSingle::iterator::iterator( const iterator &it )
{
    itptr = it.itptr;
}

sortedSingle::iterator &sortedSingle::iterator::operator++( )
{
    itptr = itptr->next;
    return *this;
}

sortedSingle::iterator sortedSingle::iterator::operator++( int )
{
    iterator temp( *this );
    itptr = itptr->next;
    return temp;
}

int &sortedSingle::iterator::operator*( ) const
{
    return itptr->theItem;
}

int *sortedSingle::iterator::operator->( ) const
{
    return &( itptr->theItem );
}

bool sortedSingle::iterator::operator==( const iterator &x ) const
{
    return itptr == x.itptr;
}

bool sortedSingle::iterator::operator!=( const iterator &x ) const
{
    return itptr != x.itptr;
}