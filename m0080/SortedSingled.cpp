/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"

sortedSingle::sortedSingle( sortedSingle &l )
{
    if( l.headptr == nullptr )
    {
        headptr = nullptr;
        return;
    }
    node *curr = l.headptr;

    // dynamically allocate a new node
    node *newcurr = new ( nothrow ) node;
    if( newcurr == nullptr )
    {
        return;
    }
    newcurr->theItem = curr->theItem;
    newcurr->next = curr->next;
    headptr = newcurr;
    curr = curr->next;

    while( curr != nullptr )
    {
        newcurr = new ( nothrow ) node;
        if( newcurr == nullptr )
        {
            return;
        }
        newcurr->theItem = curr->theItem;
        newcurr->next = curr->next;
        curr = curr->next;
    }
}