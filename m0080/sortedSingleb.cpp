#include "sortedSingle.h"
using std::ostream;
using std::string;
using std::nothrow;

bool sortedSingle::insert( int item )
{
    node *newItem;
    newItem = new ( nothrow ) node;
    if( newItem == nullptr )
    {
        return false;
    }
    newItem->theItem = item;
    newItem->next = nullptr;
    node *prev = headptr;
    node *curr = headptr;
    if( empty( ) == true )
    {
        headptr = newItem;
        return true;
    }
    if( size( ) == 1 )
    {
        if( curr->theItem > item )
        {
            headptr = newItem;
        }
        else
        {
            curr->next = newItem;
        }
        return true;
    }
    while( curr != nullptr )
    {
        if( prev->theItem < item && item < curr->theItem )
        {
            prev->next = newItem;
            newItem->next = curr;
            return true;
        }
        if( curr->next == nullptr && curr->theItem < item )
        {
            curr->next = newItem;
            return true;
        }
        prev = curr;
        curr = curr->next;
    }
    return false;
}
/*
void sortedSingle::print( ostream &out, string seperator )
{
    node *temp;
    temp = new ( nothrow ) node;
    if( temp == nullptr )
    {
        return;
    }
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
*/