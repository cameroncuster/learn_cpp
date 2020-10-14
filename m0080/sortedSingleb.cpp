#include "sortedSingle.h"
#include <sstream>
#include <string>
using std::ostream;
using std::string;
using std::nothrow;
using namespace std;

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
            newItem->next = curr;
        }
        else
        {
            curr->next = newItem;
        }
        return true;
    }
    while( curr != nullptr )
    {
        if( curr->theItem == item )
        {
            if( curr == headptr )
            {
                headptr = newItem;
                newItem->next = curr;
                return true;
            }
            prev->next = newItem;
            newItem->next = curr;
            return true;
        }
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

void sortedSingle::print( ostream &out, string seperator )
{
    node *temp = headptr;
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