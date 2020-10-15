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
    curr = headptr;
    while( l.curr != nullptr )
    {
        curr->theItem = l.curr->theItem;
        curr->next = l.curr->next;
        l.curr = l.curr->next;
    }
}