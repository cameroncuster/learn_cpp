/** ***************************************************************************
 * @file    
 *
 * @brief   Where a students test cases will be written for the enqueue,
 *          dequeue, front and copy constructor member functions.
 *       
 *****************************************************************************/
#include "..\catch.hpp"
#include <sstream>
#include "myQueue.h"

using namespace std;

void printQueue( Queue q, ostream &out );

//write your test cases here
TEST_CASE( "QUEUE::ENQUEUE - INSERTING INTO A QUEUE" )
{
    Queue queue1;
    ostringstream sout1;

    // empty print
    queue1.print( sout1 );

    SECTION( "EMPTY" )
    {
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }

    // enqueue items in the queue
    REQUIRE( queue1.enqueue( "a" ) == true );
    REQUIRE( queue1.enqueue( "b" ) == true );
    REQUIRE( queue1.enqueue( "c" ) == true );
    REQUIRE( queue1.enqueue( "d" ) == true );
    REQUIRE( queue1.enqueue( "e" ) == true );
    REQUIRE( queue1.enqueue( "f" ) == true );
    REQUIRE( queue1.enqueue( "g" ) == true );
    REQUIRE( queue1.enqueue( "h" ) == true );
    REQUIRE( queue1.enqueue( "i" ) == true );
    REQUIRE( queue1.enqueue( "j" ) == true );
    
    // print
    queue1.print( sout1 );

    SECTION( "MULTIPLE ITEM ENQUEUE" )
    {
        CHECK( queue1.size( ) == 10 );
        REQUIRE( sout1.str( ) == "a, b, c, d, e, f, g, h, i, j" );
    }
}

TEST_CASE( "QUEUE::DEQUEUE - REMOVING FROM A QUEUE" )
{
    Queue queue1;
    ostringstream sout1;

    // words
    string word1 = "a";
    string word2 = "b";
    string word3 = "c";
    string word4 = "d";
    string word5 = "e";
    string word6 = "f";
    string word7 = "g";
    string word8 = "h";
    string word9 = "i";

    // empty print
    queue1.print( sout1 );

    SECTION( "EMPTY" )
    {
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }

    // enqueue single item
    CHECK( queue1.enqueue( word1 ) == true );

    // dequeue the single item
    REQUIRE( queue1.dequeue( word1 ) == true );

    // print
    queue1.print( sout1 );

    SECTION( "SINGLE ITEM DEQUEUE" )
    {
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }

    // enqueue multiple items
    CHECK( queue1.enqueue( word1 ) == true );
    CHECK( queue1.enqueue( word2 ) == true );
    CHECK( queue1.enqueue( word3 ) == true );
    CHECK( queue1.enqueue( word4 ) == true );
    CHECK( queue1.enqueue( word5 ) == true );
    CHECK( queue1.enqueue( word6 ) == true );
    CHECK( queue1.enqueue( word7 ) == true );
    CHECK( queue1.enqueue( word8 ) == true );
    CHECK( queue1.enqueue( word9 ) == true );

    // dequeue half items
    REQUIRE( queue1.dequeue( word1 ) == true );
    REQUIRE( queue1.dequeue( word2 ) == true );
    REQUIRE( queue1.dequeue( word3 ) == true );
    REQUIRE( queue1.dequeue( word4 ) == true );
    REQUIRE( queue1.dequeue( word5 ) == true );

    // print
    queue1.print( sout1 );

    SECTION( "MULTIPLE ITEM DEQUEUE" )
    {
        CHECK( queue1.size( ) == 4 );
        REQUIRE( sout1.str( ) == "f, g, h, i" );
    }

    // dequeue the remaining items
    REQUIRE( queue1.dequeue( word6 ) == true );
    REQUIRE( queue1.dequeue( word7 ) == true );
    REQUIRE( queue1.dequeue( word8 ) == true );
    REQUIRE( queue1.dequeue( word9 ) == true );

    // print
    queue1.print( sout1 );

    SECTION( "MULTIPLE ITEM DEQUEUE NULLIFY" )
    {
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }
}




void printQueue( Queue q, ostream &out )
{
    // write the code to print a queue to the screen destroying the
    // contents of the queue when done. It is pass by value.
    


}

