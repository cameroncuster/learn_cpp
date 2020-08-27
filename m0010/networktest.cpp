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

TEST_CASE("compressOctets - testing CLASSC ip address")
{
    // Test case #3 - CLASSC
    octet octet0 = 222;
    octet octet1 = 255;
    octet octet2 = 255;
    octet octet3 = 255;

    ip ipAddress = compressOctets(octet0, octet1, octet2, octet3);
    CHECK(3741319167 == ipAddress);
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

TEST_CASE("extractOctets - testing CLASSA ip to octet")
{
    // Test case #1 - CLASSA
    ip ipAddress = compressOctets(126, 255, 255, 255);
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == 126);
    CHECK(octet1 == 255);
    CHECK(octet2 == 255);
    CHECK(octet3 == 255);
}

TEST_CASE("extractOctets - testing CLASSB ip to octet")
{
    // Test case #2 - CLASSB
    ip ipAddress = compressOctets(190, 255, 255, 255);
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == 190);
    CHECK(octet1 == 255);
    CHECK(octet2 == 255);
    CHECK(octet3 == 255);
}

TEST_CASE("extractOctets - testing CLASSC ip to octet")
{
    // Test case #3 - CLASSC
    ip ipAddress = compressOctets(222, 255, 255, 255);
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == 222);
    CHECK(octet1 == 255);
    CHECK(octet2 == 255);
    CHECK(octet3 == 255);
}

TEST_CASE("extractOctets - testing CLASSD ip to octet")
{
    // Test case #4 - CLASSD
    ip ipAddress = compressOctets(239, 255, 255, 255);
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == 239);
    CHECK(octet1 == 255);
    CHECK(octet2 == 255);
    CHECK(octet3 == 255);
}

TEST_CASE("extractOctets - testing CLASSE ip to octet")
{
    // Test case #5 - CLASSE
    ip ipAddress = compressOctets(255, 255, 255, 255);
    octet octet0 = 0;
    octet octet1 = 0;
    octet octet2 = 0;
    octet octet3 = 0;

    extractOctets(ipAddress, octet0, octet1, octet2, octet3);
    CHECK(octet0 == 255);
    CHECK(octet1 == 255);
    CHECK(octet2 == 255);
    CHECK(octet3 == 255);
}

TEST_CASE("getNetworkType - classifying example networks including private") {
    ip ipAddress = compressOctets(151, 159, 15, 20);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSB == classified);

    ipAddress = compressOctets(172, 18, 4, 20);
    classified = getNetworkType(ipAddress);
    CHECK(BPRIVATE == classified);

    //Add two tests from each class not including the example
}

TEST_CASE("getNetworkType - classifying CLASSA and APRIVATE networks") {
    ip ipAddress = compressOctets(126, 255, 255, 255);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSA == classified);

    ipAddress = compressOctets(10, 0, 0, 0);
    classified = getNetworkType(ipAddress);
    CHECK(APRIVATE == classified);
}

TEST_CASE("getNetworkType - classifying CLASSB and BPRIVATE networks") {
    ip ipAddress = compressOctets(128, 0, 0, 0);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSB == classified);

    ipAddress = compressOctets(172, 16, 255, 255);
    classified = getNetworkType(ipAddress);
    CHECK(BPRIVATE == classified);
}

TEST_CASE("getNetworkType - classifying CLASSC and CPRIVATE networks") {
    ip ipAddress = compressOctets(192, 255, 255, 255);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSC == classified);

    ipAddress = compressOctets(192, 168, 0, 0);
    classified = getNetworkType(ipAddress);
    CHECK(CPRIVATE == classified);
}

TEST_CASE("getNetworkType - classifying CLASSD and INVALID networks") {
    ip ipAddress = compressOctets(224, 0, 0, 0);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSD == classified);

    ipAddress = compressOctets(0, 255, 255, 255);
    classified = getNetworkType(ipAddress);
    CHECK(INVALID == classified);
}

TEST_CASE("getNetworkType - classifying CLASSE and LOCALHOST networks") {
    ip ipAddress = compressOctets(255, 255, 255, 255);
    networkType classified = getNetworkType(ipAddress);
    CHECK(CLASSE == classified);

    ipAddress = compressOctets(127, 0, 0, 0);
    classified = getNetworkType(ipAddress);
    CHECK(LOCALHOST == classified);
}