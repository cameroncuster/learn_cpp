#include "sortedSingle.h"
#include "..\\catch.hpp"
using namespace std;

/*
// iterator class tests
TEST_CASE( "ITERATOR" )
{
    sortedSingle<int> list1;
    sortedSingle::iterator it;

    ostringstream sout1;

    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    it = list1.begin( );

    SECTION( "PRE_INCREMENT" )
    {
        while( it != list1.end( ) )
        {
            sout1 << *it;
            ++it;
            if( it != list1.end( ) )
                sout1 << ", ";
        }
        REQUIRE( sout1.str( ) == "10, 20, 30, 40, 50" );
    }

    SECTION( "PRE_INCREMENT" )
    {
        while( it != list1.end( ) )
        {
            sout1 << *it;
            it++;
            if( it != list1.end( ) )
                sout1 << ", ";
        }
        REQUIRE( sout1.str( ) == "10, 20, 30, 40, 50" );
    }

    SECTION( "EQUALITY&!" )
    {
        sortedSingle::iterator it1 = list1.begin( );
        sortedSingle::iterator it2 = list1.begin( );
        sortedSingle::iterator it3 = list1.end( );

        REQUIRE( it1 == it2 );
        REQUIRE( it1 != it3 );
        REQUIRE( it2 != it3 );
    }

    SECTION( "DEREFRENCE" )
    {
        it = list1.begin( );
        *it = 9;

        for( it = list1.begin( ); it != list1.end( ); it++ )
            sout1 << *it << ' ';
        REQUIRE( sout1.str( ) == "9 20 30 40 50 " );
    }

    SECTION( "DEREFRENCE_RETURN_VAL" )
    {
        int n;
        n = *it;
        REQUIRE( n == 10 );
        n = *it++;
        REQUIRE( n == 10 );
    }

    SECTION( "ADDRESS_OF_ITEM" )
    {
        it = list1.begin( );
        ++it;
        it++;

        *it = 35;
        for( it = list1.begin( ); it != list1.end( ); ++it )
            sout1 << *it << ' ';
        REQUIRE( sout1.str( ) == "10 20 35 40 50 " );
    }
}

TEST_CASE( "default constructor" )
{
    sortedSingle list1;

    SECTION( "empty" )
    {
        CHECK( list1.empty( ) == true );
        CHECK( list1.size( ) == 0 );
    }

    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    SECTION( "values" )
    {
        CHECK( list1.empty( ) == false );
        CHECK( list1.size( ) == 5 );
    }

    SECTION( "new section" )
    {
        CHECK( list1.empty( ) == false );
        CHECK( list1.size( ) == 5 );
    }
}

TEST_CASE( "copy constructor" )
{
    sortedSingle list1;
    sortedSingle ecpy;

    ostringstream sout1;
    ostringstream sout1cpy;

    list1.print( sout1 );
    ecpy.print( sout1cpy );

    REQUIRE( sout1.str( ) == sout1cpy.str( ) );
    
    list1.insert( 10 );
    list1.insert( 20 );
    list1.insert( 30 );
    list1.insert( 40 );
    list1.insert( 50 );

    sortedSingle list1cpy( list1 );
    
    list1.print( sout1 );
    list1cpy.print( sout1cpy );

    REQUIRE( sout1.str( ) == sout1cpy.str( ) );

    sout1.clear( );
    sout1cpy.clear( );

    list1.remove( 10 );
    list1.remove( 20 );

    list1.print( sout1 );
    list1cpy.print( sout1cpy );

    REQUIRE( sout1.str( ) != sout1cpy.str( ) );
}

TEST_CASE( "destructor - untestable" )
{
    sortedSingle list1;

    SECTION( "empty list" )
    {
        REQUIRE( list1.empty( ) == true );
        REQUIRE( list1.size( ) == 0 );
    }
}

TEST_CASE( "empty" )
{
    sortedSingle list1;

    SECTION( "empty" )
    {
        REQUIRE( list1.empty( ) == true );
    }

    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );
    
    SECTION( "values" )
    {
        REQUIRE( list1.empty( ) == false );
    }
}

TEST_CASE( "size" )
{
    sortedSingle list1;

    SECTION( "empty" )
    {
        CHECK( list1.empty( ) == true );
        REQUIRE( list1.size( ) == 0 );
    }

    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    SECTION( "size 5" )
    {
        CHECK( list1.empty( ) == false );
        REQUIRE( list1.size( ) == 5 );
    }

    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    SECTION( "size 10 w/duplicates" )
    {
        CHECK( list1.empty( ) == false );
        REQUIRE( list1.size( ) == 10 );
    }

    list1.insert( 10 );
    list1.insert( 30 );
    list1.insert( 20 );
    list1.insert( 50 );
    list1.insert( 40 );

    SECTION( "size 15 w/triplets" )
    {
        CHECK( list1.empty( ) == false );
        REQUIRE( list1.size( ) == 15 );
    }
}

TEST_CASE( "find" )
{
    sortedSingle list1;

    list1.insert( 0 );

    SECTION( "find 0" )
    {
        REQUIRE( list1.find( -1 ) == false );
        REQUIRE( list1.find( 0 ) == true );
        REQUIRE( list1.find( 1 ) == false );
        REQUIRE( list1.find( 2 ) == false );
        REQUIRE( list1.find( 3 ) == false );
        REQUIRE( list1.find( 4 ) == false );
        REQUIRE( list1.find( 5 ) == false );
    }

    list1.insert( 1 );

    SECTION( "find 0, 1" )
    {
        REQUIRE( list1.find( -1 ) == false );
        REQUIRE( list1.find( 0 ) == true );
        REQUIRE( list1.find( 1 ) == true );
        REQUIRE( list1.find( 2 ) == false );
        REQUIRE( list1.find( 3 ) == false );
        REQUIRE( list1.find( 4 ) == false );
        REQUIRE( list1.find( 5 ) == false );
    }

    list1.insert( 2 );

    SECTION( "find 0, 1, 2" )
    {
        REQUIRE( list1.find( -1 ) == false );
        REQUIRE( list1.find( 0 ) == true );
        REQUIRE( list1.find( 1 ) == true );
        REQUIRE( list1.find( 2 ) == true );
        REQUIRE( list1.find( 3 ) == false );
        REQUIRE( list1.find( 4 ) == false );
        REQUIRE( list1.find( 5 ) == false );
    }

    list1.insert( 3 );

    SECTION( "find 0, 1, 2, 3" )
    {
        REQUIRE( list1.find( -1 ) == false );
        REQUIRE( list1.find( 0 ) == true );
        REQUIRE( list1.find( 1 ) == true );
        REQUIRE( list1.find( 2 ) == true );
        REQUIRE( list1.find( 3 ) == true );
        REQUIRE( list1.find( 4 ) == false );
        REQUIRE( list1.find( 5 ) == false );
    }

    list1.insert( 4 );

    SECTION( "find 0, 1, 2, 3, 4" )
    {
        REQUIRE( list1.find( -1 ) == false );
        REQUIRE( list1.find( 0 ) == true );
        REQUIRE( list1.find( 1 ) == true );
        REQUIRE( list1.find( 2 ) == true );
        REQUIRE( list1.find( 3 ) == true );
        REQUIRE( list1.find( 4 ) == true );
        REQUIRE( list1.find( 5 ) == false );
    }

    list1.insert( 5 );

    SECTION( "find 0, 1, 2, 3, 4, 5" )
    {
        REQUIRE( list1.find( -1 ) == false );
        REQUIRE( list1.find( 0 ) == true );
        REQUIRE( list1.find( 1 ) == true );
        REQUIRE( list1.find( 2 ) == true );
        REQUIRE( list1.find( 3 ) == true );
        REQUIRE( list1.find( 4 ) == true );
        REQUIRE( list1.find( 5 ) == true );
    }

    list1.remove( 5 );
    list1.remove( 4 );
    list1.remove( 3 );
    list1.remove( 2 );
    list1.remove( 1 );
    
    SECTION( "find 0 after remove" )
    {
        REQUIRE( list1.find( -1 ) == false );
        REQUIRE( list1.find( 0 ) == true );
        REQUIRE( list1.find( 1 ) == false );
        REQUIRE( list1.find( 2 ) == false );
        REQUIRE( list1.find( 3 ) == false );
        REQUIRE( list1.find( 4 ) == false );
        REQUIRE( list1.find( 5 ) == false );
    }
}

TEST_CASE( "retrievePosition" )
{
    sortedSingle list1;

    list1.insert( 0 );

    SECTION( "retrieve 0" )
    {
        REQUIRE( list1.retrievePosition( -1 ) == 0 );
        REQUIRE( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.retrievePosition( 1 ) == 0 );
        REQUIRE( list1.retrievePosition( 2 ) == 0 );
        REQUIRE( list1.retrievePosition( 3 ) == 0 );
        REQUIRE( list1.retrievePosition( 4 ) == 0 );
        REQUIRE( list1.retrievePosition( 5 ) == 0 );
    }

    list1.insert( 1 );

    SECTION( "retrieve 0, 1" )
    {
        REQUIRE( list1.retrievePosition( -1 ) == 0 );
        REQUIRE( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.retrievePosition( 1 ) == 2 );
        REQUIRE( list1.retrievePosition( 2 ) == 0 );
        REQUIRE( list1.retrievePosition( 3 ) == 0 );
        REQUIRE( list1.retrievePosition( 4 ) == 0 );
        REQUIRE( list1.retrievePosition( 5 ) == 0 );
    }

    list1.insert( 2 );

    SECTION( "retrieve 0, 1, 2" )
    {
        REQUIRE( list1.retrievePosition( -1 ) == 0 );
        REQUIRE( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.retrievePosition( 1 ) == 2 );
        REQUIRE( list1.retrievePosition( 2 ) == 3 );
        REQUIRE( list1.retrievePosition( 3 ) == 0 );
        REQUIRE( list1.retrievePosition( 4 ) == 0 );
        REQUIRE( list1.retrievePosition( 5 ) == 0 );
    }

    list1.insert( 3 );

    SECTION( "retrieve 0, 1, 2, 3" )
    {
        REQUIRE( list1.retrievePosition( -1 ) == 0 );
        REQUIRE( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.retrievePosition( 1 ) == 2 );
        REQUIRE( list1.retrievePosition( 2 ) == 3 );
        REQUIRE( list1.retrievePosition( 3 ) == 4 );
        REQUIRE( list1.retrievePosition( 4 ) == 0 );
        REQUIRE( list1.retrievePosition( 5 ) == 0 );
    }

    list1.insert( 4 );

    SECTION( "retrieve 0, 1, 2, 3, 4" )
    {
        REQUIRE( list1.retrievePosition( -1 ) == 0 );
        REQUIRE( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.retrievePosition( 1 ) == 2 );
        REQUIRE( list1.retrievePosition( 2 ) == 3 );
        REQUIRE( list1.retrievePosition( 3 ) == 4 );
        REQUIRE( list1.retrievePosition( 4 ) == 5 );
        REQUIRE( list1.retrievePosition( 5 ) == 0 );
    }

    list1.insert( 5 );

    SECTION( "retrieve 0, 1, 2, 3, 4, 5" )
    {
        REQUIRE( list1.retrievePosition( -1 ) == 0 );
        REQUIRE( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.retrievePosition( 1 ) == 2 );
        REQUIRE( list1.retrievePosition( 2 ) == 3 );
        REQUIRE( list1.retrievePosition( 3 ) == 4 );
        REQUIRE( list1.retrievePosition( 4 ) == 5 );
        REQUIRE( list1.retrievePosition( 5 ) == 6 );
    }

    list1.remove( 5 );
    list1.remove( 4 );
    list1.remove( 3 );
    list1.remove( 2 );
    list1.remove( 1 );

    SECTION( "retrieve 0 after remove" )
    {
        REQUIRE( list1.retrievePosition( -1 ) == 0 );
        REQUIRE( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.retrievePosition( 1 ) == 0 );
        REQUIRE( list1.retrievePosition( 2 ) == 0 );
        REQUIRE( list1.retrievePosition( 3 ) == 0 );
        REQUIRE( list1.retrievePosition( 4 ) == 0 );
        REQUIRE( list1.retrievePosition( 5 ) == 0 );
    }
}

TEST_CASE( "insert" )
{
    // multiple lists
    sortedSingle list1;
    sortedSingle list2;
    sortedSingle list3;

    // multiple string streams for multiple lists
    ostringstream sout1;
    ostringstream sout2;
    ostringstream sout3;

    // print the lists
    list1.print( sout1 );
    list2.print( sout2 );
    list3.print( sout3 );
    
    SECTION( "empty" )
    {
        // list 1
        REQUIRE( list1.find( 1 ) == false );
        CHECK( list1.retrievePosition( 1 ) == 0 );
        CHECK( list1.empty( ) == true );
        CHECK( list1.size( ) == 0 );
        CHECK( sout1.str( ) == "" );

        // list 2
        REQUIRE( list2.find( 0 ) == false );
        CHECK( list2.retrievePosition( 0 ) == 0 );
        CHECK( list2.empty( ) == true );
        CHECK( list2.size( ) == 0 );
        CHECK( sout2.str( ) == "" );

        // list 3
        REQUIRE( list3.find( -1 ) == false );
        CHECK( list3.retrievePosition( -1 ) == 0 );
        CHECK( list3.empty( ) == true );
        CHECK( list3.size( ) == 0 );
        CHECK( sout3.str( ) == "" );
    }

    // insert to initialize the list
    REQUIRE( list1.insert( 1 ) == true );
    REQUIRE( list2.insert( 0 ) == true );
    REQUIRE( list3.insert( -1 ) == true );

    // clear then print the lists
    sout1.str( "" );
    sout2.str( "" );
    sout3.str( "" );
    list1.print( sout1 );
    list2.print( sout2 );
    list3.print( sout3 );

    SECTION( "into empty list" )
    {
        // list 1
        REQUIRE( list1.find( 1 ) == true );
        REQUIRE( list1.retrievePosition( 1 ) == 1 );
        CHECK( list1.empty( ) == false );
        CHECK( list1.size( ) == 1 );
        CHECK( sout1.str( ) == "1" );

        // list 2
        REQUIRE( list2.find( 0 ) == true );
        REQUIRE( list2.retrievePosition( 0 ) == 1 );
        CHECK( list2.empty( ) == false );
        CHECK( list2.size( ) == 1 );
        CHECK( sout2.str( ) == "0" );

        // list 3
        REQUIRE( list3.find( -1 ) == true );
        REQUIRE( list3.retrievePosition( -1 ) == 1 );
        CHECK( list3.empty( ) == false );
        CHECK( list3.size( ) == 1 );
        CHECK( sout3.str( ) == "-1" );
    }
    
    // insert into each list at end
    REQUIRE( list1.insert( 2 ) == true );
    REQUIRE( list2.insert( 2 ) == true );
    REQUIRE( list3.insert( 2 ) == true );

    // insert into each list at the end
    REQUIRE( list1.insert( -2 ) == true );
    REQUIRE( list2.insert( -2 ) == true );
    REQUIRE( list3.insert( -2 ) == true );

    // clear then print the lists
    sout1.str( "" );
    sout2.str( "" );
    sout3.str( "" );
    list1.print( sout1 );
    list2.print( sout2 );
    list3.print( sout3 );

    SECTION( "into both ends of list" )
    {
        // list 1
        // check -2, and 2
        REQUIRE( list1.find( -2 ) == true );
        REQUIRE( list1.find( 2 ) == true );
        REQUIRE( list1.retrievePosition( -2 ) == 1 );
        REQUIRE( list1.retrievePosition( 2 ) == list1.size( ) );
        CHECK( list1.empty( ) == false );
        CHECK( sout1.str( ) == "-2, 1, 2" );

        // list 2
        // check -2, and 2
        REQUIRE( list2.find( -2 ) == true );
        REQUIRE( list2.find( 2 ) == true );
        REQUIRE( list2.retrievePosition( -2 ) == 1 );
        REQUIRE( list2.retrievePosition( 2 ) == list2.size( ) );
        CHECK( list2.empty( ) == false );
        CHECK( sout2.str( ) == "-2, 0, 2" );

        // list 3
        // check -2, and 2
        REQUIRE( list3.find( -2 ) == true );
        REQUIRE( list3.find( 2 ) == true );
        REQUIRE( list3.retrievePosition( -2 ) == 1 );
        REQUIRE( list3.retrievePosition( 2 ) == list3.size( ) );
        CHECK( list3.empty( ) == false );
        CHECK( sout3.str( ) == "-2, -1, 2" );
    }

    // insert to list 1
    REQUIRE( list1.insert( -3 ) == true );
    REQUIRE( list1.insert( 3 ) == true );

    // insert to list 2
    REQUIRE( list2.insert( -3 ) == true );
    REQUIRE( list2.insert( 3 ) == true );

    // insert to list 3
    REQUIRE( list3.insert( -3 ) == true );
    REQUIRE( list3.insert( 3 ) == true );

    // insert duplicates
        // insert to list 1
    REQUIRE( list1.insert( -3 ) == true );
    REQUIRE( list1.insert( 3 ) == true );

    // insert to list 2
    REQUIRE( list2.insert( -3 ) == true );
    REQUIRE( list2.insert( 3 ) == true );

    // insert to list 3
    REQUIRE( list3.insert( -3 ) == true );
    REQUIRE( list3.insert( 3 ) == true );

    // clear then print the lists
    sout1.str( "" );
    sout2.str( "" );
    sout3.str( "" );
    list1.print( sout1 );
    list2.print( sout2 );
    list3.print( sout3 );

    SECTION( "duplicates" )
    {
        // list 1
        REQUIRE( list1.find( -3 ) == true );
        REQUIRE( list1.find( 3 ) == true );
        REQUIRE( list1.retrievePosition( -3 ) == 1 );
        REQUIRE( list1.retrievePosition( 3 ) == list1.size( ) - 1 );
        CHECK( list1.empty( ) == false );
        CHECK( sout1.str( ) == "-3, -3, -2, 1, 2, 3, 3" );

        // list 2
        REQUIRE( list2.find( -3 ) == true );
        REQUIRE( list2.find( 3 ) == true );
        REQUIRE( list2.retrievePosition( -3 ) == 1 );
        REQUIRE( list2.retrievePosition( 3 ) == list2.size( ) - 1 );
        CHECK( list2.empty( ) == false );
        CHECK( sout2.str( ) == "-3, -3, -2, 0, 2, 3, 3" );

        // list 3
        REQUIRE( list3.find( -3 ) == true );
        REQUIRE( list3.find( 3 ) == true );
        REQUIRE( list3.retrievePosition( -3 ) == 1 );
        REQUIRE( list3.retrievePosition( 3 ) == list3.size( ) - 1 );
        CHECK( list3.empty( ) == false );
        CHECK( sout3.str( ) == "-3, -3, -2, -1, 2, 3, 3" );
    }

    // insert triplets
        // insert to list 1
    REQUIRE( list1.insert( -3 ) == true );
    REQUIRE( list1.insert( 3 ) == true );

    // insert to list 2
    REQUIRE( list2.insert( -3 ) == true );
    REQUIRE( list2.insert( 3 ) == true );

    // insert to list 3
    REQUIRE( list3.insert( -3 ) == true );
    REQUIRE( list3.insert( 3 ) == true );

    // clear then print the lists
    sout1.str( "" );
    sout2.str( "" );
    sout3.str( "" );
    list1.print( sout1 );
    list2.print( sout2 );
    list3.print( sout3 );

    SECTION( "triplets" )
    {
        // list 1
        REQUIRE( list1.find( -3 ) == true );
        REQUIRE( list1.find( 3 ) == true );
        REQUIRE( list1.retrievePosition( -3 ) == 1 );
        REQUIRE( list1.retrievePosition( 3 ) == list1.size( ) - 2 );
        CHECK( list1.empty( ) == false );
        CHECK( sout1.str( ) == "-3, -3, -3, -2, 1, 2, 3, 3, 3" );

        // list 2
        REQUIRE( list2.find( -3 ) == true );
        REQUIRE( list2.find( 3 ) == true );
        REQUIRE( list2.retrievePosition( -3 ) == 1 );
        REQUIRE( list2.retrievePosition( 3 ) == list2.size( ) - 2 );
        CHECK( list2.empty( ) == false );
        CHECK( sout2.str( ) == "-3, -3, -3, -2, 0, 2, 3, 3, 3" );

        // list 3
        REQUIRE( list3.find( -3 ) == true );
        REQUIRE( list3.find( 3 ) == true );
        REQUIRE( list3.retrievePosition( -3 ) == 1 );
        REQUIRE( list3.retrievePosition( 3 ) == list3.size( ) - 2 );
        CHECK( list3.empty( ) == false );
        CHECK( sout3.str( ) == "-3, -3, -3, -2, -1, 2, 3, 3, 3" );
    }
}

TEST_CASE( "print" )
{
    // lists
    sortedSingle list1;

    // string streams
    stringstream sout1;

    SECTION( "empty" )
    {
        list1.print( sout1 );
        REQUIRE( sout1.str( ) == "" );
    }

    CHECK( list1.insert( 0 ) == true );

    SECTION( "values" )
    {
        list1.print( sout1 );
        REQUIRE( sout1.str( ) == "0" );
    }

    CHECK( list1.insert( 1 ) == true );

    SECTION( "values" )
    {
        list1.print( sout1 );
        REQUIRE( sout1.str( ) == "0, 1" );
    }

    CHECK( list1.insert( 2 ) == true );

    SECTION( "values" )
    {
        list1.print( sout1 );
        REQUIRE( sout1.str( ) == "0, 1, 2" );
    }

    CHECK( list1.insert( 3 ) == true );

    SECTION( "values" )
    {
        list1.print( sout1 );
        REQUIRE( sout1.str( ) == "0, 1, 2, 3" );
    }

    CHECK( list1.insert( 4 ) == true );

    SECTION( "values" )
    {
        list1.print( sout1 );
        REQUIRE( sout1.str( ) == "0, 1, 2, 3, 4" );
    }

    CHECK( list1.insert( 5 ) == true );

    SECTION( "values" )
    {
        list1.print( sout1 );
        REQUIRE( sout1.str( ) == "0, 1, 2, 3, 4, 5" );
    }
}

TEST_CASE( "remove" )
{
    sortedSingle list1;
    sortedSingle list2;

    CHECK( list2.insert( 10 ) == true );

    SECTION( "before first value" )
    {
        REQUIRE( list2.remove( 5 ) == false );
    }

    CHECK( list2.insert( 20 ) == true );

    SECTION( "not in list between two items" )
    {
        REQUIRE( list2.remove( 15 ) == false );
    }

    SECTION( "empty" )
    {
        CHECK( list1.empty( ) == true );
        REQUIRE( list1.remove( 0 ) == false );
    }

    CHECK( list1.insert( 0 ) == true );

    SECTION( "remove only value" )
    {
        CHECK( list1.empty( ) == false );
        CHECK( list1.size( ) == 1 );
        CHECK( list1.find( 0 ) == true );
        REQUIRE( list1.remove( 0 ) == true );
        REQUIRE( list1.find( 0 ) == false );
        REQUIRE( list1.empty( ) == true );
        REQUIRE( list1.size( ) == 0 );
    }

    CHECK( list1.insert( 1 ) == true );

    SECTION( "remove first value" )
    {
        CHECK( list1.size( ) == 2 );
        CHECK( list1.find( 0 ) == true );
        CHECK( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.remove( 0 ) == true );
        REQUIRE( list1.retrievePosition( 0 ) == 0 );
        REQUIRE( list1.find( 0 ) == false );
        REQUIRE( list1.size( ) == 1 );
    }

    CHECK( list1.insert( 2 ) == true );

    SECTION( "remove last value" )
    {
        CHECK( list1.size( ) == 3 );
        CHECK( list1.find( 2 ) == true );
        CHECK( list1.retrievePosition( 2 ) == 3 );
        REQUIRE( list1.remove( 2 ) == true );
        REQUIRE( list1.retrievePosition( 2 ) == 0 );
        REQUIRE( list1.find( 2 ) == false );
        REQUIRE( list1.size( ) == 2 );
    }

    CHECK( list1.insert( 0 ) == true );

    SECTION( "remove first instance of duplicated value" )
    {
        CHECK( list1.size( ) == 4 );
        CHECK( list1.find( 0 ) == true );
        CHECK( list1.retrievePosition( 0 ) == 1 );
        REQUIRE( list1.remove( 0 ) == true );
        REQUIRE( list1.size( ) == 3 );
    }

    CHECK( list1.insert( 1 ) == true );

    SECTION( "more duplications" )
    {
        CHECK( list1.size( ) == 5 );
        CHECK( list1.find( 1 ) == true );
        CHECK( list1.retrievePosition( 1 ) == 3 );
        REQUIRE( list1.remove( 1 ) == true );
        REQUIRE( list1.size( ) == 4 );
    }
}

TEST_CASE( "clear" )
{
    sortedSingle list1;
    ostringstream sout1;

    list1.clear( );
    list1.print( sout1 );

    SECTION( "empty" )
    {
        REQUIRE( sout1.str( ) == "" );
    }

    CHECK( list1.insert( 10 ) == true );
    CHECK( list1.insert( 20 ) == true );
    CHECK( list1.insert( 30 ) == true );
    CHECK( list1.insert( 40 ) == true );
    CHECK( list1.insert( 50 ) == true );

    SECTION( "list of values" )
    {
        REQUIRE( sout1.str( ) == "" );
    }
}

TEST_CASE( "remove - should fail" )
{
    sortedSingle list1;
    list1.insert( 20 );
    list1.insert( 30 );
    REQUIRE( list1.remove( 30 ) == true );
    REQUIRE(list1.size( ) == 1);
}
*/