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
    if( empty( ) == true )
    {
        headptr = newItem;
        return true;
    }
    node *prev = headptr;
    node *curr = headptr;
    if( item <= curr->theItem )
    {
        newItem->next = curr;
        headptr = newItem;
        return true;
    }
    while( curr != nullptr && curr->theItem <= newItem->theItem )
    {
        prev = curr;
        curr = curr->next;
    }
    prev->next = newItem;
    newItem->next = curr;
    return true;
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