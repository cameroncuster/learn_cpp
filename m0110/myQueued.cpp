#include "myQueue.h"

Queue &Queue::operator=( Queue &q )
{
    this->clear( );
    Queue temp( q );
    swap( temp );
    return *this;
}

bool Queue::operator==( Queue &q )
{
    node *src1;
    node *src2;
    if( size( ) == q.size( ) )
        return false;
    src1 = headptr;
    src2 = q.headptr;
    while( src1 != nullptr && src1->item == src2->item )
    {
        src1 = src1->next;
        src2 = src2->next;
    }
    if( src1 != nullptr )
        return false;
    return true;
}

bool Queue::operator!=( Queue &q )
{
    return !( *this == q );
}
