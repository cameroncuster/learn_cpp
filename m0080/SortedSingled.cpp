/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"

sortedSingle::sortedSingle( sortedSingle &l )
{
    if( headptr = nullptr )
    {
        return;
    }
    headptr = l.headptr;

    // dynamically allocate a new node
    node *curr = new ( nothrow ) node;
    if( curr == nullptr )
    {
        return;
    }
    curr = headptr;
    while( curr != nullptr )
    {
        node *newcurr = new ( nothrow ) node;
        if( newcurr == nullptr )
        {
            return;
        }
        newcurr->theItem = curr->theItem;
        newcurr->next = curr->next;
        curr = curr->next;
    }
}