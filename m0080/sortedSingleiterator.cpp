#include "sortedSingle.h"

template <typename TY>
sortedSingle<TY>::iterator sortedSingle<TY>::begin( )
{
    return iterator( headptr );
}

template <typename TY>
sortedSingle<TY>::iterator sortedSingle<TY>::end( )
{
    return iterator( nullptr );
}

template <typename TY>
sortedSingle<TY>::iterator::iterator( node *ptr )
{
    itptr = ptr;
}

template <typename TY>
sortedSingle<TY>::iterator::iterator( const iterator &it )
{
    itptr = it.itptr;
}

template <typename TY>
sortedSingle<TY>::iterator &sortedSingle<TY>::iterator::operator++( )
{
    itptr = itptr->next;
    return *this;
}

template <typename TY>
sortedSingle<TY>::iterator sortedSingle<TY>::iterator::operator++( int )
{
    iterator temp( *this );
    itptr = itptr->next;
    return temp;
}

template <typename TY>
int &sortedSingle<TY>::iterator::operator*( ) const
{
    return itptr->theItem;
}

template <typename TY>
int *sortedSingle<TY>::iterator::operator->( ) const
{
    return &( itptr->theItem );
}

template <typename TY>
bool sortedSingle<TY>::iterator::operator==( const iterator &x ) const
{
    return itptr == x.itptr;
}

template <typename TY>
bool sortedSingle<TY>::iterator::operator!=( const iterator &x ) const
{
    return itptr != x.itptr;
}