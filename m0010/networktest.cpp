#include "..\\catch.hpp"
#include "network.h"

TEST_CASE("compressOctets - testing a class b ip address");
{
    octet octet0 = 151;
    octet octet1 = 159;
    octet octet2 = 15;
    octet octet3 = 20;
    
    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(2543783700 == ipAddress);
}