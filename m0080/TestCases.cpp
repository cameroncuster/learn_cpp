#include "sortedSingle.h"
#include "..\\catch.hpp"
#include <sstream>
#include <iostream>

using namespace std;


TEST_CASE( "constructor" )
{
    sortedSingle list1;
    REQUIRE( list1.empty( ) == true );
    REQUIRE( list1.size( ) == 0 );
}

TEST_CASE( "destructor" )
{
    sortedSingle list1;
    REQUIRE( list1.empty( ) == true );
    REQUIRE( list1.size( ) == 0 );
}

TEST_CASE( "find" )
{
    sortedSingle list1;
    REQUIRE( list1.find( 10 ) == false );
}

TEST_CASE( "retrievePosition" )
{
    sortedSingle list1;
    REQUIRE( list1.retrievePosition( 10 ) == 0 );
}

TEST_CASE( "insert" )
{
    sortedSingle list1;
    REQUIRE( list1.insert( 10 ) == true );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 1 );
    REQUIRE( list1.insert( 30 ) == true );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 2 );
    REQUIRE( list1.insert( 20 ) == true );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 3 );
}