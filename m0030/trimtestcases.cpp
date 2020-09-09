#include "..//catch.hpp"
#include "trim.h"

TEST_CASE("cTrim - Testing C strings with no ws on either end")
{
    char theString[100] = "Catch with Sections!";
    char theAnswer[100] = "Catch with Sections!";
    CHECK(strcmp(theString, theAnswer) == 0);

    SECTION("Front - Just a phrase")
    {
        cTrim(theString[100], FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    SECTION("End - Just a phrase")
    {
        cTrim(theString[100], END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    SECTION("Both - Just a phrase")
    {
        cTrim(theString[100], BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("sTrim - Testing strings with no ws on either end")
{
    string theString = "Catch with Sections!";
    string theAnswer = "Catch with Sections!";
    CHECK(theString == theAnswer);

    SECTION("Front - Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }

    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }

    SECTION("Both - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}

TEST_CASE("cTrim - Testing C strings with whitespace on both ends")
{
    char theString[100] = "  Catch with Sections!  ";
    char theAnswer[100] = "Catch with Sections!  ";
    CHECK(strcmp(theString, theAnswer) == 0);

    SECTION("Front - Just a phrase")
    {
        cTrim(theString[100], FRONT);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    char theAnswer[100] = "  Catch with Sections!";

    SECTION("End - Just a phrase")
    {
        cTrim(theString[100], END);
        CHECK(strcmp(theAnswer, theString) == 0);
    }

    char theAnswer[100] = "Catch with Sections!";

    SECTION("Both - Just a phrase")
    {
        cTrim(theString[100], BOTH);
        CHECK(strcmp(theAnswer, theString) == 0);
    }
}

TEST_CASE("sTrim - Testing strings with whitespace on both ends")
{
    string theString = "  Catch with Sections!  ";
    string theAnswer = "Catch with Sections!  ";
    CHECK(theString == theAnswer);

    SECTION("Front - Just a phrase")
    {
        sTrim(theString, FRONT);
        CHECK(theAnswer == theString);
    }

    string theAnswer = "  Catch with Sections!";

    SECTION("End - Just a phrase")
    {
        sTrim(theString, END);
        CHECK(theAnswer == theString);
    }

    string theAnswer = "Catch with Sections!";

    SECTION("Both - Just a phrase")
    {
        sTrim(theString, BOTH);
        CHECK(theAnswer == theString);
    }
}