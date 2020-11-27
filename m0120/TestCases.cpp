#include "..\\catch.hpp"
#include "sortedSingle.h"
using namespace std;

TEST_CASE( "INTTEMPLATE" )
{
    sortedSingle<int> intlist;

    ostringstream intsout;

    // fill the list
    REQUIRE( intlist.insert( 10 ) == true );
    REQUIRE( intlist.insert( 20 ) == true );
    REQUIRE( intlist.insert( 30 ) == true );
    REQUIRE( intlist.insert( 40 ) == true );
    REQUIRE( intlist.insert( 50 ) == true );


    SECTION( "PRINT COMPARE" )
    {
        intlist.print( intsout );
        REQUIRE( intsout.str( ) == "10, 20, 30, 40, 50" );
    }

    // find and retrieve the positions of some items
    REQUIRE( intlist.find( 00 ) == false );
    REQUIRE( intlist.find( 10 ) == true );
    REQUIRE( intlist.find( 20 ) == true );
    REQUIRE( intlist.find( 30 ) == true );
    REQUIRE( intlist.find( 40 ) == true );
    REQUIRE( intlist.find( 50 ) == true );
    REQUIRE( intlist.find( 60 ) == false );
    
    REQUIRE( intlist.retrievePosition( 00 ) == 0 );
    REQUIRE( intlist.retrievePosition( 10 ) == 1 );
    REQUIRE( intlist.retrievePosition( 20 ) == 2 );
    REQUIRE( intlist.retrievePosition( 30 ) == 3 );
    REQUIRE( intlist.retrievePosition( 40 ) == 4 );
    REQUIRE( intlist.retrievePosition( 50 ) == 5 );
    REQUIRE( intlist.retrievePosition( 60 ) == 0 );

    // remove the items from the list and print
    REQUIRE( intlist.remove( 00 ) == false );
    REQUIRE( intlist.remove( 10 ) == true );
    REQUIRE( intlist.remove( 50 ) == true );
    REQUIRE( intlist.remove( 20 ) == true );
    REQUIRE( intlist.remove( 30 ) == true );
    REQUIRE( intlist.remove( 40 ) == true );
    REQUIRE( intlist.remove( 10 ) == false );
    
    SECTION( "PRINT COMPARE" )
    {
        intlist.print( intsout );
        REQUIRE( intsout.str( ) == "" );
    }
}

TEST_CASE( "STRTEMPLATE" )
{
    sortedSingle<string> stringlist;

    ostringstream stringsout;

    // fill the list
    REQUIRE( stringlist.insert( "a" ) == true );
    REQUIRE( stringlist.insert( "b" ) == true );
    REQUIRE( stringlist.insert( "c" ) == true );
    REQUIRE( stringlist.insert( "d" ) == true );
    REQUIRE( stringlist.insert( "e" ) == true );

    SECTION( "PRINT COMPARE" )
    {
        stringlist.print( stringsout );
        REQUIRE( stringsout.str( ) == "a, b, c, d, e" );
    }

    // find and retrieve the positions of some items
    REQUIRE( stringlist.find( "x" ) == false );
    REQUIRE( stringlist.find( "a" ) == true );
    REQUIRE( stringlist.find( "b" ) == true );
    REQUIRE( stringlist.find( "c" ) == true );
    REQUIRE( stringlist.find( "d" ) == true );
    REQUIRE( stringlist.find( "e" ) == true );
    REQUIRE( stringlist.find( "y" ) == false );
    
    REQUIRE( stringlist.retrievePosition( "x" ) == 0 );
    REQUIRE( stringlist.retrievePosition( "a" ) == 1 );
    REQUIRE( stringlist.retrievePosition( "b" ) == 2 );
    REQUIRE( stringlist.retrievePosition( "c" ) == 3 );
    REQUIRE( stringlist.retrievePosition( "d" ) == 4 );
    REQUIRE( stringlist.retrievePosition( "e" ) == 5 );
    REQUIRE( stringlist.retrievePosition( "y" ) == 0 );

    // remove the items from the list and print
    REQUIRE( stringlist.remove( "x" ) == false );
    REQUIRE( stringlist.remove( "a" ) == true );
    REQUIRE( stringlist.remove( "b" ) == true );
    REQUIRE( stringlist.remove( "c" ) == true );
    REQUIRE( stringlist.remove( "d" ) == true );
    REQUIRE( stringlist.remove( "e" ) == true );
    REQUIRE( stringlist.remove( "y" ) == false );

    SECTION( "PRINT COMPARE" )
    {
        stringlist.print( stringsout );
        REQUIRE( stringsout.str( ) == "" );
    }
}
