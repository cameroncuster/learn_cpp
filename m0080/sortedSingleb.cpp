#include "sortedSingle.h"

bool sortedSingle::insert( int item )
{
    node *newItem;
    node *prev = headptr;
    node *curr = headptr;
    if( empty( ) == true )
    {
        headptr = newItem;
        return true;
    }
    while(  curr->next != nullptr )
    {
        if( prev->theItem < item && item < curr->theItem )
        {
            newItem->theItem = item;
            prev->next = newItem;
            newItem->next = curr->next;
            return true;
        }
    }
    return false;
}

void sortedSingle::print( ostream &out, string seperator=", " )
{
    node *temp;
    if( empty( ) == true )
    {
        return;
    }
    while( temp->next != nullptr )
    {
        out << temp->theItem;
        out << seperator;
        temp = temp->next;
    }
    out << temp->theItem;
}