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
