#include "sortedSingle.h"
#include "..\\catch.hpp"
using namespace std;

TEST_CASE( "TEMPLATE CLASS - INTIGER LIST" )
{
    sortedSingle<int> intlist;

    intlist.insert( 10 );
    intlist.insert( 20 );
    intlist.insert( 30 );
    intlist.insert( 40 );
    intlist.insert( 50 );
}

TEST_CASE( "TEMPLATE CLASS - STRING LIST" )
{
    sortedSingle<string> stringlist;

    stringlist.insert( "a" );
    stringlist.insert( "b" );
    stringlist.insert( "c" );
    stringlist.insert( "d" );
    stringlist.insert( "e" );
}

TEST_CASE( "TEMPLATE CLASS - DOUBLE LIST" )
{
    sortedSingle<double> doublelist;

    doublelist.insert( 1.1 );
    doublelist.insert( 2.2 );
    doublelist.insert( 3.3 );
    doublelist.insert( 4.4 );
    doublelist.insert( 5.5 );
}
