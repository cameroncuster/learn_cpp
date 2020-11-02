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
    string word;

    SECTION( "EMPTY" )
    {
        // dequeue items from an empty list
        REQUIRE( queue1.dequeue( word ) == false );

        // empty print
        queue1.print( sout1 );

        // nullified queue
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }

    // enqueue single item
    CHECK( queue1.enqueue( "a" ) == true );

    SECTION( "SINGLE ITEM DEQUEUE" )
    {
        // dequeue the single item and require word
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "a" );

        // print
        queue1.print( sout1 );

        // nullified queue
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }

    // enqueue multiple items
    REQUIRE( queue1.enqueue( "b" ) == true );
    REQUIRE( queue1.enqueue( "c" ) == true );
    REQUIRE( queue1.enqueue( "d" ) == true );
    REQUIRE( queue1.enqueue( "e" ) == true );
    REQUIRE( queue1.enqueue( "f" ) == true );
    REQUIRE( queue1.enqueue( "g" ) == true );
    REQUIRE( queue1.enqueue( "h" ) == true );
    REQUIRE( queue1.enqueue( "i" ) == true );

    SECTION( "MULTIPLE ITEM DEQUEUE" )
    {
        // dequeue half items and require words
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "a" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "b" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "c" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "d" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "e" );

        // print
        queue1.print( sout1 );

        // dequeue
        CHECK( queue1.size( ) == 4 );
        REQUIRE( sout1.str( ) == "f, g, h, i" );
    }

    SECTION( "MULTIPLE ITEM DEQUEUE NULLIFY" )
    {
        // nullify the queue and require words
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "a" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "b" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "c" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "d" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "e" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "f" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "g" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "h" );
        REQUIRE( queue1.dequeue( word ) == true );
        REQUIRE( word == "i" );

        // print
        queue1.print( sout1 );

        // nullified queue
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }
}

TEST_CASE( "QUEUE::FRONT - GET THE FIRST WORD IN THE QUEUE" )
{
    Queue queue1;
    ostringstream sout1;
    string word;

    SECTION( "EMPTY" )
    {
        // front items from an empty list
        REQUIRE( queue1.front( word ) == false );
        REQUIRE( word == "" );

        // empty print
        queue1.print( sout1 );

        // nullified queue
        CHECK( queue1.size( ) == 0 );
        REQUIRE( sout1.str( ) == "" );
    }

    // enqueue multiple items
    REQUIRE( queue1.enqueue( "a" ) == true );
    REQUIRE( queue1.enqueue( "b" ) == true );
    REQUIRE( queue1.enqueue( "c" ) == true );

    SECTION( "MULTIPLE ITEMS FRONT" )
    {
        // front items from an empty list
        REQUIRE( queue1.front( word ) == true );
        REQUIRE( word == "a" );

        // empty print
        queue1.print( sout1 );

        // nullified queue
        CHECK( queue1.size( ) == 3 );
        REQUIRE( sout1.str( ) == "a, b, c" );
    }
}

TEST_CASE( "QUEUE::COPY_CONSTRUCTOR" )
{
    Queue queue1;
    ostringstream sout1, sout2;

    // copy the queue
    Queue queue2( queue1 );

    // empty print
    printQueue( queue1, sout1 );
    printQueue( queue2, sout2 );

    SECTION( "EMPTY" )
    {
        CHECK( queue1.size( ) == queue2.size( ) );
        REQUIRE( sout1.str( ) == sout2.str( ) );
    }

    // enqueue items in the queue
    REQUIRE( queue1.enqueue( "a" ) == true );

    // copy the queue
    Queue queue3( queue1 );

    // print
    printQueue( queue1, sout1 );
    printQueue( queue3, sout2 );

    SECTION( "SINGLE ITEM ENQUEUES" )
    {
        CHECK( queue1.size( ) == queue3.size( ) );
        REQUIRE( sout1.str( ) == sout2.str( ) );
    }

    // clear the string streams
    sout1.clear( );
    sout2.clear( );

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

    // copy the queue
    Queue queue4( queue1 );

    // print
    printQueue( queue1, sout1 );
    printQueue( queue4, sout2 );

    SECTION( "MULTIPLE ITEM ENQUEUES" )
    {
        CHECK( queue1.size( ) == queue4.size( ) );
        REQUIRE( sout1.str( ) == sout2.str( ) );
    }
}



void printQueue( Queue q, ostream &out )
{
    // write the code to print a queue to the screen destroying the
    // contents of the queue when done. It is pass by value.
    string word;
    while( q.empty( ) == true )
    {
        q.dequeue( word );
        out << word;
        if( q.size( ) != 1 )
        {
            out << ", ";
        }
    }
}