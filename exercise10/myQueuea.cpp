/** ***************************************************************************
 * @file    
 *
 * @brief   Implements of the enqueue function for the Queue class.
 *****************************************************************************/
#include "myQueue.h"


/** ***************************************************************************
 * @brief   Adds an object onto the end of this Queue
 *
 * @param   word    The word to be placed at the end of the queue
 *
 * @returns True if it succeeds, false if it fails.
 *****************************************************************************/
bool Queue::enqueue( string word )
{
    node *temp = new ( nothrow ) node;
    if( temp == nullptr )
        exit( 1 );
    temp->item = word;
    temp->next = nullptr;
    if( headptr == nullptr )
    {
        headptr = temp;
        tailptr = temp;
        return true;
    }
    tailptr->next = temp;
    tailptr = temp;
    return true;
}
