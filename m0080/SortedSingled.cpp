/******************************************************************************
 * @file    
 *
 * @brief   This file is reserved for future use.  Do not edit.
 *****************************************************************************/
#include "sortedSingle.h"

sortedSingle::sortedSingle( sortedSingle &l)
{
    // temp val to walk through
    node *temp = headptr;

    // set a new headptr equal to the first node in the new list
    node *newheadptr = temp;

    // walk through the list allocating memory dynamically for each node in the new list
    while( temp != nullptr )
    {
        // set each value in the new list equal to the value in the old list
        node *newval = new ( nothrow ) node;
        if( newval == nullptr )
        {
            exit( 0 );
        }
        newval = temp;
        newval->next = temp->next;
        temp = temp->next;
    }
}