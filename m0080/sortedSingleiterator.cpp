#include "sortedSingle.h"

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