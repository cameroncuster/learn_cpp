#include "..\\catch.hpp"
#include "network.h"

TEST_CASE("compressOctets - testing example ip address")
{
    // Example test case
    octet octet0 = 151;
    octet octet1 = 159;
    octet octet2 = 15;
    octet octet3 = 20;
    
    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(2543783700 == ipAddress);
}

TEST_CASE("compressOctets - testing CLASSA ip address")
{
    // Test case #1 - CLASSA
    octet octet0 = 126;
    octet octet1 = 255;
    octet octet2 = 255;
    octet octet3 = 255;

    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(2130706431 == ipAddress);
}

TEST_CASE("compressOctets - testing CLASSB ip address")
{
    // Test case #2 - CLASSB
    octet octet0 = 190;
    octet octet1 = 255;
    octet octet2 = 255;
    octet octet3 = 255;

    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(3204448255 == ipAddress);
}
/
TEST_CASE("compressOctets - testing CLASSC ip address")
{
    // Test case #3 - CLASSC
    octet octet0 = 222;
    octet octet1 = 255;
    octet octet2 = 255;
    octet octet3 = 255;

    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(3741319467 == ipAddress);
}

TEST_CASE("compressOctets - testing CLASSD ip address")
{
    // Test case #4 - CLASSD
    octet octet0 = 239;
    octet octet1 = 255;
    octet octet2 = 255;
    octet octet3 = 255;

    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(4026531839 == ipAddress);
}

TEST_CASE("compressOctets - testing CLASSE ip address")
{
    // Test case #5 - CLASSE
    octet octet0 = 255;
    octet octet1 = 255;
    octet octet2 = 255;
    octet octet3 = 255;

    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(4294967295 == ipAddress);
}

TEST_CASE("extractOctets - testing example ip to octet")
{
    // Example test case
    ip ipAddress = compressOctets(151, 159, 15, 20);
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
/*
TEST_CASE("extractOctets - testing a class_ ip to octet")
{
    // Test case #1 - CLASSA
    ip ipAddress = compressOctets();
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == );
    CHECK(octet1 == );
    CHECK(octet2 == );
    CHECK(octet3 == );
}

TEST_CASE("extractOctets - testing a class_ ip to octet")
{
    // Test case #2 - CLASSB
    ip ipAddress = compressOctets();
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == );
    CHECK(octet1 == );
    CHECK(octet2 == );
    CHECK(octet3 == );
}

TEST_CASE("extractOctets - testing a class_ ip to octet")
{
    // Test case #3 - CLASSC
    ip ipAddress = compressOctets();
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == );
    CHECK(octet1 == );
    CHECK(octet2 == );
    CHECK(octet3 == );
}

TEST_CASE("extractOctets - testing a class_ ip to octet")
{
    // Test case #4 - CLASSD
    ip ipAddress = compressOctets();
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == );
    CHECK(octet1 == );
    CHECK(octet2 == );
    CHECK(octet3 == );
}

TEST_CASE("extractOctets - testing a class_ ip to octet")
{
    // Test case #5 - CLASSE
    ip ipAddress = compressOctets();
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == );
    CHECK(octet1 == );
    CHECK(octet2 == );
    CHECK(octet3 == );
}
*/
TEST_CASE("getNetworkType - classifying a class_ networks including private") {
    ip ipAddress = compressOctets(151, 159, 15, 20);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSB == classified);

    ipAddress = compressOctets(172, 18, 4, 20);
    classified = getNetworkType(ipAddress);
    CHECK(BPRIVATE == classified);

    //Add two tests from each class not including the example
}