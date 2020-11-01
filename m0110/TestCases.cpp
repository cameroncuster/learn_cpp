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
TEST_CASE( "QUEUE::ENQUEUE - inserting into a queue" )
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

    // insert items in the queue
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

    SECTION( "MANY ITEMS" )
    {
        CHECK( queue1.size( ) == 10 );
        REQUIRE( sout1.str( ) == "a, b, c, d, e, f, g, h, i, j" );
    }
}





void printQueue( Queue q, ostream &out )
{
    // write the code to print a queue to the screen destroying the
    // contents of the queue when done. It is pass by value.
    


}

