#include "sortedSingle.h"
#include "..\\catch.hpp"
#include <sstream>
#include <iostream>
using namespace std;

TEST_CASE( "constructor" )
{
    // create a list of values
    sortedSingle list1;
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    // empty list
    sortedSingle listempty;

    // test empty list
    CHECK( listempty.empty( ) == true );
    CHECK( listempty.size( ) == 0 );

    // test list of values
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 5 );
}

TEST_CASE( "destructor" )
{
    /*
    // create a list of values
    sortedSingle list1;
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );
    */

    // empty list
    sortedSingle listempty;

    // test and empty list
    REQUIRE( listempty.empty( ) == true );
    REQUIRE( listempty.size( ) == 0 );

    /*
    // test a list of values
    REQUIRE( list1.empty( ) == true );
    REQUIRE( list1.size( ) == 0 );
    */
}

TEST_CASE( "empty" )
{
    // create a list of values
    sortedSingle list1;
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    // empty list
    sortedSingle listempty;

    // test an empty list
    REQUIRE( listempty.empty( ) == true );

    // test a list of values for true and false returns with boundry testing
    REQUIRE( list1.empty( ) == false );
}

TEST_CASE( "size" )
{
    // create a list of values
    sortedSingle list1;
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    // empty list
    sortedSingle listempty;

    // test an empty list
    REQUIRE( listempty.size( ) == 0 );

    // test a list of values for true and false returns with boundry testing
    REQUIRE( list1.size( ) == 5 );
}

TEST_CASE( "find" )
{
    // create a list of values
    sortedSingle list1;
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    // empty list
    sortedSingle listempty;
    
    // test an empty list
    REQUIRE( listempty.find( 5 ) == false );

    // test a list of values for true and false returns with boundry testing
    REQUIRE( list1.find( 5 ) == false );
    REQUIRE( list1.find( 60 ) == false );
    REQUIRE( list1.find( 35 ) == false );
    REQUIRE( list1.find( 10 ) == true );
    REQUIRE( list1.find( 50 ) == true);
    REQUIRE( list1.find( 30 ) == true );
}

TEST_CASE( "retrievePosition" )
{

    // create a list of values
    sortedSingle list1;
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    // empty list
    sortedSingle listempty;

    // test an empty list
    REQUIRE( listempty.retrievePosition( 10 ) == 0 );

    // test a list of values for a location or 0 if not found in the list
    REQUIRE( list1.retrievePosition( 0 ) == 0 );
    REQUIRE( list1.retrievePosition( 10 ) == 1 );
    REQUIRE( list1.retrievePosition( 20 ) == 2 );
    REQUIRE( list1.retrievePosition( 30 ) == 3 );
    REQUIRE( list1.retrievePosition( 40 ) == 4 );
    REQUIRE( list1.retrievePosition( 50 ) == 5 );
    REQUIRE( list1.retrievePosition( 60 ) == 0 );
}

TEST_CASE( "insert" )
{
    sortedSingle list1;

    // insert 10 and verify
    REQUIRE( list1.insert( 10 ) == true );
    REQUIRE( list1.find( 10 ) == true );
    REQUIRE( list1.retrievePosition( 10 ) == 1 );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 1 );

    // insert 30 and verify
    REQUIRE( list1.insert( 30 ) == true );
    REQUIRE( list1.find( 30 ) == true );
    REQUIRE( list1.retrievePosition( 30 ) == 2 );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 2 );

    // insert 20 and verify
    REQUIRE( list1.insert( 20 ) == true );
    REQUIRE( list1.find( 20 ) == true );
    REQUIRE( list1.retrievePosition( 20 ) == 2 );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 3 );

    // insert 50 and verify
    REQUIRE( list1.insert( 50 ) == true );
    REQUIRE( list1.find( 50 ) == true );
    REQUIRE( list1.retrievePosition( 50 ) == 4 );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 4 );

    // insert 40 and verify
    REQUIRE( list1.insert( 40 ) == true );
    REQUIRE( list1.find( 40 ) == true );
    REQUIRE( list1.retrievePosition( 40 ) == 4 );
    CHECK( list1.empty( ) == false );
    CHECK( list1.size( ) == 5 );
}

TEST_CASE( "print" )
{
    // string stream
    ostringstream soutempty;
    ostringstream sout1;

    // list of values
    sortedSingle list1;
    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    // empty list
    sortedSingle listempty;

    // check empty
    listempty.print( soutempty );
    REQUIRE( soutempty.str( ) == "" );

    //check list of values
    list1.print( sout1 );
    REQUIRE( sout1.str( ) == "10, 20, 30, 40, 50" );
}