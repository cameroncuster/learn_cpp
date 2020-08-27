#include "..\\catch.hpp"
#include "network.h"

TEST_CASE("compressOctets - testing a class b ip address")
{
    octet octet0 = 151;
    octet octet1 = 159;
    octet octet2 = 15;
    octet octet3 = 20;
    
    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(2543783700 == ipAddress);
}

TEST_CASE("extractOctets - testing a class b ip to octet version1")
{
    ip ipAddress = 2543783700;
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == 151);
    CHECK(octet1 == 159);
    CHECK(octet2 == 15);
    CHECK(octet3 == 20);
}

TEST_CASE("getNetworkType - classifying a class b networks including private") {
    ip ipAddress = compressOctets(151, 159, 15, 20);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSB == classified);

    ipAddress = compressOctets(172, 18, 4, 20);
    classified = getNetworkType(ipAddress);
    CHECK(BPRIVATE == classified);
}