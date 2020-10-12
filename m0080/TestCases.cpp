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